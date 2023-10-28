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
    void deleteAtStart(Node* &head){
        head=head->next;
        return;
    }
    void deleteAtEnd(Node* head){
        if(head==NULL || head->next==NULL){
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
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
    deleteAtStart(newroot);
    display(newroot);
    deleteAtStart(newroot);
    display(newroot);
}