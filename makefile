CC = gcc
fib: fib.o main_fib.o timing.o bmp.o
	$(CC) -g -o fib fib.c main_fib.c timing.c bmp.c
run: fib
	./fib 7 25 25 25 200 200 fib7.bmp
	./fib 9 25 25 25 200 400 fib9.bmp
	./fib 25 5 5 5 5000 5000 fib25.bmp
	./fib 26 5 5 5 5000 7000 fib26.bmp
clean :
	@rm -rf fib *.o *.bmp *.jpg 