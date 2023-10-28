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
//Insert At K
void insertAtK(Node* &head,int x,int k){
    if(k==0){
        insertAtStart(head,x);
        return;
    }
    Node* ne=new Node(x);
    k-=1;
    Node* temp=head;
    while(k--){
        temp=temp->next;
    }
    ne->next=temp->next;
    temp->next=ne;
    return;
}
//Delete At K
void deleteAtK(Node* &head,int k){
    if(k==0){
        head=head->next;
        return;
    }
    k-=1;
    Node* temp=head;
    while(k--){
        temp=temp->next;
    }
    temp->next=temp->next->next;
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
    insertAtK(newroot,6,1);
    deleteAtK(newroot,1);
    display(newroot);
    display(newroot);
}