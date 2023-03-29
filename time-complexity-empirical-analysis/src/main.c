#include "headerfiles/commons.h"
#include "headerfiles/searches.h"
#include "headerfiles/sorts.h"

#define FUNCTIONS 7
#define ITERATIONS 10
#define SIZE 1000
#define THRESHOLD 10000



int main()
{
	FILE* file = fopen("data/data.csv", "w");

	if(file == NULL)
		return 1;

	fputs("Size,Bubblesort,Insertionsort,Quicksort,Mergesort,Heapsort,Linearsearch,Binarysearch\n", file);

	int array[SIZE];
	float means[FUNCTIONS];

	for(int i = 10; i < SIZE + 1; i += 10)
	{
		fprintf(file, "%i,", i);

		for(int j = 0; j < FUNCTIONS; j++)
			means[j] = 0;

		for(int j = 0; j < ITERATIONS; j++)
		{
			for(int k = 0; k < FUNCTIONS; k++)
			{
				generate(array, i, THRESHOLD);
				clock_t clocks;

				/* Bubblesort */
				clocks = clock();
				bubblesort(array, i);
				clocks = clocks - clock();
				means[0] += clocks;


				/* Insertionsort */
				clocks = clock();
				insertionsort(array, i);
				clocks = clocks - clock();
				means[1] += clocks;

				/* Quicksort */
				clocks = clock();
				quicksort(array, 0, i - 1);
				clocks = clocks - clock();
				means[2] += clocks;

				/* Mergesort */
				clocks = clock();
				mergesort(array, 0, i - 1);
				clocks = clocks - clock();
				means[3] += clocks;

				/* Heapsort */
				clocks = clock();
				heapsort(array, i);
				clocks = clocks - clock();
				means[4] += clocks;

				/* Linearsearch */
				clocks = clock();
				linearsearch(array, i, );
				clocks = clocks - clock();
				means[5] += clocks;

				/* Binarysearch */
				clocks = clock();
				binarysearch(array, i, );
				clocks = clocks - clock();
				means[6] += clocks;
			}
		}
	}

	fclose(file);
	return 0;
}