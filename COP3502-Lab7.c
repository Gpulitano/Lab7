#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[]);
void selectionSort(int array[]);
void swap(int* value1, int* value2);

int main()
{
	int array1[9] = { 97,16,45,63,13,22,7,58,72 };
	int array2[9] = { 90,80,70,60,50,40,30,20,10 };

	printf("Array1:\n");

	printf("Bubble Sort:\n");
	bubbleSort(array1);

	printf("Array2:\n");

	printf("Bubble Sort:\n");
	bubbleSort(array2);

	printf("Array1:\n");

	printf("Selection Sort:\n");
	selectionSort(array1);

	printf("Array2:\n");

	printf("Selection Sort:\n");
	selectionSort(array2);
}

void bubbleSort(int array[])
{
	int swapCount = 0;
	int swappedCountArray[9][2] = { 0 };

	for (int i = 0; i < 8; i++)
	{
		swappedCountArray[i][0] = array[i];
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapCount++;

				for (int k = 0; k < 8; k++)
				{
					if (array[j] == swappedCountArray[k][0])
					{
						swappedCountArray[k][1] += 1;
					}
					if (array[j + 1] == swappedCountArray[k][0])
					{
						swappedCountArray[k][1] += 1;
					}
				}
			}
		}

		printf("%d: Swapped %d times\n", swappedCountArray[i][0], swappedCountArray[i][1]);
	}

	printf("Total # of swaps: %d\n", swapCount);
}

void selectionSort(int array[])
{
	int swapCount = 0;
	int swappedCountArray[9][2] = { 0 };

	for (int i = 0; i < 8; i++)
	{
		swappedCountArray[i][0] = array[i];
	}

	for (int i = 0; i < 8; i++)
	{
		int min = swappedCountArray[i][0];
		int minIndex = 0;
		for (int j = i; j < 8; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}

		for (int k = 0; k < 8; k++)
		{
			if (array[i] == swappedCountArray[k][0])
			{
				swappedCountArray[k][1] += 1;
			}
			if (array[minIndex] == swappedCountArray[k][0])
			{
				swappedCountArray[k][1] += 1;
			}
		}

		swap(array[i], array[minIndex]);
		swapCount++;
	}

	for (int i = 0; i < 8; i++)
	{
		printf("%d: Swapped %d times\n", swappedCountArray[i][0], swappedCountArray[i][1]);
		printf("Total # of swaps: %d\n", swapCount);
	}
}

void swap(int* value1, int* value2)
{
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}