#include <iostream>

using namespace std;

class Node{
public:
    int data, key;
    Node* prev;
    Node* next;

    Node(){
        data = key = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int k, int d){
        key = k;
        data = k;
    }

};

class Doubly_linked_list{
public:
    Node* head;
    Node* tail;

    Doubly_linked_list(){
        head = NULL;
        tail = NULL;
    }

    Doubly_linked_list(Node* n){
        head  = n;
        tail = head; 
    }

    void append_node(Node* n){
        if(node_exists(n->key) != NULL){
            cout<< "Node with such key already exist...";
        }
        else{
            if(head == NULL){
                head = n;
                tail = head;

                write(head, 'a');
            }
            else{
                Node* ptr = head;

                while(ptr->next != NULL){
                    ptr = ptr->next;
                }

                n->prev = ptr;
                ptr->next = n;

                tail = n;

                write(ptr->next, 'a');
            }
        }
    }

    void prepend_node(Node* n){
        if(node_exists(n->key) != NULL){
            cout<< "Node with such key already exist...";
        }
        else{
            if(head == NULL){
                head = n;
                tail = head;

                write(head, 'p');
            }
            else{
                n->next = head;
                head->prev = n ;
                head = n;

                write(head, 'p');
            }
        }
    }

    void insert_node(int k, Node* n){
        Node* ptr = node_exists(k);

        if(node_exists(n->key) != NULL){
            cout<< "Node with such key already exist..."<< endl;
        }
        if(ptr == NULL){
            cout<< "There is no node with such key...";
        }
        else{
            if(ptr->next == NULL){
                tail = n;
                ptr->next = n;
                n->prev = ptr;

                write(ptr->next, 'i');
            }
            else{
                n->next = ptr->next;
                n->prev = ptr;
                ptr->next->prev = n;
                ptr->next = n;

                write(ptr->next, 'i');
            }
        
        }
    }

    void delete_node(int k){
        Node* ptr = node_exists(k);

        if(ptr == NULL){
            cout<< "There is no node with such key...";
        }
        else{
            if(ptr->next == NULL){
                if(ptr == head){
                    head = NULL;
                    tail = head;
                }
                else{
                    ptr->prev->next = NULL;
                    tail = ptr->prev;                    
                }
                write(ptr, 'd');
                ptr = NULL;
            }
            else{
                if(ptr == head){
                    head = ptr->next;
                }
                else{
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                write(ptr, 'd');
                ptr = NULL;
            }
        
        }
    }

    void update_node(int k, int d){
        Node* ptr = node_exists(k);

        if(ptr == NULL){
            cout<< "There is no node with such key...";
        }
        else{
            write(ptr, 'u');
            ptr->data = d;        
        }
    }

    Node* node_exists(int k){
        Node* ptr = head;

        while(ptr != NULL){
            if(ptr->key == k)
                return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }

    void display(){
        Node* ptr = head;

        while(ptr != NULL){
            cout<<"Node <"<< ptr->key << " , "<< ptr->data <<">"<<endl;
            ptr = ptr->next; 
        }
    }


    void display_reverse(){
        Node* ptr = tail;

        while(ptr != NULL){
            cout<<"Node <"<< ptr->key << " , "<< ptr->data <<">"<<endl;
            ptr = ptr->prev; 
        }
    }

    void write(Node* ptr, char op){
        cout<<"Node <"<< ptr->key << " , "<< ptr->data <<">";

        switch(op){
            case 'a':
                cout<< " appended."<< endl;
                break;
            case 'p':
                cout<< " prepended."<< endl;
                break;
            case 'd':
                cout<< " deleted."<< endl;
                break;
            case 'i':
                cout<< " inserted."<< endl;
                break;
            case 'u':
                cout<< " updated."<< endl;
                break;
            default:
                cout<< " Nem tudom."<< endl;
                break;
        }
    }
};

int main(){
    int data, key, op;

    Doubly_linked_list d;

    system("clear");

    do{
        cout<<"\nWhat operations to  perfom? Press 0 to exit.\n";
        cout<<"1. Append a node()."<<endl;
        cout<<"2. Prepend a node()."<<endl;
        cout<<"3. Insert a node()."<<endl;
        cout<<"4. Delete a node()."<<endl;
        cout<<"5. Update a node()."<<endl;
        cout<<"6. Display()."<<endl;
        cout<<"7. Display in reverse()."<<endl;
        cout<<"8. Clear Screen\n"<<endl;

        cin>>op;

        Node* n = new Node();

        switch(op){
            case 0:
                break;
            case 1:
                cout<<"Input the key_value: ";
                cin>> n->key;
                cin>> n->data;
                d.append_node(n);
                break;
            case 2:
                cout<<"Input the key_value: ";
                cin>> n->key;
                cin>> n->data;
                d.prepend_node(n);
                break;
            case 3:
                cout<<"Input the key_value: ";
                cin>> n->key;
                cin>> n->data;
                cout<<"Insert after: ";
                cin>> key;
                d.insert_node(key, n);
                break;
            case 4:
                cout<<"Delete the node with key: ";
                cin>> key;
                d.delete_node(key);
                break;
            case 5:
                cout<<"Update the key_value: ";
                cin>> key;
                cin>> data;
                d.update_node(key, data);
                break;
            case 6:
                d.display();
                break;
            case 7:
                d.display_reverse();
                break;
            case 8:
                system("clear");
                break;
        }

    }while(op != 0);

    return 0;
}