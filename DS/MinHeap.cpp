#include <iostream>
#include <cmath>
#include "Funtions.h"

using namespace std;


class MinHeap{
public:
    int* array;
    int capacity;
    int size;

    MinHeap(int elements){
        capacity = elements;
        array = new int(capacity);
        size = 0;
    }

    void decreasekey(int index){
        array[index] = getMin() - 1;
        while(index != 0 && array[index] < array[parentIndex(index)]){
            my_swap(array[index], array[parentIndex(index)]);
            index = parentIndex(index);
        }
    }

    void deleteKey(int index){
        if (index >= size)
            cout<< "Invalid key"<< endl;
        else {
            decreasekey(index);
            extractMin();
        }
    }

    void minHeapify(int index){
        int left_index = index + 1;
        int right_index = index + 2;
        int smallest = index;

        if (left_index < size && array[smallest] > array[left_index])
            smallest = left_index;
        if (right_index < size && array[smallest] > array[right_index])
            smallest = right_index;
        if (smallest != index) {
            my_swap(array[index], array[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin(){
        if(isEmpty())
            return INT8_MAX;
        else if (size == 1){
            size--;
            return array[0];
        }

        int root = array[0];
        array[0] = array[--size];

        minHeapify(0);

        return root;
    }

    void insertValue(int value){
        if (isFull())
            cout<<"Heap Full";
        else{
            int child_index = size++;

            array[child_index] = value;
            
            while (child_index != 0 && array[child_index] < array[parentIndex(child_index)]){
               my_swap(array[child_index] , array[parentIndex(child_index)]);
               child_index = parentIndex(child_index);
            }
        }
    }

    void printHeap(){
        for(int i = 0; i < size; i++)
            cout<< array[i]<< " ";
        cout<< endl;
    }

    int linearSearch(int value){
        for(int i = 0; i < size; i++)
            if (array[i] == value) return i;

        return -1;
    }

    int getMin(){
        return (!isEmpty())? array[0] : INT16_MIN;
    }

    int height(){
        return (ceil(log2(size + 1)) - 1);
    }

    int parentIndex(int child_index){
        return (child_index - 1) / 2;
    }

    int leftChildIndex(int parent_index){
        return (2 * parent_index) + 1;
    }

    int rightChildIndex(int parent_index){
        return (2 * parent_index) + 2;
    }

    bool isFull(){
        return (size == capacity)? 1 : 0;
    }

    bool isEmpty(){
        return (size == 0 )? 1 : 0;
    }

};

int main() {
  int size, option, value;
  cout << "Enter Size of Min Heap" << endl;
  cin >> size;
  MinHeap heap(size);
  
  cout << "Min Heap Created" << endl;
  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout << "4. Get Min" << endl;
    cout << "5. Extract Min" << endl;
    cout << "6. Height of Heap" << endl;
    cout << "7. Print/Traversal Heap values" << endl;
    cout << "8. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation -" << endl;
      cout << "Enter VALUE to INSERT in HEAP: ";
      cin >> value;
      heap.insertValue(value);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation -" << endl;
      cout << "Enter VALUE to SEARCH in HEAP: ";
      cin >> value;
      heap.linearSearch(value);
      break;
    case 3:
      cout << "DELETE Operation -" << endl;
      cout << "Enter INDEX of Heap Array to DELETE: ";
      cin >> value;
      heap.deleteKey(value);
      break;
    case 4:
      cout << "GET Min value : " << heap.getMin();
      cout << endl;
      break;
    case 5:
      cout << "EXTRACT Min value : " << heap.extractMin();
      cout << endl;
      break;
    case 6:
      cout << "HEAP TREE HEIGHT : " << heap.height() << endl;
      break;

    case 7:
      cout << "PRINT Heap Array : " << endl;
      heap.printHeap();

      cout << endl;
      break;

    case 8:
      system("clear");
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
