#include <iostream>

using namespace std;
int main(){

    int n = 5;
    int *ptr = &n;

    cout<< &n<< endl;
    cout<< ptr<< endl;
    *ptr = 10;
    cout<< *ptr<< endl<< n;

    return 0;
}