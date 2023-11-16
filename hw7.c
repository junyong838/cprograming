#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr1[6] = { 1,2,3,4,5,6 };
	int arr2[6] = { 7,8,9,10,11,12 };
	int* point1 = &arr1[0];
	int* point2 = &arr2[0];
	int num;

	for (int i = 0; i <= 5; i++)
	{
		num = *point1;
		*point1 = *point2;
		*point2 = num;
		point1++;
		point2++;
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i <= 5; i++)
	{
		printf("%d ", arr2[i]);
	}
}