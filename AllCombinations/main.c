#include <stdio.h>
#include <stdlib.h>

void printCombinations(int data[], int index, int r)
{
	for (int j = 0; j < r; j++)
	{
		printf("%d ", data[j]);
	}	
	printf("\n");
	return;
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int smallestIndex)
{
	if (index == r)
	{
		printCombinations(data, index, r);
	}
	else
	{
		for (int i = start; i <= end && end - i + 1 >= r - index && (start > 0 || i == smallestIndex); i++)
		{
			data[index] = arr[i];
			combinationUtil(arr, data, i + 1, end, index + 1, r, smallestIndex);
		}
	}
}

void allCombination(int arr[], int n, int r)
{
	int* data = (int*) malloc(sizeof(int) * r);
	combinationUtil(arr, data, 0, n - 1, 0, r, 0);
	free(data);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int r = 3;
	allCombination(arr, n, r);
}