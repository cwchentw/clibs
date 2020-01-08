ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname -s 2>/dev/null || echo not')
endif

ifneq (,$(findstring $(CC),cl.exe))
	RM=del /q /f
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
	TEST_INTEGER_EXEC=test_integer.exe
	TEST_IO_EXEC=test_cio.exe
	TEST_MATH_EXEC=test_cmath.exe
	TEST_STRING_EXEC=test_cstring.exe
	TEST_TERM_COLOR_EXEC=
	TEST_TIME_EXEC=test_ctime.exe
else
	TEST_BOOLEAN_EXEC=test_boolean
	TEST_INTEGER_EXEC=test_integer
	TEST_IO_EXEC=test_cio
	TEST_MATH_EXEC=test_cmath
	TEST_STRING_EXEC=test_cstring
	TEST_TERM_COLOR_EXEC=test_term_color
	TEST_TIME_EXEC=test_ctime
endif

ifneq (,$(findstring $(CC),cl.exe))
	TEST_BOOLEAN_OBJ=test_boolean.obj
	TEST_INTEGER_OBJ=test_integer.obj
	TEST_IO_OBJ=cio.obj test_cio.obj
	TEST_MATH_OBJ=test_cmath.obj
	TEST_STRING_OBJ=cstring.obj test_cstring.obj
	TEST_TERM_COLOR_OBJ=test_term_color.obj
	TEST_TIME_OBJ=clibs_time.obj test_ctime.obj
else
	TEST_BOOLEAN_OBJ=test_boolean.o
	TEST_INTEGER_OBJ=test_integer.o
	TEST_IO_OBJ=cio.o test_cio.o
	TEST_MATH_OBJ=test_cmath.o
	TEST_STRING_OBJ=cstring.o test_cstring.o
	TEST_TERM_COLOR_OBJ=test_term_color.o
	TEST_TIME_OBJ=clibs_time.o test_ctime.o
endif

TEST_EXEC=$(TEST_BOOLEAN_EXEC) $(TEST_INTEGER_EXEC) $(TEST_IO_EXEC) \
	$(TEST_MATH_EXEC) $(TEST_STRING_EXEC) $(TEST_TERM_COLOR_EXEC) \
	$(TEST_TIME_EXEC)

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
	.\$(TEST_INTEGER_EXEC)
	.\$(TEST_IO_EXEC)
	.\$(TEST_MATH_EXEC)
	.\$(TEST_STRING_EXEC)
	echo "Skip term color testing"
	.\$(TEST_TIME_EXEC)
else
	./$(TEST_BOOLEAN_EXEC)
	./$(TEST_INTEGER_EXEC)
	./$(TEST_IO_EXEC)
	./$(TEST_MATH_EXEC)
	./$(TEST_STRING_EXEC)
	./$(TEST_TERM_COLOR_EXEC)
	./$(TEST_TIME_EXEC)
endif

$(TEST_BOOLEAN_EXEC): $(TEST_BOOLEAN_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_BOOLEAN_EXEC) $(TEST_BOOLEAN_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_INTEGER_EXEC): $(TEST_INTEGER_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_INTEGER_EXEC) $(TEST_INTEGER_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_INTEGER_EXEC) $(TEST_INTEGER_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_IO_EXEC): $(TEST_IO_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_IO_EXEC) $(TEST_IO_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_IO_EXEC) $(TEST_IO_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_MATH_EXEC): $(TEST_MATH_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_MATH_EXEC) $(TEST_MATH_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_MATH_EXEC) $(TEST_MATH_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_STRING_EXEC): $(TEST_STRING_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_STRING_EXEC) $(TEST_STRING_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_STRING_EXEC) $(TEST_STRING_OBJ) $(CFLAGS)
endif  # cl.exe

$(TEST_TERM_COLOR_EXEC): $(TEST_TERM_COLOR_OBJ)
ifeq ($(detected_OS),Windows)
	echo "Not supported"
else
	$(CC) -o $(TEST_TERM_COLOR_EXEC) $(TEST_TERM_COLOR_OBJ) $(CFLAGS)
endif  # Windows

$(TEST_TIME_EXEC): $(TEST_TIME_OBJ)
ifneq (,$(findstring $(CC),cl.exe))
	$(CC) /Fe: $(TEST_TIME_EXEC) $(TEST_TIME_OBJ) $(CFLAGS)
else
	$(CC) -o $(TEST_TIME_EXEC) $(TEST_TIME_OBJ) $(CFLAGS)
endif

test_integer.o:
ifeq ($(CSTD),c89)
	$(CC) -std=c89 -o get_sizeof_data_type get_sizeof_data_type.c
	./get_sizeof_data_type
endif  # c89
	$(CC) -c test_integer.c $(CFLAGS)

%.obj: %.c
	$(CC) /c $< $(CFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	$(RM) $(TEST_EXEC) $(TEST_BOOLEAN_OBJ) $(TEST_INTEGER_OBJ) \
		$(TEST_IO_OBJ) $(TEST_MATH_OBJ) $(TEST_STRING_OBJ) \
		$(TEST_TERM_COLOR_OBJ) $(TEST_TIME_OBJ) \
		get_sizeof_data_type get_sizeof_data_type.exe _sizeof_data_type.h
