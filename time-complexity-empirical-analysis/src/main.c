#include "headerfiles/commons.h"
#include "headerfiles/searches.h"
#include "headerfiles/sorts.h"

#define SORTS 5
#define FUNCTIONS 7
#define REPETITIONS 10
#define SIZE 5000
#define THRESHOLD 5000

static void (*sorts[SORTS])() = {bubblesort, insertionsort, quicksort, mergesort, heapsort};

int main()
{
	FILE* file = fopen("../data/data.csv", "w");

	if(file == NULL)
		return 1;

	fputs("Size;Bubblesort;Insertionsort;Quicksort;Mergesort;Heapsort;Linearsearch;Binarysearch\n", file);

	int array[SIZE];
	unsigned long int means[FUNCTIONS];

	for(int size = 1; size <= SIZE; size++)
	{
		fprintf(file, "%i", size);
		printf("%i", size);

		for(int i = 0; i < FUNCTIONS; i++)
			means[i] = 0;

		for(int repetition = 0; repetition < REPETITIONS; repetition++)
		{
			for(int function = 0; function < SORTS; function++)
			{
				generate(array, size, THRESHOLD);
				means[function] = sorttime(array, size, sorts[function]);
			}

			generate(array, size, THRESHOLD);
			means[SORTS + 1] = searchtime(array, size, array[rand() % size + 1], linearsearch);

			generate(array, size, THRESHOLD);
			quicksort(array, size);
			means[SORTS + 2] = searchtime(array, size, array[rand() % size + 1], binarysearch);
		}

		for(int i = 0; i < FUNCTIONS; i++)
		{
			means[i] /= REPETITIONS;
			fprintf(file, ";%lu", means[i]);
			printf(",%lu", means[i]);
		}
		
		fprintf(file, "\n");
		printf("\n");
	}

	fclose(file);
	return 0;
}