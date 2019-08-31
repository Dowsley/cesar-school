#include <stdio.h>

// Ponteiro é o endereço da posição de memória:

int main(void)
{
	int a = 10;
	int* add = &a;   // DECLAROU ponteiro "add" vai ter o endereço de memória onde a var "a" está alocada, não significa q tem o msm valor.
	int b = *add;   // Atribuindo a b, o VALOR para qual a variável "add" está apontando.
	add = &b;   // ATRIBUIU o endereço de memória onde "b" está guardado para o add.
	*add = 5;   // Para onde(quem) o add está apontando, atribua o valor 5 --> b passa a ter o valor 5.
	(*add)++;   // Para onde o add esta apontando, (b), incremente o valor. --> b vira 6.


	int x = 42;
	int *pt = &x;
	printf("%d\n", x);
	printf("%d\n", &x);
	printf("%d\n", pt);
	printf("%d\n", &pt);
	printf("%d\n", *pt);


	// -----------  Ponteiro com estruturas  -------------
	struct s
	{
		int i;
		float f;
		int* point_member;
		struct s* next;  // Ponteiro que aponta para estruturas struct do tipo s
	} struct1, struct2;

	int a = 5;   
	int* add = &a;
	struct s* point_s;
	point_s = &struct1;
	(*point_s).i = 10;
	point_s->f = 4.3;   // Mesma coisa que o de cima
	*add = point_s->i;
	struct1.point_member = &a;
	struct1.next = struct2;

	return 0;
}

