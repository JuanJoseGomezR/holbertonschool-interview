#include "sort.h"

/**
  * swap - swaps values in array
  * @a: first value to change
  * @b: second value to change
  * @array: array with the values
  * @size: size of array
  * Return: void
  */

void swap(int *a, int *b, int *array, int size)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}

/**
  * heapify- heapifies the array
  * @arr: array
  * @size: size of array
  * @real_size: real size
  * @i: iterator
  * Return: void
  */
void heapify(int *arr, int size, int i, int real_size)
{
	int largest = i;

	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

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
  * heap_sort - sort algorithm
  * @array: array to change
  * @size: sizeof array
  * Return: void
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
