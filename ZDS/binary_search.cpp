#include <iostream>
#include <vector>

using namespace std;

void display_arr(vector<int> a){
    for(int i = 0; i < a.size(); i++)
        cout<< a[i]<< " ";
    cout<<endl;
}

int bin_search(vector<int> a, int n){
    int left = 0;
    int right = a.size() - 1;
    int mid; 

    while(left <= right){   
        mid = (right + left) / 2;
        if(a[mid] == n)
            return mid;
        else if(a[mid] > n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main(){
    int n, pos;
    vector<int> arr = {1, 3, 12, 15, 19, 24, 30, 35, 43, 50, 67, 76, 83, 87, 94, 96, 102};

    display_arr(arr);
    cout<< "Find number: ";
    cin>> n;

    pos = bin_search(arr, n);

    (pos == -1)? cout<<"Not found": cout<< "Found at "<<pos;
    cout<< endl;

    return 0;
}