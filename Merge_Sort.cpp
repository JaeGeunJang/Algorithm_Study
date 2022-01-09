#include <iostream>
using namespace std;

void a_merge(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) L[i] = A[p + i];
	for (int j = 0; j < n2; j++) R[j] = A[q + j + 1];

	int i = 0;
	int j = 0;
	int k = p;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
}

void a_mergeSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		a_mergeSort(A, p, q);
		a_mergeSort(A, q + 1, r);
		a_merge(A, p, q, r);
	}
	else return;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 1,3,5,7,9,2,4,6,8,10 };
	int size = sizeof(a) / sizeof(a[0]);
	cout << "Unsorted array : " << endl;
	printArray(a, size);
	a_mergeSort(a, 0, size - 1);
	cout << "Sorted array : " << endl;
	printArray(a, size);
}