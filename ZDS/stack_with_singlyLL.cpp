#include <iostream>

using namespace std;

class Node{
public:
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
        next = NULL;


    }

};

class Stack{
    Node* top;
    int count;

public:
    Stack(){
        count = 0;
        top = NULL;
    }

    Stack(Node* node){
        top = node;
        count += 1;
    }

    void push(Node* node){
        if (node_exists(node->key) != NULL){
            cout<< "Node with such key already exist";
        }
        else{
            if(is_empty())
                top = node;
            else{
                node->next = top;
                top = node;
            }

            cout<<"Node <"<< top->key << " , "<< top->data <<"> pushed."<<endl;
            count++;
        }
    }

    void pop(){
        if(is_empty()){
            cout<< "Stack is underflow."<<endl;
        }else{
            Node* ptr = top;
            top = top->next;

            cout<<"Node <"<< ptr->key << " , "<< ptr->data <<"> popped."<<endl;

            delete ptr;
            ptr = NULL;

            count--;
        }
    }

    void display(){
        Node* ptr =  top;

        while (ptr != NULL)
        {
            cout<<"Node <"<< ptr->key << " , "<< ptr->data <<">"<<endl;
            ptr = ptr->next;
        }
        
    }

    int get_count(){
        return count;
    }

    bool is_empty(){
        if (top == NULL)
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
        return NULL;
    }

    
};

int main(){

    int key, data, option;
    Stack stack;
    do{
        
        cout<<"\nWhat operations to  perfom? Press 0 to exit.\n";
        cout<<"1. Push()."<<endl;
        cout<<"2. Pop()."<<endl;
        cout<<"3. Peek()."<<endl;
        cout<<"4. IsEmtpy()."<<endl;
        cout<<"5. Count()."<<endl;
        cout<<"6. Display()."<<endl;
        cout<<"7. Clear Screen\n"<<endl;

        Node* node = new Node();

        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Input the value-key: ";
                cin>> node->data;
                cin>> node->key;
                stack.push(node);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout<<"Use option 6 to see the last element(The one who comes first)"<<".\n";
                break;
            case 4:
                cout<<"Is empty? "<<stack.is_empty()<<".\n";
                break;
            case 5:
                cout<<"The queue has: "<< stack.get_count()<<" elements.\n";
                break;
            case 6:
                stack.display();
                break;
            case 7:
                system("clear");
                break;
        }

    }while(option != 0);

    return 0;
}