#include <iostream>
#include <fstream>
using namespace std;

void ArrayMerging(int arr[], int p, int q, int r) 
{

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void MergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    int m = l + (r - l) / 2;
	MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    ArrayMerging(arr, l, m, r);
  }
}

void Traversal(int arr[], int size) 
{
  for (int i = 0; i < size; i++)
  {
  	cout << arr[i] << " ";
  }
  cout << endl;
}

int main() 
{
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
    
    MergeSort(arr, 0, n-1);
    cout << "\n\nSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

