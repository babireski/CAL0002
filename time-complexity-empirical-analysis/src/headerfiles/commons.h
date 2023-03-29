#ifndef _COMMONS_H_
	#define _COMMONS_H_
	#include <stdio.h>
	#include <time.h>
	void generate(int* array, int size, int threshold);
	double sorttime(int* array, int size, void (*sort)(int*, int));
	double searchtime(int* array, int size, int key, void (*search)(int*, int, int));
	void print(int* array, int size);
	void swap(int* a, int* b);
#endif