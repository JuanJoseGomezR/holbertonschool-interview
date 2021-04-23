#include "sort.h"

/**
  *
  *
  *
  */

void swap(int *a, int *b, int *array, int size)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

void heapify(int *arr, int size, int i, int real_size)
{
	int largest = i;

	int left = (2 * i) + 1;
	int right = (2 * i )+ 2;

	if (left < size && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < size && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&arr[i], &arr[largest], arr, real_size);
		heapify(arr, size, largest, real_size);
	}
}



/**
  *
  *
  *
  */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}
