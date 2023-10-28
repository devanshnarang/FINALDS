//Implement singly link list insertion deletion at start and end
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int x){
        val=x;
        next=NULL;
    }
};


//insert At Start
void insertAtStart(Node* &head,int x){
    Node* ne=new Node(x);
    if(head==NULL){
        head=ne;
        return ;
    }
    ne->next=head;
    head=ne;
}


//insert At End
void insertAtEnd(Node* &head,int x){
    Node* ne=new Node(x);
    if(head==NULL){
        head=ne;
        return ;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ne;
    return;
}


//Display
void display(Node* &head){
    cout<<"Linked List is: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* newroot=new Node(2);
    insertAtStart(newroot,1);
    insertAtEnd(newroot,3);
    display(newroot);
}