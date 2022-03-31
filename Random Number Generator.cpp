#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
int main()
{
    int i;
    srand(time(0));
    for(i=0; i<1000; i++)
        cout<<rand()<<endl;
    cout<<endl;
    
    ofstream MyFile("1000-RandomNumbers.txt");
    for(i=0; i<1000; i++)
        MyFile << rand() <<endl;
	
	MyFile.close();
    return 0;
}
