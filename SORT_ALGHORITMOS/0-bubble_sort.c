#include "sort.h"

/**
 * swap - swap two elements in array
 * @array: element of array to swap
 * @array2: element of array to swap
 */
void swap(int *array, int *array2)
{
	int tmp;

	tmp = *array;
	*array = *array2;
	*array2 = tmp;
}

/**
 * bubble_sort - sort array
 * @array: address array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, i, j;
	/*int tmp;*/

	if (size <= 0 || array == NULL)
		return;

	n = size;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = 0; j < (n - 1); j++)
		{
			if (array[j] < array[j + 1])
				continue;
			else
			{
				if (array[j] == array[j + 1])
					break;
				swap(&array[j], &array[j + 1]);
				/*tmp = array[j];*/
				/*array[j] = array[j + 1];*/
				/*array[j + 1] = tmp;*/
				print_array(array, size);
			}
		}
	}
}
