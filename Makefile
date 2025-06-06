clear:
	rm -rf *.o *.a *_test integral quadratic_equation list stack

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror


quadratic_equation.o: utils/quadratic_equation.c utils/quadratic_equation.h
	gcc -g -c utils/quadratic_equation.c -o quadratic_equation.o -lm

quadratic_equation.a: quadratic_equation.o
	ar rc quadratic_equation.a quadratic_equation.o -lm

integral.o: utils/integral.c utils/integral.h
	gcc -g -c utils/integral.c -o integral.o -lm

integral.a: integral.o
	ar rc integral.a integral.o -lm

list.o: data_structures/list.c data_structures/list.h
	gcc -g -c data_structures/list.c -o list.o

list.a: list.o
	ar rc list.a list.o

stack.o: data_structures/stack.c data_structures/stack.h
	gcc -g -c data_structures/stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

array_list.o: data_structures/array_list.c data_structures/array_list.h
	gcc -g -c data_structures/array_list.c -o array_list.o -lm

array_list.a: array_list.o
	ar rc array_list.a array_list.o -lm

hash_table.o: data_structures/hash_table.c data_structures/hash_table.h
	gcc -g -c data_structures/hash_table.c -o hash_table.o -lm

hash_table.a: hash_table.o
	ar rc hash_table.a hash_table.o -lm

linear_allocator.o: memory/linear_allocator.c memory/linear_allocator.h
	gcc -g -c memory/linear_allocator.c -o linear_allocator.o -lm

linear_allocator.a: linear_allocator.o
	ar rc linear_allocator.a linear_allocator.o -lm

pool_allocator.o: memory/pool_allocator.c memory/pool_allocator.h
	gcc -g -c memory/pool_allocator.c -o pool_allocator.o -lm

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o -lm

cycled_links.o: garbage_collection/cycled_links.c garbage_collection/cycled_links.h
	gcc -g -c garbage_collection/cycled_links.c -o cycled_links.o -lm

cycled_links.a: cycled_links.o
	ar rc cycled_links.a cycled_links.o -lm

destructor.o: garbage_collection/destructor.c garbage_collection/destructor.h
	gcc -g -c garbage_collection/destructor.c -o destructor.o -lm

destructor.a: destructor.o
	ar rc destructor.a destructor.o -lm

garbage_collector.o: garbage_collection/garbage_collector.c garbage_collection/garbage_collector.h
	gcc -g -c garbage_collection/garbage_collector.c -o garbage_collector.o -lm

garbage_collector.a: garbage_collector.o
	ar rc garbage_collector.a garbage_collector.o -lm



quadratic_equation_test.o: tests/quadratic_equation_test.c utils/quadratic_equation.h
	gcc -g -c tests/quadratic_equation_test.c -o quadratic_equation_test.o -lm

quadratic_equation_test: quadratic_equation_test.o quadratic_equation.a
	gcc -g -static -o quadratic_equation_test quadratic_equation_test.o quadratic_equation.a -lm

integral_test.o: tests/integral_test.c utils/integral.h
	gcc -g -c tests/integral_test.c -o integral_test.o -lm

integral_test: integral_test.o integral.a
	gcc -g -static -o integral_test integral_test.o integral.a -lm

list_test.o: tests/list_test.c data_structures/list.h
	gcc -g -c tests/list_test.c -o list_test.o

list_test: list_test.o list.a
	gcc -g -static -o list_test list_test.o list.a 

stack_test.o: tests/stack_test.c data_structures/stack.h
	gcc -g -c tests/stack_test.c -o stack_test.o

stack_test: stack_test.o stack.a
	gcc -g -static -o stack_test stack_test.o stack.a 

array_list_test.o: tests/array_list_test.c data_structures/array_list.h
	gcc -g -c tests/array_list_test.c -o array_list_test.o -lm

array_list_test: array_list_test.o array_list.a linear_allocator.a
	gcc -g -static -o array_list_test array_list_test.o array_list.a linear_allocator.a -lm

hash_table_test.o: tests/hash_table_test.c data_structures/hash_table.h
	gcc -g -c tests/hash_table_test.c -o hash_table_test.o -lm

