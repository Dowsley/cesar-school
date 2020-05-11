run:
	gcc -o vm -Wall vm_jfcd.c
	./vm addresses.txt

clean:
	rm vm
	rm valgrind-out.txt

debug:
	gcc -o vm -Wall -ggdb3 vm_jfcd.c
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./vm addresses.txt