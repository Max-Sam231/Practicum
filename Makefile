SRC_DIR = data_structures memory utils
TEST_DIR = tests
TEST_SRCS = $(wildcard $(TEST_DIR)/*_test.c)
PRGS = $(patsubst %.c, %, $(notdir $(TEST_SRCS)))

SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
HDRS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.h))

all: $(PRGS) run_tests

run_tests: $(PRGS)
	@for test in $(PRGS); do \
        echo "Running: $$test"; \
        ./$$test || exit 1; \
    done

memory_test: $(PRGS)
	@for test in $(PRGS); do \
        echo "Memory check: $$test"; \
        valgrind --leak-check=full ./$$test || exit 1; \
    done

clear:
	rm -rf *.o *.a $(PRGS) $(OBJS)

check_fmt:
	clang-format -style=LLVM -i `find . -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

%.o: %.c 
	gcc -g -c $< -o $@ -I. -lm

OBJS = $(SRCS:.c=.o)

%_test.o: tests/%_test.c
	gcc -g -c $^ -o $@ -I. -lm

%_test: %_test.o $(OBJS)
	gcc -g -static -o $@ $^ -lm
