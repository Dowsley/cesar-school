all: serial_group4 pthreads_group4 omp_group4

exec:
	./serial_group4.out arquivo1.txt arquivo2.txt result.txt
	./pthreads_group4.out arquivo1.txt arquivo2.txt result.txt
	./omp_group4.out arquivo1.txt arquivo2.txt result.txt

serial_group4: serial_group4.c 
	gcc serial_group4.c -o serial_group4.out
	
pthreads_group4: pthreads_group4.c
	gcc pthreads_group4.c -lpthread -o pthreads_group4.out
	
omp_group4: omp_group4.c
	gcc omp_group4.c -o omp_group4.out

clean: 
	rm serial_group4.out 
	rm pthreads_group4.out 
	rm omp_group4.out
	rm compare.txt