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
Node* Reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
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
    insertAtEnd(newroot,4);
    display(newroot);
    Node* reversed=Reverse(newroot);
    cout<<"After reversing ";
    display(reversed);
}