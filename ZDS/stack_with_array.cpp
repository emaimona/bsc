#include <iostream>

using namespace std;


class Stack{
    int top, size;
    int* arr;

protected:
    bool isFull(){
        if(top == size-1)
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }
public:
    Stack(int siz){
        top = -1;
        arr = new int(siz);
        size = siz;
    }

    void push(int val){
        if(isFull()){
            cout<< "Stack overflow"<< endl;;
        }
        else{
            top++;
            arr[top] = val;
            cout<< "pushed"<< endl;;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<< "stack underflow"<< endl;;
            return 0;
        }
        else {
            int n = arr[top];
            arr[top] = 0;
            top--;
            cout<<"Poped"<< endl;;
            return n;            
        }
    }

    int peek(int index){
        if(index > top and !isEmpty()){
            cout<< "Error peek the number"<< endl;;
            return 0;
        }
        else{
            return arr[index];
        }
    }

    void change(int index, int value){
        if(index <= top && !isEmpty()){
            arr[index] = value;
            cout<< "changed!"<< endl;;
        }
        else{
            cout<< "Error changing the number"<< endl;;
        }
    }

    void list(){
        for(int i=top; i >= 0; i--){
            cout<< "Listing"<< endl;
            cout<<"["<<i<<"]== "<<arr[i]<< endl;;
        }
    }

    ~Stack(){
        delete[] arr;
        arr = NULL;
    }

};


int main(){
    Stack s(4);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(8);
    s.push(5);

    cout<< s.pop()<< endl;

    s.push(325);

    cout<< s.peek(4)<< endl;

    s.list();
    s.change(2, 454);
    s.list();

    return 0;
}