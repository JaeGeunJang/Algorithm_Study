#include <iostream>
#include <limits.h>

using namespace std;
int heap_size;
#define inf INT_MAX

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

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

int HM(int arr[])
{
	return arr[1];
}

int HEM(int arr[])
{
	if (heap_size < 1)
	{
		cout << "Heap underflow" << endl;
		return;
	}
	int max = arr[1];
	arr[1] = arr[heap_size - 1];
	heap_size -= 1;
	MH(arr, 0, heap_size);
}

void HIK(int arr[], int i, int key)
{
	if (key < arr[i])
	{
		cout << "New key is less than key" << endl;
		return;
	}
	arr[i] = key;
	while (i > 1 && arr[parent(i)] < arr[i])
	{
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}

void MHI(int arr[], int key)
{
	heap_size += 1;
	arr[heap_size] = -inf;
	HIK(arr, heap_size, key);
}

