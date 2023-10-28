#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        prev=NULL;
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
Node* KfromEnd(Node* head,int N){
    Node* slow=head;
    Node* fast=head;
    while(N--){
        fast=fast->next;
    }
    if(fast==NULL)return head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->next;
}

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
    Node* a=new Node(1);
    insertAtEnd(a,2);
    insertAtEnd(a,3);
    insertAtEnd(a,4);
    insertAtEnd(a,5);
    insertAtEnd(a,6);
    insertAtEnd(a,7);
    display(a);
    cout<<"Nth Node from end is: ";
    Node* ans=KfromEnd(a,2);
    cout<<ans->val<<endl;
}