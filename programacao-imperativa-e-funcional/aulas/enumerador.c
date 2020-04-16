// Associaçao entre identificadores e inteiros

#include <stdio.h>

int main()
{
	enum weather{
		sunny,
		windy,
		cloudy,
		rain
	};

	enum weather weather_outside = rain;
	printf("%d\n", weather_outside);

	return 0;
}