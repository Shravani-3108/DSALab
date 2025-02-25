#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    
    node(int value){
        data=value;
        left=right=nullptr;
    }
};
// insert new node
node* insert(node *root,int value){
    if(root==nullptr){
        return new node(value);
    }

    if(value < root->data){
        root->left=insert(root->left,value);
    }
    else if(value > root->data){
        root->right=insert(root->right,value);
    }

    return root;
}
// find longestpath
int findheight(node *root){
    if(root==nullptr){
        return 0;
    }

    int leftheight=findheight(root->left);
    int rightheight=findheight(root->right);

    return max(leftheight , rightheight) + 1;
}
// minimum value-minimum value will be last node at our left side tree so traverse left part of tree to get it

int findmin(node *root){
    if(root==nullptr){
        return -1;
    }

    while(root->left != nullptr){
        root=root->left;
    }

    return root->data;
}

void mirrortree(node *root){
    if(root==nullptr){
        return;
    }
    swap(root->left , root->right);

    mirrortree(root->left);
    mirrortree(root->right);
}

bool search(node *root , int key){
    if(root==nullptr) return false ;
    if(root->data==key) return true;
    if(key < root->data) return search(root->left , key);
    return search(root->right , key);
}

void inorder(node *root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" "<<endl;
    inorder(root->right);
}

int main(){
    node *root =nullptr;
    int choice , value;
    do{
        cout << "\n===== Binary Search Tree Menu =====\n";
        cout << "1. Insert a node\n";
        cout << "2. Display (Inorder Traversal)\n";
        cout << "3. Find height of the tree\n";
        cout << "4. Find minimum value in the tree\n";
        cout << "5. Mirror the tree\n";
        cout << "6. Search for a value\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1 :
                cout<<"Enter value to insert \n";
                cin>>value;
                root=insert(root,value);
                cout<<"value inserted";
                break;
            case 2 :
            if(root==nullptr){
                cout<<"Tree is empty";
            }
                cout<<"Inorder Traversal \n";
                inorder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"The height of tree is : \n";
                cout<<findheight(root);
                cout<<endl;
                break;
            case 4:
                cout<<"The minimum value in tree : \n";
                cout<<findmin(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Mirrored Tree is in inorder is as follows: \n";
                mirrortree(root);
                cout<<endl;
                inorder(root);
                cout<<endl;
                break;
            case 6:
                int key;
                cout<< "Enter Value \n";
                cin>>key;
                cout<< (search(root,key) ? "Value found in tree"  : "Value not found in tree")<<endl;
                break;
            default:
                cout<<"Entered Invalid choice";
                break;
        }
    }while(choice!=7);
    return 0;
}