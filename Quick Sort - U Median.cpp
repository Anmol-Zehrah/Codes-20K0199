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
void InsertionSort(int a[], int num)
{
    int min;
    int i, j;
    for (i = 0; i < num; i++)
    {
        min = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > min)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = min ;
    }
}
int DivideFunc(int arr[],int low,int high)
{
	int pivot = arr[(low + high)/2];
	int i = low;
	for(int j = low; j<=high ; j++)
	{
		if(arr[j]< pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void QuickSort(int arr[],int low,int high)
{
	int N = 50;
	if((high-low)<N)
	{
		InsertionSort(arr,high);
	}
	else if(low<high)
	{
		int pi = DivideFunc(arr,low,high);
		QuickSort(arr,low,pi);
		QuickSort(arr,pi+1,high);
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
