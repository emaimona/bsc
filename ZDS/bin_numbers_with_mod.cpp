#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int n;

    cout<<"Input the number of binary 1-0: ";
    cin>> n;

    for(int i = 0; i < n; i++)
        cout<< (i % 2)<< " ";
    return 0;
}
