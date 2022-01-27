#include <iostream>

using namespace std;

template<typename T>
void print(T number)
{
    cout<<"The number is "<< *number<< endl;
    
}

void print(void* number, char type)
{
    switch(type)
    {
        case 'i':
            cout<<"The number is "<< *((int *)number)<< endl;
            break;
        case 'c': 
            cout<<"The number is "<< *((char *)number);
            break;
    }
    
}

int main()
{
    int n = 4, tob= 488;
    char c = '9';

    print(&tob);

    print(&n, 'i');
    print(&c, 'c');

    return 0;
}