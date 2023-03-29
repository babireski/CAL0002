#include "../headerfiles/commons.h"

void arraygenerator(int* array, int size, int threshold)
{
	for(int i = 0; i < size; i++)
	{
		array[size] = rand() % threshold;
	}
}

void arrayprinter(int* array, int size)
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