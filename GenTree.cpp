#include<iostream>
#include<string>
using namespace std;

struct Node{
    string data;
    int childCount;
    Node* children[10];
    // Constructor to inialize
    Node(string value){
        data=value;
        childCount=0;
        for(int i=0;i<10;++i){
            children[i]=nullptr;
        }
    }
};

void addChild(Node* parent,const string& childData){
    if(parent->childCount < 10 ){
        parent->children[parent->childCount]=new Node(childData);
        parent->childCount++;
    }
    else{
        cout<<"Maximum Size reached for children\n";
    }
}

void constructTree(Node* parent){
    int numChildren;
    cout<<"Enter Number of Children \n";
    cin>>numChildren;
    cin.ignore();
    if(numChildren >10){
        cout<<"Error : Limit reached Adjusting to 10\n";
        numChildren=10;
    }
    for(int i=0;i<numChildren;++i){
        string childData;
        cout<<"Enter name of child " << i+1 <<"of "<< parent->data << " ";
        getline(cin,childData);
        addChild(parent, childData);
        constructTree(parent->children[parent->childCount-1]);
    }
}

void printTree(Node* parent , int level=0){
    if(!parent) return;
    for(int i=0;i<level;++i){

        cout<<" "<<"\n";
    }
    cout<<parent->data;
    for(int i=0;i<parent->childCount;++i){
        printTree(parent->children[i],level+1);
    }
}
int main(){
    string parentData;
    cout<<"Enter Name of Book(Head)\n";
    getline(cin,parentData);
    Node* parent =new Node(parentData);
    constructTree(parent);
    cout<<"Book Structure:\n";
    printTree(parent);
}