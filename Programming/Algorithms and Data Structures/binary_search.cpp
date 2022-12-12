#include <iostream>
using namespace std;

int binary_search(int arr[], int bottom, int top, int value){
    if (bottom > top)
        return -1;
    
    int mid = (bottom + top) / 2;

    if (arr[mid] == value)
        return mid;
    else if (arr[mid] > value)
        return binary_search(arr, bottom, mid - 1, value);

    return binary_search(arr, mid + 1, top, value);

}


int main() {
    int arr[] = {1, 3, 7, 64, 75, 88, 96};
    int array_size = sizeof(arr) / sizeof(arr[0]);
    int value = 0, index = -1;
    
    cout<< endl<< "Enter the value to be searched: ";
    cin>> value;

    index = binary_search(arr, 0, array_size - 1, value);
   
    (index == - 1) ? cout<< "The element is not part of the array" : cout<< "Element found at position "<< ++index<< endl;  

    return 0;
}