#include <iostream>

using namespace std;

bool is_doubleo(int n){
    if(n%2==0)
        return false;
    return true;
}

void space(int lim, int n){
    lim = (lim*(lim + 1)) / 2;
    n = (lim - n)/2;
    (is_doubleo(n) && n>1)? n: n++;
    cout<< n;
    for (int i = 0; i < n; i++)
        cout<< " ";
}

int main(){

    Filho y(1244,"ema");

    int lim = 10, count = 1;

    cout<< is_doubleo(91);

    for(int i = 1, j=2; i < lim; i++, j++){
        if (i == 1){
            space(lim, count);
            cout<< "*"<< endl;
        }
        count+= j;
        space(lim, count);
        for (int k=0; k<count; k++)
            cout<< "*";
        cout<< endl;
    }
    cout<< y.nome<< y.idad;
    return 0;
}