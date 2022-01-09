#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n-1; j > i ; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 1,5,2,6,7,8,10,24,622,34,-10 };
	int size = sizeof(arr) / sizeof(int);
	bubbleSort(arr, size);
	printArray(arr, size);
}
