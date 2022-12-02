#include <iostream>
using namespace std;
// A function to merge the two subarrays into a sorted array.
void Merge(int* a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted through the mergesort function.
	int i, j, k;
	int* temp = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values in the left subarray from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values in the right subarray from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// move the sorted data stored in temporary array temp[] to array a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

// A function to split array into two parts.
void MergeSort(int* a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two subarrays.
		MergeSort(a, low, mid);                     //the left subarray
		MergeSort(a, mid + 1, high);               //the right subarray

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	// for testing
	int arr[] = { 60,10,20,50,20,70 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, 0, n - 1);
	print(arr, n);

}
