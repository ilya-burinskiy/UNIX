fork: fork.o sorts.o
	gcc fork.o sorts.o -o fork
fork.o: fork.c
	gcc -c -g fork.c
sorts.o: sorts.c
	gcc -c -g sorts.c
clean:
	rm *.o
