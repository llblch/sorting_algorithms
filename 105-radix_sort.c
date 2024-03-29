#include "sort.h"
#include <stdio.h>
/**
 * getMax - A utility function to get maximum value
 * @arr: array
 * @n: size of the array
 * Return: array
 */
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countSort - A function to do counting sort
 * @arr: array
 * @n: size of the array
 * @exp: exp is 10^i
 * @output: array to save the temporary values
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
	/*print_array(arr, n);*/
}

/**
 * radix_sort - The main function that sorts arr[]
 * @array: array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
