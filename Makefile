CSTD := $(CSTD)
ifndef $(CSTD)
	CSTD=c89
endif

CFLAGS=-Wall -Wextra -g -std=$(CSTD)

TEST_BOOLEAN_EXEC=test_boolean
TEST_STRING_EXEC=test_cstring

TEST_BOOLEAN_SRC=test_boolean.c
TEST_STRING_SRC=cstring.c test_cstring.c

TEST_EXEC=$(TEST_BOOLEAN_EXEC) $(TEST_STRING_EXEC)


.PHONY: all test clean

all: test
	$(MAKE) test
	$(MAKE) clean
	$(MAKE) test CSTD=c99
	$(MAKE) clean
	$(MAKE) test CSTD=c11
	$(MAKE) clean

test: $(TEST_EXEC)
	./$(TEST_BOOLEAN_EXEC)
	./$(TEST_STRING_EXEC)

$(TEST_BOOLEAN_EXEC):
	$(CC) -o $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_SRC) $(CFLAGS)

$(TEST_STRING_EXEC):
	$(CC) -o $(TEST_STRING_EXEC) $(TEST_STRING_SRC) $(CFLAGS)

clean:
	$(RM) $(TEST_EXEC)
