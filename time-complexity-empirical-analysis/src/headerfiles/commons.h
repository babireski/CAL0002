#ifndef _COMMONS_H_
	#define _COMMONS_H_
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <sys/time.h>
	void generate(int* array, int size, int threshold);
	unsigned long int sorttime(int* array, int size, void (*sort)(int*, int));
	unsigned long int searchtime(int* array, int size, int key, int (*search)(int*, int, int));
	void print(int* array, int size);
	void swap(int* a, int* b);
#endif