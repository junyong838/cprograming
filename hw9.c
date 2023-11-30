#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[50];
	int num;
	num = 'A' - 'a';
	fputs("Input> ", stdout);
	fgets(arr, sizeof(arr), stdin);
	arr[strlen(arr) - 1] = 0;

	fputs("Output> ",stdout);
	for (int i = 0; i < strlen(arr); i++)
	{
		if ('a' <= arr[i] && arr[i] <= 'z')
		{
			arr[i] += num;
		}
		else if ('A' <= arr[i] && arr[i] <= 'Z')
		{
			arr[i] -= num;
		}

	}
	fputs(arr, stdout);
	return 0;
}