#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(void)
{
	double km, mile;
	double m = 1.609;
	printf("Please enter kilometers: ");
	scanf("%lf", &km);
	mile = km / m;
	printf("%.1f km is equal to %.1f miles. \n", km, mile);
	return 0;
}