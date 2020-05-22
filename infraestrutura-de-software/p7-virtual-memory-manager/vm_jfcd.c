#include <stdio.h>
#include <stdlib.h>

void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--) {
        for (j=7;j>=0;j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
	int mask = 0xFFFF; /* Bitmask to turn off the first 16 digits */
	int p;

	FILE *fp = fopen("BACKING_STORE.bin","rb");
	
	for (int i = 0; i < 5; i++) {
		fread(&p, sizeof(int), 1, fp);
		printf("normal %d: ", i);
		print_bits(sizeof(p), &p);
		p = p & mask;
		printf("mask %d: ", i);
		print_bits(sizeof(p), &p);
	}
	
	fclose(fp);
	return 0;
}
