#include "../headerfiles/commons.h"

void generate(int* array, int size, int threshold)
{
	for(int i = 0; i < size; i++)
	{
		array[size] = rand() % threshold;
	}
}

double sorttime(int* array, int size, void (*sort)(int*, int))
{
	clock_t clocks = clock();
	sort(array, size);
	clocks = clock() - clocks;

	return (double) clocks / CLOCKS_PER_SEC;
}

double searchtime(int* array, int size, int key, void (*search)(int*, int, int))
{
	clock_t clocks = clock();
	sort(array, size, key);
	clocks = clock() - clocks;

	return (double) clocks / CLOCKS_PER_SEC;
}

void print(int* array, int size)
{
	printf("[");

	for(int i = 0; i < size; i++)
	{
		if(i)
			printf(", ");

		printf("%i", array[i]);
	}

	printf("]");
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}