hash_table_test: hash_table_test.o hash_table.a pool_allocator.a
	gcc -g -static -o hash_table_test hash_table_test.o hash_table.a pool_allocator.a -lm

linear_allocator_test.o: tests/linear_allocator_test.c memory/linear_allocator.h
	gcc -g -c tests/linear_allocator_test.c -o linear_allocator_test.o -lm

linear_allocator_test: linear_allocator_test.o linear_allocator.a
	gcc -g -static -o linear_allocator_test linear_allocator_test.o linear_allocator.a -lm

pool_allocator_test.o: tests/pool_allocator_test.c memory/pool_allocator.h
	gcc -g -c tests/pool_allocator_test.c -o pool_allocator_test.o -lm

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	gcc -g -static -o pool_allocator_test pool_allocator_test.o pool_allocator.a -lm

cycled_links_test.o: tests/cycled_links_test.c garbage_collection/cycled_links.h
	gcc -g -c tests/cycled_links_test.c -o cycled_links_test.o -lm

cycled_links_test: cycled_links_test.o cycled_links.a
	gcc -g -static -o cycled_links_test cycled_links_test.o cycled_links.a -lm

destructor_test.o: tests/destructor_test.c garbage_collection/destructor.h
	gcc -g -c tests/destructor_test.c -o destructor_test.o -lm

destructor_test: destructor_test.o destructor.a
	gcc -g -static -o destructor_test destructor_test.o destructor.a -lm

garbage_collector_test.o: tests/garbage_collector_test.c garbage_collection/garbage_collector.h
	gcc -g -c tests/garbage_collector_test.c -o garbage_collector_test.o -lm

garbage_collector_test: garbage_collector_test.o garbage_collector.a
	gcc -g -static -o garbage_collector_test garbage_collector_test.o garbage_collector.a -lm


run_tests: quadratic_equation_test integral_test list_test stack_test array_list_test hash_table_test linear_allocator_test pool_allocator_test 
	valgrind --leak-check=full --show-leak-kinds=all ./quadratic_equation_test
	valgrind --leak-check=full --show-leak-kinds=all ./integral_test
	valgrind --leak-check=full --show-leak-kinds=all ./list_test
	valgrind --leak-check=full --show-leak-kinds=all ./stack_test
	valgrind --leak-check=full --show-leak-kinds=all ./array_list_test
	valgrind --leak-check=full --show-leak-kinds=all ./hash_table_test
	valgrind --leak-check=full --show-leak-kinds=all ./linear_allocator_test
	valgrind --leak-check=full --show-leak-kinds=all ./pool_allocator_test




integral: integral.o integral.a
	gcc -g -static -o integral integral.o integral.a -lm
	./integral

quadratic_equation: quadratic_equation.o quadratic_equation.a
	gcc -g -static -o quadratic_equation quadratic_equation.o quadratic_equation.a -lm
	./quadratic_equation

list: list.o list.a
	gcc -g -static -o list list.o list.a
	./list

stack: stack.o stack.a
	gcc -g -static -o stack stack.o stack.a
	./stack

array_list: array_list.o array_list.a
	gcc -g -static -o array_list array_list.o array_list.a -lm
	./array_list

hash_table: hash_table.o hash_table.a
	gcc -g -static -o hash_table hash_table.o hash_table.a -lm
	./hash_table

linear_allocator: linear_allocator.o linear_allocator.a
	gcc -g -static -o linear_allocator linear_allocator.o linear_allocator.a -lm
	./linear_allocator

pool_allocator: pool_allocator.o pool_allocator.a
	gcc -g -static -o pool_allocator pool_allocator.o pool_allocator.a -lm
	./pool_allocator

cycled_links: cycled_links.o cycled_links.a
	gcc -g -static -o cycled_links cycled_links.o cycled_links.a -lm
	./cycled_links

destructor: destructor.o destructor.a
	gcc -g -static -o destructor destructor.o destructor.a -lm
	./destructor

garbage_collector: garbage_collector.o garbage_collector.a
	gcc -g -static -o garbage_collector garbage_collector.o garbage_collector.a -lm
	./garbage_collector