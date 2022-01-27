#include <iostream>

using namespace std;

class Node{
public:
    int data, key;
    Node* next;

    Node(){
        data = 0;
        key = 0;
        next = NULL;
    }

    Node(int k, int d){
        data = d;
        key = k;
        next = NULL;
    }

};


class Singly_linked_list{
public:
    Node* head;

    Singly_linked_list(){
        head = NULL;
    }
    Singly_linked_list(Node* n){
        head = n;
    }
    ~Singly_linked_list(){
        /*Node* next;
        Node* ptr;
        ptr = head;
        while(ptr != NULL){
            next = ptr->next;
            delete ptr;
            ptr = next->next;
        }
        
        delete [] ptr;
        delete next;
        delete head;
        head = NULL;
        ptr = NULL;
        next = NULL;*/
    };

    void append_node(Node* n){
        if(node_exist(n->key) != NULL){
            cout<< "Node with the key already exist, Insert a node with another key..."<< endl;
        }
        else{

            if(head == NULL){
                head = n;
                cout<< "Node <"<< head->key<<", "<< head->data << "> Appended "<< endl;
            }
            else {
                Node* ptr = head;
                
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<< "Node <"<< ptr->next->key<<", "<< ptr->next->data << "> Appended "<< endl;
            }
        }
    }

    void preppend(Node* n){
        if(node_exist(n->key) != NULL){
            cout<< "Node with the key already exist, Insert a node with another key..."<< endl;
        }
        else{
            if(head == NULL){
                head = n;
                cout<< "Node <"<< head->key<<", "<< head->data << "> Preppended "<< endl;
            }else{
                //Node* ptr = head;
                n->next = head;
                head = n;
                cout<< "Node <"<< head->key<<", "<< head->data << "> Preppended "<< endl;
            }
        }
    }

    void insert_node(int key, Node* n){
        if(node_exist(key) == NULL){
            cout<< "Node with the key Does not exist, Try with another key..."<< endl;
        }
        if(node_exist(n->key) != NULL){
            cout<< "Node with the key already exist, Insert a node with another key..."<< endl;
        }
        else{
            Node* ptr = head;

            while(ptr != NULL){
                if(ptr->key == key){
                    if(ptr->next == NULL){
                        ptr->next = n;
                        cout<< "Node <"<< ptr->next->key<<", "<< ptr->next->data << "> Inserted after <"<<key <<"> "<< endl;
                    }   
                    else{
                        n->next = ptr->next;
                        ptr->next = n;
                        cout<< "Node <"<< ptr->next->key<<", "<< ptr->next->data << "> Inserted after <"<<key <<"> "<< endl;
                    }
                }
                ptr = ptr->next;
            }
        }
    }

    void delete_node(int k){
        if(node_exist(k) == NULL){
            cout<< "Node with the key Does not exist, Try with another key..."<< endl;
        } else if(head == NULL){
            cout<< "The list is empty..."<< endl;
        }
        else{
            Node* prev = NULL;
            Node* ptr = head;
            while(ptr != NULL){
                if(ptr->key == k){
                    if(ptr->next == NULL){
                        if(prev == NULL){           
                            ptr = NULL;
                            head = NULL;
                            
                      
                        }else{
                            prev->next = NULL;
                            ptr = NULL;
                        }   
                        cout<< "Node <"<<k <<"> "<<"deleted."<< endl;
                        
                    } else{
                        if(prev == NULL){
                            head = ptr->next;
                            ptr = NULL;
                        }else{
                            prev->next = ptr->next;
                            ptr = NULL;
                        }
                        
                        cout<< "Node <"<<k <<"> "<<"deleted."<< endl;
                    }
                    break;
                }

                prev = ptr;
                ptr = ptr->next;
            }
        }
    }


    void update_node(int k, int d){
        if(node_exist(k) == NULL){
            cout<< "Node with the key Does not exist, Try with another key..."<< endl;
        } else if(head == NULL){
            cout<< "The list is empty..."<< endl;
        }
        else{
            Node* ptr = head;
            while(ptr != NULL){
                if(ptr->key == k){
                   ptr->data = d;
                   cout<< "Node <"<<k <<"> "<<"updated."<< endl;
                   break;
                }
                ptr = ptr->next;
            }
        }
    }


    void point_info(Node* n){
        cout<<"Key: " << n->key<< endl;
        cout<<"Data: "<< n->data<< endl;
        cout<<"Next: "<< n->next<< endl;
    }
    void print(){
        Node* ptr = head;
        while(ptr != NULL){
            cout<< "Node <"<< ptr->key<<", "<< ptr->data << ">"<< endl;
            ptr = ptr->next;
        }
        cout<<endl;
    }

    Node* node_exist(int k){
        Node* temp = NULL;
        Node* ptr = head;
  
        while(ptr != NULL){

            if(ptr->key == k){
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

};

//cout<< ""<< endl;
int main()
{
    int op, key, data;

    Singly_linked_list s;

    do{
        
        cout<<"\nWhat operations to perfom? Press 0 to exit.\n";
        cout<<"1. Append a new node()."<<endl;
        cout<<"2. Preppend a new node()."<<endl;
        cout<<"3. Insert a new node after()."<<endl;
        cout<<"4. Delete a node()."<<endl;
        cout<<"5. update a node()."<<endl;
        cout<<"6. Print()."<<endl;
        cout<<"7. Clear Screen\n"<<endl;
        
        Node* n = new Node();
        cin>>op;

        switch(op){
            case 0:
                break;
            case 1:
                cout<<"Input the key__Value: ";
                cin>> n->key;
                cin>> n->data;
                s.append_node(n);
                break;
            case 2:
                cout<<"Input the key__Value: ";
                cin>> n->key;
                cin>> n->data;
                s.preppend(n);

                break;
            case 3:
                cout<<"Input the key__Value: ";
                cin>> n->key;
                cin>> n->data;
                cout<<"Insert after : ";
                cin>> key;
                s.insert_node(key, n);
                break;
            case 4:
                cout<<"Input the key to delete: ";
                cin>> key;
                s.delete_node(key);
                break;
            case 5:
            cout<<"Input the key__Value to update: ";
                cin>> key;
                cin>> data;
                s.update_node(key, data);
                break;
            case 6:
                s.print();
                break;
            case 7:
                system("clear");
                break;
        }

    }while(op != 0);

    return 0;
}