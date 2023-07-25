#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swap two digits in array
 * @a: first digit to swap
 * @b: second digit to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - order subset array of digits according to
 * lomuto partition scheme (last element as pivot)
 * @array: array digit
 * @size: array size
 * @left: starting index of subset to order
 * @right: ending index of subset to order
 *
 * Return: final partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - implement quicksort algo through recursion
 * @array: array digits to sort
 * @size: array size
 * @left: starting index of array partition to order
 * @right: ending index of array partition to order
 *
 * Description: use Lomuto partition scheme
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - sort array digits in ascending
 * order using quicksort algo
 * @array: array digit
 * @size: array size
 *
 * Description: use lomuto partition scheme
 * print array after each swap of two elements
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
