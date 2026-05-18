#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

typedef struct key_value_pair_t key_value_pair_t;

struct hash_table_t {
    key_value_pair_t **pairs;
    size_t size;
    size_t capacity;
};

struct key_value_pair_t {
    const char *key;
    const char *value;
    key_value_pair_t *next;
};

static unsigned long _hash(const char *string);
static key_value_pair_t * _pair_new(const char *key, const char *value);
static BOOL _hash_table_expand(hash_table_t *self);
static BOOL _rehash(hash_table_t *self, size_t capacity);
static BOOL _shrink(hash_table_t *self);

#define _PRIME_SIZE 14
static const size_t primes[_PRIME_SIZE] = {
    11, 23, 47, 97, 197, 397, 797, 1597,
    3203, 6421, 12853, 25717, 51437, 102877
};

hash_table_t * hash_table_new(void)
{
    hash_table_t *table = (hash_table_t *) malloc(sizeof(hash_table_t));
    if (!table)
        return NULL;

    table->size = 0;
    table->capacity = primes[0];
    table->pairs = (key_value_pair_t **)
        malloc(table->capacity * sizeof(key_value_pair_t *));
    if (!table->pairs) {
        free(table);
        return NULL;
    }

    {
        size_t i;
        for (i = 0; i < table->capacity; i++)
            table->pairs[i] = NULL;
    }

    return table;
}

static unsigned long _hash(const char *string)
{
    unsigned long code = 5381;
    size_t i;

    for (i = 0; string[i] != '\0'; i++)
        code = ((code << 5) + code) + (unsigned char) string[i];

    return code;
}

static key_value_pair_t * _pair_new(const char *key, const char *value)
{
    key_value_pair_t *pair =
        (key_value_pair_t *) malloc(sizeof(key_value_pair_t));
    if (!pair)
        return NULL;

    pair->key = key;
    pair->value = value;
    pair->next = NULL;

    return pair;
}

static BOOL _hash_table_expand(hash_table_t *self)
{
    size_t threshold;
    size_t index = 0;
    size_t capacity;

    if (!self)
        return FALSE;

    threshold = self->capacity * 3 / 4;

    if (self->size + 1 <= threshold)
        return TRUE;

    if (self->capacity >= primes[_PRIME_SIZE - 1])
        return TRUE;

    {
        size_t i;
        for (i = 0; i < _PRIME_SIZE; i++) {
            if (primes[i] > self->capacity) {
                index = i;
                break;
            }
        }
    }

    capacity = primes[index];
    return _rehash(self, capacity);
}

BOOL hash_table_add(hash_table_t *self, const char *key, const char *value)
{
    unsigned long code;
    size_t index;
    key_value_pair_t *q;

    assert(self);
    assert(key && 0 != strcmp("", key));

    if (!self || !key || *key == '\0')
        return FALSE;

    if (!_hash_table_expand(self))
        return FALSE;

    code = _hash(key);
    index = code % self->capacity;

    /* Duplicate key: overwrite existing value. */
    q = self->pairs[index];
    while (q) {
        if (0 == strcmp(q->key, key)) {
            q->value = value;
            return TRUE;
        }
        q = q->next;
    }

    /* Insert at head: simpler and O(1). */
    q = _pair_new(key, value);
    if (!q)
        return FALSE;

    q->next = self->pairs[index];
    self->pairs[index] = q;
    self->size += 1;

    return TRUE;
}

static BOOL _rehash(hash_table_t *self, size_t capacity)
{
    key_value_pair_t **new_pairs;
    size_t old_capacity;
    size_t i;

    if (!self)
        return FALSE;

    new_pairs = (key_value_pair_t **)
        malloc(capacity * sizeof(key_value_pair_t *));
    if (!new_pairs)
        return FALSE;

    for (i = 0; i < capacity; i++)
        new_pairs[i] = NULL;

    old_capacity = self->capacity;

    for (i = 0; i < old_capacity; i++) {
        key_value_pair_t *p = self->pairs[i];

        while (p) {
            key_value_pair_t *next = p->next;
            size_t index = _hash(p->key) % capacity;

            p->next = new_pairs[index];
            new_pairs[index] = p;
            p = next;
        }
    }

    free(self->pairs);
    self->pairs = new_pairs;
    self->capacity = capacity;

    return TRUE;
}

const char * hash_table_get(hash_table_t *self, const char *key)
{
    unsigned long code;
    size_t index;
    key_value_pair_t *q;

    assert(self);
    assert(key && 0 != strcmp("", key));

    if (!self || !key || *key == '\0')
        return NULL;

    code = _hash(key);
    index = code % self->capacity;
    q = self->pairs[index];

    while (q) {
        if (0 == strcmp(q->key, key))
            return q->value;
        q = q->next;
    }

    return NULL;
}

BOOL hash_table_remove(hash_table_t *self, const char *key)
{
    unsigned long code;
    size_t index;
    key_value_pair_t *p = NULL;
    key_value_pair_t *q;

    assert(self);
    assert(key && 0 != strcmp("", key));

    if (!self || !key || *key == '\0')
        return FALSE;

    code = _hash(key);
    index = code % self->capacity;
    q = self->pairs[index];

    while (q) {
        if (0 == strcmp(key, q->key)) {
            if (!p)
                self->pairs[index] = q->next;
            else
                p->next = q->next;

            free(q);
            self->size -= 1;

            if (!_shrink(self))
                return FALSE;

            return TRUE;
        }

        p = q;
        q = q->next;
    }

    return FALSE;
}

static BOOL _shrink(hash_table_t *self)
{
    size_t threshold;
    size_t index = 0;
    size_t capacity;

    if (!self)
        return FALSE;

    threshold = self->capacity / 4;

    if (self->size >= threshold)
        return TRUE;

    if (self->capacity <= primes[0])
        return TRUE;

    {
        size_t i;
        for (i = 1; i < _PRIME_SIZE; i++) {
            if (self->capacity == primes[i]) {
                index = i - 1;
                break;
            }
        }
    }

    capacity = primes[index];

    if (capacity == self->capacity)
        return TRUE;

    return _rehash(self, capacity);
}

void hash_table_delete(hash_table_t *self)
{
    size_t i;

    if (!self)
        return;

    for (i = 0; i < self->capacity; i++) {
        key_value_pair_t *p = NULL;
        key_value_pair_t *q = self->pairs[i];

        while (q) {
            p = q;
            q = q->next;
            free(p);
        }
    }

    free(self->pairs);
    free(self);
}