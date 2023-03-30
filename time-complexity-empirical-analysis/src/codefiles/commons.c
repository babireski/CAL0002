#include "../headerfiles/commons.h"

void generate(int* array, int size, int threshold)
{
	for(int i = 0; i < size; i++)
	{
		array[i] = rand() % threshold;
	}
}

unsigned long sorttime(int* array, int size, void (*sort)(int*, int))
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	sort(array, size);
	gettimeofday(&end, NULL);

	return (1000000 * end.tv_sec + end.tv_usec) - (1000000 * start.tv_sec + start.tv_usec);
}

unsigned long searchtime(int* array, int size, int key, int (*search)(int*, int, int))
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	search(array, size, key);
	gettimeofday(&end, NULL);

	return (1000000 * end.tv_sec + end.tv_usec) - (1000000 * start.tv_sec + start.tv_usec);
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