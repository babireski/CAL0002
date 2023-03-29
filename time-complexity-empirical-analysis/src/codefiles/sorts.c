#include "../headerfiles/sorts.h"

void bubblesort(int* array, int size)
{
	int swapped = 1;

	while(swapped)
	{
		swapped = 0;

		for(int i = 1; i < size; i++)
		{
			if(array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				swapped = 1;
			}
		}
	}
}

void insertionsort(int* array, int size)
{
	int i = 1;

	while(i < size)
	{
		int j = i;

		while(j > 0 && array[j - 1] > array[j])
		{
			swap(&array[j - 1], &array[j]);
			j--;
		}

		i++;
	}
}

int partition(int* array, int leftmost, int rightmost)
{
	int pivot = array[rightmost];
	int i = leftmost - 1;

	for(int j = leftmost; j < rightmost; j++)
	{
		if(array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(array[i + 1], array[rightmost]);
	return i + 1;
}

void quicksort(int* array, int leftmost, int rightmost)
{
	if(leftmost < rightmost)
	{
		int halfway = partition(array, leftmost, rightmost);
		quicksort(array, leftmost, halfway - 1);
		quicksort(array, halfway + 1, rightmost);
	}
}

void merge(int* array, int leftmost, int halfway, int rightmost)
{

}

void mergesort(int* array, int leftmost, int rightmost)
{
	if(leftmost < rightmost)
	{
		int halfway = (leftmost + rightmost) / 2;
		mergesort(array, leftmost, halfway);
		mergesort(array, halfway + 1, rightmost);
		merge(array, leftmost, halfway, rightmost);
	}
}

void heapsort(int* array, int leftmost, int rightmost)
{

}