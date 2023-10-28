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
//Display
void display(Node* &head){
    cout<<"Linked List is: ";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
void mergerpoint(Node* &nw,Node* &c){
    Node* temp=nw;
    while(temp!=NULL && temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=c;
    return;
}
Node* Finder(Node* &newroot,Node* &newroot2){
    int  l1=0;
    Node* temp=newroot;
    while(temp!=NULL){
        temp=temp->next;
        l1++;
    }
    int l2=0;
    Node* temp2=newroot2;
    while(temp2!=NULL){
        temp2=temp2->next;
        l2++;
    } 
    temp=newroot;
    temp2=newroot2;
    if(l1>l2){
        int o=l1-l2;
        while(o--){
            temp=temp->next;
        }
    }
    else if(l2>l1){
        int o=l2-l1;
        while(o--){
            temp2=temp2->next;
        }
    }
    while(temp!=NULL && temp!=temp2){
        temp=temp->next;
        temp2=temp2->next;
    }
    return temp;
}
int main(){
    Node* newroot=new Node(2);
    insertAtStart(newroot,1);
    Node* merger=new Node(3);
    mergerpoint(newroot,merger);
    insertAtEnd(newroot,4);
    insertAtEnd(newroot,5);
    insertAtEnd(newroot,6);
    insertAtEnd(newroot,7);
    display(newroot);
    Node* newroot2=new Node(8);
    insertAtEnd(newroot2,9);
    insertAtEnd(newroot2,10);
    mergerpoint(newroot2,merger);
    display(newroot2);
    Node* final=Finder(newroot,newroot2);
    cout<<final->val<<endl;
}