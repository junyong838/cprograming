#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct city
{
	char Name[50];
	char Country[50];
	int Population;
}City;

int main(void)
{
	City city[3];
	fputs("Input three cities:\n", stdout);
	for (int i = 0; i < 3; i++)
	{
		fputs("Name> ", stdout); fgets(city[i].Name, sizeof(city[i].Name),stdin);
		city[i].Name[strlen(city[i].Name) - 1] = 0;
		fputs("Country> ", stdout); fgets(city[i].Country, sizeof(city[i].Country), stdin);
		city[i].Country[strlen(city[i].Country) - 1] = 0;
		fputs("Population> ", stdout); scanf("%d", &city[i].Population);
		getchar();
	}
	printf("\nPrinting the three cities:\n");
	
	for (int i = 1; i < 4; i++)
	{
		printf("%d. %s in %s with a population of %d people\n", i, city[i - 1].Name, city[i - 1].Country, city[i - 1].Population);
	}
	return 0;
}