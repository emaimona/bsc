#include <iostream>

using namespace std;

int main()
{
    int size;

    cout << "Input the array size ";
    cin >> size;

    int* arraya = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Array [" << i << "]: ";
        cin >> arraya[i];
        cout << endl;
    }

    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Array [" << i << "]: ";
        cout << arraya[i];
        cout << endl;
    }


    delete[]arraya;
    arraya=NULL;

    return 0;
}