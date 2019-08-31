#include <stdio.h>

long fact_recusive(int);
long fact_loop(int);

int main() {

		int n;
		long f;

		printf("Enter an integer to find its factorial\n");
		scanf("%d", &n);

		if (n < 0) {
			printf("Factorial of negative integers isn't defined.\n");
		} else {

			f = fact_recusive(n);
			printf("%d! = %ld by recursion\n", n, f);

			f = fact_loop(n);
			printf("%d! = %ld by loop\n", n, f);


		}

		return 0;
}

long fact_recusive(int n) {
		if (n == 0)
			return 1;
		else
			return(n * fact_recusive(n-1));
}

long fact_loop(int n) {

		int c, fact = 1;

		for (c = 1; c <= n; c++)
				fact = fact * c;

		return fact;

}
