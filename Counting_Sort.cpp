#include <iostream>
#include <cstdlib>
using namespace std;

void countingSort(int arr[], int B[], int k, int length)
{

	int* C = new int[k+1];
	for (int i = 0; i <= k; i++) C[i] = 0;

	for (int j = 0; j < length; j++) C[arr[j]] += 1;

	for (int j = 1; j <= k; j++) C[j] = C[j] + C[j - 1];

	for (int j = length-1; j >= 0; j--)
	{
		int target = arr[j];
		B[C[target]-1] = arr[j];
		C[arr[j]] -= 1;
	}
}

int main()
{
	int n;
	cout << "Please input number range : " ;
	cin >> n ;

	int num;
	cout << "Please input number of array : " ;
	cin >> num;

	int *arr = new int[num];
	for (int i = 0; i < num; i++) arr[i] = rand() % n + 1;
	cout << "Array before sorted : ";
	for (int i = 0; i < num; i++) cout << arr[i] << " " ;
	cout << endl;

	int* sorted = new int[num];
	countingSort(arr, sorted, n, num);
	cout << "Array after sorted : " << " " ;
	for (int i = 0; i < num; i++) cout << sorted[i];
	cout << endl;

	return 0;
}