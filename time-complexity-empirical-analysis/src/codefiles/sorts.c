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
	int n = halfway - leftmost + 1;
	int m = rightmost - halfway;
	int leftside[n], rightside[m];

	for(int i = 0; i < n; i++)
		leftside[i] = array[leftmost + i];
	
	for(int i = 0; i < m; i++)
		rightside[i] = array[halfway + i + 1];

	int i = 0;
	int j = 0;
	int k = leftmost;

	while(i < n && j < m)
	{
		if(leftside[i] <= rightside[j])
		{
			array[k] = leftside[i];
			i++;
		}

		else
		{
			array[k] = rightside[j];
			j++;
		}

		k++;
	}

	while(i < n)
	{
		array[k] = leftside[i];
		i++;
		k++;
	}
	

	while(j < m)
	{
		array[k] = rightside[j];
		j++;
		k++;
	}	
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

void heapify(int* array, int size, int i)
{
	int largest = i;
	int left = 2 * 1 + 1;
	int right = 2 * 1 + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, size, largest);
	}
}

void heapsort(int* array, int size)
{
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for(int i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		heapify(array, i, 0);
	}
}