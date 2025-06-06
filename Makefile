SRC_DIR = data_structures memory
TEST_DIR = tests

SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
HDRS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.h))

memory_test: $(PRGS)
	@for test in $(PRGS); do \
        valgrind --leak-check=full ./$$test || exit 1; \
    done;

test: $(PRGS)
	for test in $(PRGS); do \
        ./$$test || exit 1; \
    done

clear: 
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find . -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

%.o: %.h %.c
	gcc -g -c $< -o $@

%.a: %.o
	ar rc $@ $^

%_test.o: %_test.c
	gcc -g -c $^ -o $@

%_test: %_test.o %.a
	gcc -g -static -o $@ $^ -lm
