#include <iostream>

using namespace std;

void printmessage(string sms, int rounds){
    if(rounds == 0)
        return;
    cout<< sms<<endl;
    printmessage(sms, --rounds);
}


void reverseString(string str, int position){
    if (position < 0)
        return;
    cout<< str[position];
    reverseString(str, --position);   
}

bool palindromes(string str){
    int size = str.length() - 1;

    return check()
}

int main(){

    //printmessage("Just kiding...", 100000);
    //string str = "anomiaM agnizN leunamE";
    //reverseString(str, str.length() - 1);

    cout<< endl;

    return 0;
}