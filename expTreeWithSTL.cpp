/*Construct an expressiontree from the given prefix expression 
for example +--a*bc/def and traverse it using postorder traversal non recursive and then delete the entire tree*/

#include<iostream>
#include<stack>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;

    Node(char val){
        data=val;
        left=right=nullptr;
    }
};

Node* createTree(string exp){
    stack<Node*> st;
    
    for(int i= exp.length()-1 ; i>=0 ;i--){
        char ch = exp[i];
        Node *newNode =new Node(ch);

        if(isalnum(ch)){
            st.push(newNode);
        }
        else{
            newNode->left = st.top();st.pop();
            newNode ->right=st.top();st.pop();
            st.push(newNode);
        }
    }
    return st.top();
}

void postOrder_nonRec(Node *root){
    if(!root) return;

    stack<Node *> s1,s2;
    Node *curr = nullptr;
    s1.push(root);
    while(!s1.empty()){
        curr=s1.top();
        s1.pop();
        s2.push(curr);
        if(curr-> left != NULL){
            s1.push(curr->left);
        }
        if(curr->right != NULL){
            s1.push(curr->right);
        }
    }

    while(!s2.empty()){
        curr=s2.top();
        cout<< curr->data <<" ";
        s2.pop();
    }
}

void deleteTree(Node *root){
    if(!root) return ;

    stack<Node*>s1;
    s1.push(root);

    while(!s1.empty()){
        Node *curr=s1.top();
        s1.pop();

        if(curr->left) s1.push(curr->left);
        if(curr->right) s1.push(curr->right);

        delete curr;
    }

    root=nullptr;
}

int main(){
    string prefix;
    cout<<"Enter Expression"<<endl;
    cin>>prefix;

    Node *root=createTree(prefix);

    cout<<"Postorder Traversal"<<endl;
    postOrder_nonRec(root);

    deleteTree(root);
    cout<<"\nTree is deleted successfully\n";
    cout<<endl;
}