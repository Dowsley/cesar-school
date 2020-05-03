run:
	gcc -o allocator memory_jfcd.c
	./allocator 1048576

clean:
	rm allocator
	rm valgrind-out.txt

debug:
	gcc -o allocator -ggdb3 memory_jfcd.c
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./allocator 1048576