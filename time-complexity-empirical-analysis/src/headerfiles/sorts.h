#ifndef _SORTS_H_
	#define _SORTS_H_
	#include "commons.h"
	void bubblesort(int* array, int size);
	void insertionsort(int* array, int size);
	void quicksort(int* array, int size);
	void truequicksort(int* array, int leftmost, int rightmost);
	int partition(int* array, int leftmost, int rightmost);
	void mergesort(int* array, int size);
	void truemergesort(int* array, int leftmost, int rightmost);
	void merge(int* array, int leftmost, int halfway, int rightmost);
	void heapsort(int* array, int size);
	void heapify(int* array, int size, int i);
#endif