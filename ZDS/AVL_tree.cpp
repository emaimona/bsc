#include <iostream>
#define SPACE 10
using namespace std;

class TreeNode{

public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        data = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }

};

class AVL{
public:
    TreeNode* root;
    TreeNode* prev;
    bool found;

    AVL(){
        root = NULL;
        prev = NULL;
        found = 0;
    }

    AVL(TreeNode* node){
        root = node;
        prev = NULL;
        found = 0;
    }

    int getBalancefactor(TreeNode* node){
        if (node == NULL)
            return -1;
        return height(node->left) - height(node->right);
    }

    TreeNode* leftRotate(TreeNode* node){
        TreeNode* ptr = node->right;

        node->right = ptr->left;
        ptr->left = node;

        return ptr;
    }

    TreeNode* righttRotate(TreeNode* node){
        TreeNode* ptr = node->left;

        node->left = ptr->right;
        ptr->right = node;

        return ptr;
    }

    TreeNode* deleteNodeRecursively(TreeNode* node, int value){
        if (node == NULL)
            return node;
        else if (node->data > value)
            node->left = deleteNodeRecursively(node->left, value);
        else if (node->data < value)
            node->right = deleteNodeRecursively(node->right, value);
        else {
            if(node->left == NULL)
                return node->right;
            else if (node->right == NULL)
                return node->left;
            else{
                replaceTheRightestNullPointer(node->left, node->right);
                return node->left;
            }
        }

        int balancefactor = getBalancefactor(node);

        if (balancefactor == -2){
            balancefactor = getBalancefactor(node->right);
            if(balancefactor == 0 || balancefactor == -1)
                return leftRotate(node);
            else{
                node = leftRotate(node);
                return righttRotate(node);
            }
        }
        else {
            balancefactor = getBalancefactor(node->left);
            if(balancefactor == 0 || balancefactor == -1)
                return righttRotate(node);
            else{
                node = righttRotate(node);
                return leftRotate(node);
            }
        }

        return node;
    }

    TreeNode* insertNodeRecursively(TreeNode* node, TreeNode* new_node){
        if (node == NULL){
            node = new_node;
            return node;
        }
        else if (node->data < new_node->data)
            node->right = insertNodeRecursively(node->right, new_node);
        else if (node->data > new_node->data)
            node->left = insertNodeRecursively(node->left, new_node);
        else{
            cout<< "Node already exist, try another..."<< endl;        
            return node;
        }

        int balancefactor = getBalancefactor(node);

        if (balancefactor > 1 && new_node->data < node->data)
            return righttRotate(node);
        else if (balancefactor < -1 && new_node->data > node->data)
            return leftRotate(node);
        else if (balancefactor > 1 && new_node->data > node->data){
            node = leftRotate(node);
            return righttRotate(node);
        }
        else if (balancefactor < -1 && new_node->data < node->data){
            node = righttRotate(node);
            return leftRotate(node);
        }

        return node;
    }

    

    void insertNodeRecursively3(TreeNode** starting_node, TreeNode* node){
        if((*starting_node) == NULL){
            (*starting_node) = node;
            cout<<"Node <"<< (*starting_node)->data <<"> inserted."<<endl;
        }
        else if((*starting_node)->data == node->data)
            cout<<"This node already exists, insert another node.";
        else if ((*starting_node)->data > node->data)
            insertNodeRecursively3(&((*starting_node)->left), node);
        else
            insertNodeRecursively3(&((*starting_node)->right), node);
        
    }


    void replaceTheRightestNullPointer(TreeNode* ptr, TreeNode* new_ptr){
        TreeNode* temp = ptr;

        while(temp != NULL){
            if (temp->right == NULL){
                temp->right = new_ptr; 
                break;
            }
            temp = temp->right;
        }
    }

    void deleteNode(int value){
        TreeNode* ptr = iteractivesearch(value);

        if (is_empty())
            cout<< "The tree is empty..";
        else if (ptr == NULL)
            cout<< "There is no such node.";
        else{
            if (root == ptr){
                if (root->left == NULL)
                    root = root->right;
                else{
                    TreeNode* temp = root->left;
                    replaceTheRightestNullPointer(temp, root->right);
                    root =  root->left;   
                }
            }
            else{
                if (prev->left == ptr){
                    prev->left = ptr->left;
                    replaceTheRightestNullPointer(ptr->left, ptr->right);                
                }
                else {
                    prev->right = ptr->left;
                    replaceTheRightestNullPointer(ptr->left, ptr->right);
                }
            }
            
            cout<<"Node <"<< value <<"> deleted."<<endl;
        }
    }

    void printGivenLevel(TreeNode* node, int level){
        if(node == NULL)
            return;

        if (level == 0)
            cout<< node->data <<" ";
        else{
            printGivenLevel(node->left, level - 1);
            printGivenLevel(node->right, level - 1);
        }
    }

    void printLevelOrderBFS(TreeNode* node){
        int h = height(node);

        for(int i = 0; i <= h; i++){
            printGivenLevel(node, i); 
            cout<<endl;
        }
    }

    /* To be put to work, 
        Breadth search print
        print by level using recursion
     */

