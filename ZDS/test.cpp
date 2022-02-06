#include <iostream>

using namespace std;

void message(string sms, int t){
    if(t == 0)
        return;

    cout<< sms<<endl;
    message(sms, --t);
}

int factorial(int number){
    if (number == 1)
        return 1;

    return number * factorial(number - 1);
}

int main(){

    //message("Just kiding...", 100000);
    int n;
    cin>> n;
    cout<< factorial(n)<< endl;

    return 0;
}