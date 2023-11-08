#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num [5], odd [5], even [5];
	int a = 0, b =0;
	printf("Pleas input five integers: ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		if (num[i] % 2 != 0)
		{
			odd[a] = num[i];
			a++;
		}
		else
		{
			even[b] = num[i];
			b++;
		}
	}
	printf("Odd numbers: ");
	for ( int i = 0; i < a; i++)
	{
		printf("%d ", odd[i]);
	}
	printf("\n");
	printf("Even numbers: ");
	for (int i = 0; i < b; i++)
	{
		printf("%d ", even[i]);
	}
	printf("\n");
	return 0;
}