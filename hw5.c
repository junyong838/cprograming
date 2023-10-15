#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Bit(num)
{
	int num1, num2;
	static int total, i;
	num1 = num / 2;
	num2 = num % 2;
	total += num2 * sq(i);
	if (num == 1)
	{
		return total;
	}
	i++;
	Bit(num1);
}

int sq(i)
{
	int num = 1;
	for (int x = 1; x <= i; x++)
	{
		num *= 10;
	}
	return num;
}

int main(void)
{
	int num, total;
	printf("Please enter a number: ");
	scanf("%d", &num);
	total = Bit(num);
	printf("%d", total);
	return 0;
}