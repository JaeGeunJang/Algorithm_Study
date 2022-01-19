#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (arr[j] <= x)
		{
			i += 1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return i + 1;
}

int randomPartition(int arr[], int p, int r)
{
	int n = rand();
	int pvt = p + n % (r - p + 1);
	swap(&arr[r], &arr[pvt]);

	return Partition(arr, p, r);
}

void QuickSort(int arr[], int p, int r)
{
	if (p < r)
	{
		int q = randomPartition(arr, p, r);
		QuickSort(arr, p, q - 1);
		QuickSort(arr, q + 1, r);
	}
}


int main()
{
	int arr[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	int arrsize = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, arrsize - 1);
	for (int i = 0; i < arrsize; i++) cout << arr[i] << " ";
	cout << endl;
}
