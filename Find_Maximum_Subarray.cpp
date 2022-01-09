#include <iostream>
#include <climits>

#define INF INT_MAX

using namespace std;

void printArr(int arr[], int num)
{
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int* FMCS(int A[], int low, int mid, int high)
{
	int left_sum = -INF;
	int sum = 0;
	int mleft = mid;
	int mright = mid+1;

	for (int i = mid; i >= low; i--)
	{
		
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			mleft = i;
		}
	}

	int right_sum = -INF;
	sum = 0;

	for (int j = mid + 1; j <= high; j++)
	{	
		sum = sum + A[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			mright = j;
		}
	}
	int* result = new int[3];
	result[0] = mleft;
	result[1] = mright;
	result[2] = left_sum + right_sum;

	return result;
}

int* FMS(int A[], int low, int high)
{
	if (high == low)
	{
		int* result = new int[3];
		result[0] = low;
		result[1] = high;
		result[2] = A[low];
		return result;
	}
	else
	{
		int mid = (high + low) / 2;
		int* lll = FMS(A, low, mid);
		int* rrr = FMS(A, mid + 1, high);
		int* ccc = FMCS(A, low, mid, high);


		if (lll[2] >= rrr[2] && lll[2] >= ccc[2]) return lll;
		else if (rrr[2] >= lll[2] && rrr[2] >= ccc[2]) return rrr;
		else return ccc;
	}
}


int main()
{
	int arr[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int size = sizeof(arr) / sizeof(int);
	int* result = FMS(arr, 0, size-1);
	printArr(arr, size);
	cout << "Start Value : " << arr[result[0]] << " (index = [" << result[0] << "])" << endl;
	cout << "End Value : " << arr[result[1]] << " (index = [" << result[1] << "])" << endl;

	cout << "Maximum Sum Subarray : [";
	for (int i = result[0]; i < result[1]; i++) cout << arr[i] << ", ";
	cout << arr[result[1]] << "]" << endl;

	cout << "Maximum sum : " << result[2] << endl;
}