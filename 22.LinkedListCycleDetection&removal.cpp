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
void insertAtStart(Node* &newroot,int x){
    Node* ne=new Node(x);
    if(newroot==NULL){
        newroot=ne;
        return ;
    }
    ne->next=newroot;
    newroot=ne;
}


//insert At End
void insertAtEnd(Node* &newroot,int x){
    Node* ne=new Node(x);
    if(newroot==NULL){
        newroot=ne;
        return ;
    }
    Node* temp=newroot;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ne;
    return;
}
//Insert At K
void insertAtK(Node* &newroot,int x,int k){
    if(k==0){
        insertAtStart(newroot,x);
        return;
    }
    Node* ne=new Node(x);
    k-=1;
    Node* temp=newroot;
    while(k--){
        temp=temp->next;
    }
    ne->next=temp->next;
    temp->next=ne;
    return;
}
//Display
void cyclePrinter(Node* &newroot){
    Node* temp=newroot;
    Node* slow=newroot->next;
    Node* fast=newroot->next->next;
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=newroot;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    int cnt=0;
    while(cnt!=2){
        cout<<temp->val<<" ";
        if(temp==slow){
            cnt++;
            if(cnt==2)break;
        }
        temp=temp->next;
    }
    cout<<endl;
    return;
}
Node* cycleFinder(Node* &newroot){
    Node* slow=newroot->next;
    Node* fast=newroot->next->next;
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=newroot;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
void Cylcer(Node* &newroot,int x){
    Node* temp=newroot;
    while(x--){
        temp=temp->next;
    }
    Node* temp2=newroot;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
}
void removeCycle(Node* &newroot){
   Node* slow=newroot->next;
    Node* fast=newroot->next->next;
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL){
            break;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    slow=newroot;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=newroot;
    int cnt=0;
    while(temp->next!=slow || cnt!=1){
        if(temp==slow)cnt++;
        temp=temp->next;
    }
    temp->next=NULL;
}
void display(Node* &newroot){
    Node* temp=newroot;
    while(temp!=NULL){
        cout<<temp->val<<"  ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}
int main(){
    Node* newroot=new Node(2);
    insertAtStart(newroot,1);
    insertAtEnd(newroot,3);
    insertAtEnd(newroot,4);
    insertAtEnd(newroot,5);
    insertAtEnd(newroot,6);
    insertAtEnd(newroot,7);
    Cylcer(newroot,2);
    cout<<"Circular Linked List is: ";
    cyclePrinter(newroot);
    Node* cycleans=cycleFinder(newroot);
    cout<<"Cycle is at Node with value : ";
    cout<<cycleans->val<<endl;
    cout<<"After removing cycle linked list is: ";
    removeCycle(newroot);
    display(newroot);
}