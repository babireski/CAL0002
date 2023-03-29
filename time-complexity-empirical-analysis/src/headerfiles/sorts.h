#ifndef _SORTS_H_
	#define _SORTS_H_
	void bubblesort(int* array, int size);
	void insertionsort(int* array, int size);
	void quicksort(int* array, int lo, int hi);
	void mergesort(int* array, int lo, int hi);
	void heapsort(int* array, int lo, int hi);
	void merge(int* array, int lo, int md, int hi);
	int partition(int* array, int lo, int hi);
#endif