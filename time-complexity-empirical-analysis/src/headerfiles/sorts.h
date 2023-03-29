#ifndef _SORTS_H_
	#define _SORTS_H_
	void bubblesort(int* array, int size);
	void insertionsort(int* array, int size);
	void quicksort(int* array, int leftmost, int rightmost);
	void mergesort(int* array, int leftmost, int rightmost);
	void heapsort(int* array, int size);
	void merge(int* array, int leftmost, int halfway, int rightmost);
	int partition(int* array, int leftmost, int rightmost);
#endif