    /* void maby(TreeNode* node1, TreeNode* node2){
        if (node1 == NULL || node2 == NULL)
            return;
        cout<< node1->data;
        cout<< node2->data;

    }

    void myPrint(TreeNode* node){
        TreeNode* ptr = node;
        if(ptr == NULL)
            return;

        maby(ptr->left, ptr->right);
        myPrint(ptr->right);
        myPrint(ptr->left);

        cout<<endl;
    } */

    int height(TreeNode* node){
        if (node == NULL)
            return -1;
        else{
            int leftheight = height(node->left);
            int rightheight = height(node->right);
            
            if (leftheight > rightheight)
                return leftheight + 1;
            else
                return rightheight + 1;
        }
    }

    void recursivesearch(TreeNode* node, int value){
        if(node == NULL)
            return;

        if (node->data == value)
            found = 1;
        recursivesearch(node->left, value);
        recursivesearch(node->right, value);
    }

    TreeNode* iteractivesearch(int value){
        if (root == NULL)
            return NULL;
        else{
            TreeNode* ptr = root;
            prev = NULL;

            while(ptr != NULL){

                if (ptr->data == value){
                    return ptr;
                }
                else if (ptr->data < value){
                    prev = ptr;
                    ptr = ptr->right;
                }
                else{
                    prev = ptr;
                    ptr = ptr->left;

                }
            }
        }
        return NULL;
    }

    void search(int value){
        if (root == NULL)
            cout<<"The Binary search tree is empty."<< endl;
        else{
            TreeNode* ptr = root;
            int level = 0;

            while(ptr != NULL){
                if (ptr->data == value){
                    cout<< "Found at level "<< level;
                    return;
                }
                else if (ptr->data < value)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
                level++;
            }
            cout<< "Value not found.";
            return;
        }
    }

    void print2D(TreeNode* node, int space){
        if (node == NULL)
            return;

        space += SPACE;
        print2D(node->right, space);
        cout<<endl;
        for (int i = SPACE; i < space; i++)
            cout<<" ";
        cout<< node->data <<endl;

        print2D(node->left, space);
    }

    void printPreOrder(TreeNode* node){
        if (node == NULL)
            return;
        cout<<" <"<< node->data <<">";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }

    void printInOrder(TreeNode* node){
        if (node == NULL)
            return;
        printInOrder(node->left);
        cout<<" <"<< node->data <<">";
        printInOrder(node->right);
    }

    void printPostOrder(TreeNode* node){
        if (node == NULL)
            return;
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout<<" <"<< node->data <<">";
    }

    void insertNode(TreeNode* node){
        if(is_empty()){
            root = node;
            cout<<"Node <"<< root->data <<"> inserted as root node."<<endl;
        }
        else{
            TreeNode* ptr = root;

            while(ptr != NULL){
                if(ptr->data == node->data){
                    cout<<"Node already exists, insert another value."<<endl;
                    return;
                }
                else if(ptr->data > node->data){
                    if(ptr->left == NULL){
                        ptr->left = node;
                        cout<<"Node <"<< ptr->left->data <<"> inserted at left"<<endl;
                        return;
                    }else
                        ptr = ptr->left;
                } else{
                    if(ptr->right == NULL){
                        ptr->right = node;
                        cout<<"Node <"<< ptr->right->data <<"> inserted at right"<<endl;
                        return;
                    }else
                        ptr = ptr->right;
                }
            }
        }
    }

    bool is_empty(){
        if(root == NULL)
            return true;
        return false;
    }
};

int main(){
    AVL bst;
    int value, option;

  /*   system("clear"); */

    do{
        cout<<"\nWhat operations to  perfom? Press 0 to exit.\n";
        cout<<"1. Insert a node()."<<endl;
        cout<<"2. Search a node()."<<endl;
        cout<<"3. Delete a node()."<<endl;
        cout<<"4. Print values."<<endl;
        cout<<"5. Height of the tree."<<endl;
        cout<<"8. Clear Screen\n"<<endl;

        cin>>option;

        TreeNode* node = new TreeNode();

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Input the value of the node: ";
                cin>> node->data;
                bst.root = bst.insertNodeRecursively(bst.root, node);
                break;
            case 2:
                cout<<"Input the value of the node: ";
                cin>> value;
                cout<< ((bst.iteractivesearch(value) == NULL)? "Not found": "Found")<<endl;
                break;
            case 3:
                cout<<"Input the value of the node: ";
                cin>> value;
                bst.deleteNode(value);
                break;
            case 4:
                bst.print2D(bst.root, 5);
                cout<<endl;
                bst.printPreOrder(bst.root);
                cout<<endl;
                bst.printInOrder(bst.root);
                cout<<endl;
                bst.printPostOrder(bst.root);
                cout<<endl;
                cout<<"Level order BFS"<<endl;
                bst.printLevelOrderBFS(bst.root);

                break;
            case 5:
                cout<<"The height of the tree is: "<< bst.height(bst.root);
                break;
            case 6:
                cout<<"Input the value of the node: ";
                cin>> value;
                bst.root = bst.deleteNodeRecursively(bst.root, value);
                break;
            case 8:
                system("clear");
                break;
        }

    }while(option != 0);

    return 0;
}