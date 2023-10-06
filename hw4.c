#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	printf("Plese enter a number: ");
	scanf("%d", &num);

	for (int i = 2; num >= i; i++)
	{
		if (num%i == 0 && num != i)
		{
			printf("it is not a prime number.");
			break;
		}
		else if (num%i == 0 && num == i)
		{
			printf("it is a prime number.");
		}
	}
	return 0;
}
