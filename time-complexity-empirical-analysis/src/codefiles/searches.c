#include "../headerfiles/searches.h"

/* Linear search*/

int linearsearch(int* array, int size, int key)
{
	for(int i = 0; i < size; i++)
		if(array[i] == key)
			return i;

	return -1;
}

/* Binary search */

int binarysearch(int* array, int size, int key)
{
	int leftmost = 0;
	int rightmost = size - 1;

	while(leftmost <= rightmost)
	{
		int halfway = (leftmost + rightmost) / 2;

		if(array[halfway] < key)
			leftmost = halfway + 1;

		else if(array[halfway] < key)
			rightmost = halfway - 1;

		else
			return halfway;
	}

	return -1;
}