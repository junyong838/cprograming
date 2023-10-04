#include <stdio.h>

int main(void)
{
	int a, b, c;

	for ( a = 0; a < 5; a++)
	{
		for (b = 4; b > a; b--)
		{
			printf(" ");
		}
		for ( c = 0; c <= a*2; c++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}