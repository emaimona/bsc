#include <iostream>
#include "Funtions"

using namespace std;

class Node{
    int key, data;
    Node* next;

    Node(){
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int node_key, int node_data){
        key = node_key;
        data = node_data;
    }

};

class Stack{
    Node* top;

    Stack(){
        top = NULL;
    }

    Stack(Node* node){
        top = node;
    }

public:
    void push(Node* node){
        if (node)
    }

// TO IMPLEMENT IN CASE OF NEED 
    void is_full();

    bool is_empty(){
        if (top->next == NULL)
            return 1;

        return 0;
    }

    Node* node_exists(int key){
        Node* ptr = top;

        while(ptr != NULL){
            if(ptr->key == key)
                return ptr;

            ptr = ptr->next;
        }
    }

};

int main(){

    int key, data, option;

    do{
        
        cout<<"\nWhat operations to  perfom? Press 0 to exit.\n";
        cout<<"1. Push()."<<endl;
        cout<<"2. Pop()."<<endl;
        cout<<"3. Peek()."<<endl;
        cout<<"4. IsFull()."<<endl;
        cout<<"5. Count()."<<endl;
        cout<<"6. Display()."<<endl;
        cout<<"7. Clear Screen\n"<<endl;

        cin>>option;

        switch(op){
            case 0:
                break;
            case 1:
                cout<<"Input the value: ";
                cin>> val;
                q.enqueue(val);
                break;
            case 2:
                cout<< q.dequeue()<< " Dequed\n";
                break;
            case 3:
                cout<<"Is empty? "<<q.isEmpty()<<".\n";
                break;
            case 4:
                cout<<"Is full? "<<q.isFull()<<".\n";
                break;
            case 5:
                cout<<"The queue has: "<< q.count()<<" elements.\n";
                break;
            case 6:
                q.display();
                break;
            case 7:
                system("clear");
                break;
        }

    }while(op != 0);

    return 0;
}