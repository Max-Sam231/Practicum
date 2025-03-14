clear: 
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

#--- quadratic equation

quadratic_equation.o: quadratic_equation.h quadratic_equation.c
	gcc -g -c quadratic_equation.c -o quadratic_equation.o -lm

quadratic_equation.a: quadratic_equation.o
	ar rc quadratic_equation.a quadratic_equation.o -lm

quadratic_equation_test.o: tests/quadratic_equation_test.c
	gcc -g -c tests/quadratic_equation_test.c -o quadratic_equation_test.o -lm

quadratic_equation_test: quadratic_equation_test.o quadratic_equation.a
	gcc -g -static -o quadratic_equation_test quadratic_equation_test.o quadratic_equation.a -lm


quadratic_test: quadratic_equation_test
	./quadratic_equation_test

#--- integral

integral.o: integral.h integral.c
	gcc -g -c integral.c -o integral.o -lm

integral.a: integral.o
	ar rc integral.a integral.o -lm

integral_test.o: tests/integral_test.c
	gcc -g -c tests/integral_test.c -o integral_test.o -lm

integral_test: integral_test.o integral.a
	gcc -g -static -o integral_test integral_test.o integral.a -lm


integral_testing: integral_test
	./integral_test

#--- list

list.o: list.h list.c
	gcc -g -c list.c -o list.o

list.a: list.o
	ar rc list.a list.o

list_test.o: tests/list_test.c
	gcc -g -c tests/list_test.c -o list_test.o

list_test: list_test.o list.a
	gcc -g -static -o list_test list_test.o list.a


list_testing: list_test
	./list_test

#--- stack

stack.o: stack.h stack.c
	gcc -g -c stack.c -o stack.o

stack.a: stack.o
	ar rc stack.a stack.o

stack_test.o: tests/stack_test.c
	gcc -g -c tests/stack_test.c -o stack_test.o

stack_test: stack_test.o stack.a
	gcc -g -static -o stack_test stack_test.o stack.a


stack_testing: stack_test
	./stack_test

run_tests: quadratic_test integral_testing list_testing stack_testing
	./quadratic_equation_test
	./integral_test
	./list_test
	./stack_test