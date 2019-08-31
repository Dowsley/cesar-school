#include <stdio.h>

int lexico()
{
	char str1[] = {"oi"};
	char str2[] = {"ola"};
	char alfa[] = "abcdefghijklmnopqrstuvwxyz";

	int i = 0;

	while (str1[i] != "\0" || str2[i] != "\0")
	{
		for (int c = 0; c < 26; ++c)
		{

			if (alfa[c] == str1[i] && alfa[c] != str2[i])
			{
				return -1;
			}

			else
			{
				return 1;
			}
		}
		++i;
	}

	return 0;

}


int main()
{
	printf("%d\n", lexico());
}