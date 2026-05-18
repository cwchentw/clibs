/** @file       hash_table.h
 *  @brief      Constant C string hash table.
 *  @author     ByteBard
 *  @copyright  MIT
 * 
 *  @note
 *  This hash table is implemented as a bucket array and has not been tested with large datasets.
 *  Not recommended for high-performance scenarios.
 *
 *  @warning
 *  his hash table uses the simple Djb2 algorithm and is not suitable for security-sensitive contexts.
 */
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/* Custom boolean type. */
#ifndef _WINDOWS_
#ifdef __cplusplus
    #ifndef _BOOL_IS_DEFINED
        typedef bool BOOL;
        #define FALSE  false
        #define TRUE   true
        #define _BOOL_IS_DEFINED
    #endif
#else
    #if __STDC_VERSION__ < 199901L
        #ifndef _BOOL_IS_DEFINED
            typedef char BOOL;
            #define FALSE  0
            #define TRUE   1
            #define _BOOL_IS_DEFINED
        #endif
    #else
        #ifndef _BOOL_IS_DEFINED
            #include <stdbool.h>
            typedef bool BOOL;
            #define FALSE  false
            #define TRUE   true
            #define _BOOL_IS_DEFINED
        #endif
    #endif
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hash_table_t hash_table_t;

hash_table_t * hash_table_new(void);
BOOL hash_table_add(hash_table_t *self, const char *key, const char *value);
const char * hash_table_get(hash_table_t *self, const char *key);
BOOL hash_table_remove(hash_table_t *self, const char *key);
void hash_table_delete(hash_table_t *self);

#ifdef __cplusplus
}
#endif

#endif  /* HASH_TABLE_H */