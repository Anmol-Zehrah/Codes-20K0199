#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
    
    InsertionSort(arr, n);
    cout << "\n\nSorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}


