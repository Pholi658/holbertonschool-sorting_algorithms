#include "sort.h"

/**
 * swap_int - Swap two integers
 * @a: pointer to first int
 * @b: pointer to second int
 */
static void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partition array using Lomuto scheme and print after each swap
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: array size for print_array
 *
 * Return: partition index
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low;

	j = low;
	while (j <= high - 1)
	{
		if (array[j] < pivot)
		{
			if (i != j && array[i] != array[j])
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
		j++;
	}

	/* Swap pivot into place only if needed */
	if (i != high && array[i] != array[high])
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_rec - Recursively sorts using Quick sort (Lomuto)
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of array (for printing)
 */
static void quick_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_rec(array, low, p - 1, size);
		quick_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 * @array: array to sort
 * @size: number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	int n;

	if (array == NULL || size < 2)
		return;

	n = (int)size;
	quick_rec(array, 0, n - 1, size);
}

