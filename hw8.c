#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double Standard_Deviation(double *arr)
{
	double y = 0, x, up = 0, num = 2;
	for (int i = 0; i < 5; i++)
	{
		y += arr[i];
	}
	y = y / 5;
	for (int i = 0; i < 5; i++)
	{
		x = arr[i] - y;
		x = pow(x, 2);
		up += x;
		arr[i] += 1;
	}
	up = up / 5;
	up = sqrt(up);
	return up;
}

int main(void)
{
	double arr[5];
	double total;
	printf("Enter 5 real numbers: ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%lf", &arr[i]);
	}
	total = Standard_Deviation(arr);
	printf("%.3lf", total);
	return 0;
}