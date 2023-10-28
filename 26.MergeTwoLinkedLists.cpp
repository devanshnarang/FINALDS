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


Node* Helper(Node* a,Node* b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    if(a->val<=b->val){
        a->next=Helper(a->next,b);
        return a;
    }
    else{
        b->next=Helper(a,b->next);
        return b;
    }
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
    insertAtEnd(a,3);
    insertAtEnd(a,5);
    display(a);
    cout<<endl;
    Node* b=new Node(2);
    insertAtEnd(b,2);
    insertAtEnd(b,4);
    insertAtEnd(b,6);
    display(b);
    cout<<endl;
    cout<<"After merging ";
    Node* afterMerged=Helper(a,b);
    display(afterMerged);
    cout<<endl;
}