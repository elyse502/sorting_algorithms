#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, idx;

	for (max = array[0], idx = 1; idx < size; idx++)
	{
		if (array[idx] > max)
			max = array[idx];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 * Return: NULL.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, idx;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (idx = 0; idx < (max + 1); idx++)
		count[idx] = 0;
	for (idx = 0; idx < (int)size; idx++)
		count[array[idx]] += 1;
	for (idx = 0; idx < (max + 1); idx++)
		count[idx] += count[idx - 1];
	print_array(count, max + 1);

	for (idx = 0; idx < (int)size; idx++)
	{
		sorted[count[array[idx]] - 1] = array[idx];
		count[array[idx]] -= 1;
	}

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = sorted[idx];

	free(sorted);
	free(count);
}
