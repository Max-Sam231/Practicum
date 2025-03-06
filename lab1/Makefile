clear: 
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

#--- uravnenie

urav.o: urav.h urav.c
	gcc -g -c urav.c -o urav.o

urav.a: urav.o
	ar rc urav.a urav.o

urav_test.o: tests/urav_test.c
	gcc -g -c tests/urav_test.c -o urav_test.o

urav_test: urav_test.o urav.a
	gcc -g -static -o urav_test urav_test.o urav.a


test1: urav_test
	./urav_test

#--- integral

intg.o: intg.h intg.c
	gcc -g -c intg.c -o intg.o

intg.a: intg.o
	ar rc intg.a intg.o

intg_test.o: tests/intg_test.c
	gcc -g -c tests/intg_test.c -o intg_test.o

intg_test: intg_test.o intg.a
	gcc -g -static -o intg_test intg_test.o intg.a


test2: intg_test
	./intg_test

#--- spisok

spsk.o: spsk.h spsk.c
	gcc -g -c spsk.c -o spsk.o

spsk.a: spsk.o
	ar rc spsk.a spsk.o

spsk_test.o: tests/spsk_test.c
	gcc -g -c tests/spsk_test.c -o spsk_test.o

spsk_test: spsk_test.o spsk.a
	gcc -g -static -o spsk_test spsk_test.o spsk.a


test3: spsk_test
	./spsk_test

#--- stack

stck.o: stck.h stck.c
	gcc -g -c stck.c -o stck.o

stck.a: stck.o
	ar rc stck.a stck.o

stck_test.o: tests/stck_test.c
	gcc -g -c tests/stck_test.c -o stck_test.o

stck_test: stck_test.o stck.a
	gcc -g -static -o stck_test stck_test.o stck.a


test4: stck_test
	./stck_test

run_tests: test1 test2 test3 test4
	./test1
	./test2
	./test3
	./test4