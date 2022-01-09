#include <iostream>
using namespace std;

void insertionSort(int arr[], int num)
{
  int key;
  for (int j = 1; j < num; j++)
  {
    key = arr[j];
    int i = j-1;
    while (i >= 0 and arr[i] > key)
    {
      arr[i+1] = arr[i];
      i -= 1;
    }
    arr[i+1] = key;
  }
}
/*
* int main()
{
  int arr[10] = {4,1,5,2,7,8,6,10,9,3};
  insertionSort(arr, 10);
  for (int i = 0; i < 10; i++) cout << arr[i];
}
*/

