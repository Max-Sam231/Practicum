clear: 
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

#--- linear allocator

linear_allocator.o: linear_allocator.h linear_allocator.c
	gcc -g -c linear_allocator.c -o linear_allocator.o -lm

linear_allocator.a: linear_allocator.o
	ar rc linear_allocator.a linear_allocator.o -lm

linear_allocator_test.o: tests/linear_allocator_test.c
	gcc -g -c tests/linear_allocator_test.c -o linear_allocator_test.o -lm

linear_allocator_test: linear_allocator_test.o linear_allocator.a
	gcc -g -static -o linear_allocator_test linear_allocator_test.o linear_allocator.a -lm


linear_allocator_testing: linear_allocator_test
	./linear_allocator_test

#--- pull allocator

pool_allocator.o: pool_allocator.h pool_allocator.c
	gcc -g -c pool_allocator.c -o pool_allocator.o -lm

pool_allocator.a: pool_allocator.o
	ar rc pool_allocator.a pool_allocator.o -lm

pool_allocator_test.o: tests/pool_allocator_test.c
	gcc -g -c tests/pool_allocator_test.c -o pool_allocator_test.o -lm

pool_allocator_test: pool_allocator_test.o pool_allocator.a
	gcc -g -static -o pool_allocator_test pool_allocator_test.o pool_allocator.a -lm


pool_allocator_testing: pool_allocator_test
	./pool_allocator_test

#--- array list

array_list.o: array_list.h array_list.c linear_allocator.h
	gcc -g -c array_list.c -o array_list.o

array_list.a: array_list.o
	ar rc array_list.a array_list.o

array_list_test.o: tests/array_list_test.c array_list.h linear_allocator.h
	gcc -g -c tests/array_list_test.c -o array_list_test.o

array_list_test: array_list_test.o array_list.a linear_allocator.a
	gcc -g -static -o array_list_test array_list_test.o array_list.a linear_allocator.a -lm

array_list_testing: array_list_test
	./array_list_test

#--- hash table

hash_table.o: hash_table.h hash_table.c pool_allocator.h
	gcc -g -c hash_table.c -o hash_table.o

hash_table.a: hash_table.o
	ar rc hash_table.a hash_table.o

hash_table_test.o: tests/hash_table_test.c pool_allocator.h
	gcc -g -c tests/hash_table_test.c -o hash_table_test.o

hash_table_test: hash_table_test.o hash_table.a pool_allocator.a
	gcc -g -static -o hash_table_test hash_table_test.o hash_table.a pool_allocator.a -lm


hash_table_testing: hash_table_test
	./hash_table_test

run_tests: linear_allocator_testing pool_allocator_testing array_list_testing hash_table_testing
	./linear_allocator_test
	./pool_allocator_test
	./array_list_test
	./hash_table_test
