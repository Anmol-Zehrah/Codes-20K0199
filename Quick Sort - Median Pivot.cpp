#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Traversal(int arr[], int size) 
{
  int i;
  for (i = 0; i < size; i++)
  {
  	cout << arr[i] << " ";
  }
  cout << endl;
}

int PivotVal(int arr[], int l, int h) {
	int pivot = arr[h];
	int i = (l - 1);
 
	for (int j = l; j < h; j++) {
		if (arr[j] < pivot) {
		swap(&arr[++i], &arr[j]);
		}
	}
 
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

int MedianFunc(int arr[], int l, int h) {
	
	int pivot;
	int mid = (l + h) / 2;
	if (arr[mid] < arr[l]) 
		swap(&arr[mid], &arr[l]);
	if (arr[h] < arr[l])
		swap(&arr[h], &arr[l]);
	if (arr[h] < arr[mid])
		swap(&arr[h], &arr[mid]);
	swap(&arr[mid], &arr[h-1]);
	
	pivot = arr[h-1];
 
	return PivotVal(arr, l, h);
}
void QuickSort(int arr[], int l, int h) {	
	if (l < h) {
		int pi = MedianFunc(arr, l, h);
 		QuickSort(arr, l, pi - 1);
 		QuickSort(arr, pi + 1, h);
	}
}


int main() {
    int n = 1000;
    int arr[n];
    ifstream file("1000-RandomNumbers.txt");
	int count = 0;
    int x;

    while (count < n && file >> x)
    {
    	arr[count++] = x;
	}
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < count; i++)
    {
    	cout << arr[i] <<' ';
	}
    QuickSort(arr, 0, n-1);
    cout << "\n\nSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
