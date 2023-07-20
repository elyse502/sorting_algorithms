#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The First integer to swap.
 * @b: The Second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 * Return: void.
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, len = size;
	bool Bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (Bubbly == false)
	{
		Bubbly = true;
		for (idx = 0; idx < len - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				swap_ints(array + idx, array + idx + 1);
				print_array(array, size);
				Bubbly = false;
			}
		}
		len--;
	}
}
