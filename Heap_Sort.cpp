#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int parent(int i)
{
	if (i % 2) return (i - 1) / 2;
	else return (i - 2) / 2;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

void MH(int arr[], int i, int heap_size)
{
	int l = left(i);
	int r = right(i);
	int largest;

	if ((l < heap_size) && (arr[l] > arr[i])) largest = l;
	else largest = i;

	if ((r < heap_size) && (arr[r] > arr[largest])) largest = r;
	if (largest != i)
	{
		swap(&(arr[i]), &(arr[largest]));
		MH(arr, largest, heap_size);
	}	
}
void BMH(int arr[], int arrsize)
{
	for (int i = arrsize/2; i >= 0; i--) MH(arr, i, arrsize);
}

void HS(int arr[], int arrsize)
{
	int heap_size = arrsize;
	BMH(arr, arrsize);
	for (int i = arrsize-1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heap_size -= 1;
		MH(arr, 0, heap_size);
	}
}

int main()
{
	int arr[] = { 16, 4,10,14,7,9,3,2,8,1 };
	
	int arrsize = sizeof(arr) / sizeof(int);
	int heap_size = arrsize;

	HS(arr, arrsize);

	for (int i = 0; i < arrsize; i++) cout << arr[i] << " ";
}