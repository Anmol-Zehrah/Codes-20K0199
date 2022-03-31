#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
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

int DivideFunc(int arr[], int low, int high) {
    
  int pivot = arr[high];
  int i = (low - 1);
  
  for (int j = low; j < high; j++) 
  {
    if (arr[j] <= pivot) 
	{
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
int RandomPivot(int arr[], int low, int high)
{
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return DivideFunc(arr, low, high);
}

void QuickSort(int arr[], int low, int high) 
{
  if (low < high) 
  {
    int pi = RandomPivot(arr, low, high);
    QuickSort(arr, low, pi - 1);
    QuickSort(arr, pi + 1, high);
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
