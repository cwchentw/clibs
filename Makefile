ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

ifneq (,$(findstring $(CC),cl.exe))
	RM=del
endif

CSTD := $(CSTD)
ifndef $(CSTD)
	CSTD=c89
endif

ifneq (,$(findstring $(CC),cl.exe))
	CFLAGS=/W4 /sdl
else
	CFLAGS=-Wall -Wextra -g -std=$(CSTD)
endif

ifeq ($(detected_OS),Windows)
	TEST_BOOLEAN_EXEC=test_boolean.exe
	TEST_MATH_EXEC=test_cmath.exe
	TEST_STRING_EXEC=test_cstring.exe
else
	TEST_BOOLEAN_EXEC=test_boolean
	TEST_MATH_EXEC=test_cmath
	TEST_STRING_EXEC=test_cstring
endif

ifneq (,$(findstring $(CC),cl.exe))
	TEST_BOOLEAN_OBJ=test_boolean.obj
	TEST_MATH_OBJ=test_cmath.obj
	TEST_STRING_OBJ=cstring.obj test_cstring.obj
else
	TEST_BOOLEAN_OBJ=test_boolean.o
	TEST_MATH_OBJ=test_cmath.o
	TEST_STRING_OBJ=cstring.o test_cstring.o
endif

TEST_EXEC=$(TEST_BOOLEAN_EXEC) $(TEST_MATH_EXEC) $(TEST_STRING_EXEC)

VSDEVCMD="C:\\\\Program\\ Files\\ \\`(x86\\`)\\\\Microsoft\\ Visual\\ Studio\\\\2017\\\\BuildTools\\\\Common7\\\\Tools\\\\VsDevCmd.bat"

.PHONY: all test clean

all: test
ifneq (,$(findstring $(CC),cl.exe))
	$(MAKE) test
	$(MAKE) clean
else
	$(MAKE) test
	$(MAKE) clean
	$(MAKE) test CSTD=c99
	$(MAKE) clean
	$(MAKE) test CSTD=c11
	$(MAKE) clean
endif

test: $(TEST_EXEC)
ifeq ($(detected_OS),Windows)
	.\$(TEST_BOOLEAN_EXEC)
	.\$(TEST_MATH_EXEC)
	.\$(TEST_STRING_EXEC)
else
	./$(TEST_BOOLEAN_EXEC)
	./$(TEST_MATH_EXEC)
	./$(TEST_STRING_EXEC)
endif

$(TEST_BOOLEAN_EXEC): $(TEST_BOOLEAN_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
ifeq ($(TRAVIS_OS_NAME),windows)
	powershell -NoProfile -Command $(VSDEVCMD) && $(CC) /Fe: $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_OBJ) $(CFLAGS)
else
	$(CC) /Fe: $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_OBJ) $(CFLAGS)
endif  # TRAVIS_OS_NAME
else
	$(CC) -o $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_MATH_EXEC): $(TEST_MATH_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
ifeq ($(TRAVIS_OS_NAME),windows)
	powershell -NoProfile -Command $(VSDEVCMD) && $(CC) /Fe: $(TEST_MATH_EXEC) $(TEST_MATH_OBJ) $(CFLAGS)
else
	$(CC) /Fe: $(TEST_MATH_EXEC) $(TEST_MATH_OBJ) $(CFLAGS)
endif  # TRAVIS_OS_NAME
else
	$(CC) -o $(TEST_MATH_EXEC) $(TEST_MATH_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_STRING_EXEC): $(TEST_STRING_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
ifeq ($(TRAVIS_OS_NAME),windows)
	powershell -NoProfile -Command $(VSDEVCMD) && $(CC) /Fe: $(TEST_STRING_EXEC) $(TEST_STRING_OBJ) $(CFLAGS)
else
	$(CC) /Fe: $(TEST_STRING_EXEC) $(TEST_STRING_OBJ) $(CFLAGS)
endif  # TRAVIS_OS_NAME
else
	$(CC) -o $(TEST_STRING_EXEC) $(TEST_STRING_OBJ) $(CFLAGS)
endif  # cl.exe

%.obj: %.c
ifeq ($(TRAVIS_OS_NAME),windows)
	powershell -NoProfile -Command $(VSDEVCMD) && $(CC) /c $< $(CFLAGS)
else
	$(CC) /c $< $(CFLAGS)
endif

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	$(RM) $(TEST_EXEC) $(TEST_BOOLEAN_OBJ) $(TEST_MATH_OBJ) $(TEST_STRING_OBJ)
