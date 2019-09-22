main: mian.o oper_file.o
main.o: main.c
	gcc -c main.c -o main.o
oper_file.o:
	gcc -c oper_file.c -o oper_file.o

.PHONY:clean
clean:
	-rm -rf *.o
