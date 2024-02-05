runStackWithLL: stackDriver.o stack_ll.o
	gcc -o runStackWithLL stackDriver.o stack_ll.o
	./runStackWithLL

runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray stackDriver.o stack_array.o
	./runStackWithArray

stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c

stack_ll.o: stack_ll.c stack.h
	gcc -c stack_ll.c

clean:
	rm -f *.o runStackWithArray