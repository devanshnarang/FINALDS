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
//Check if a link  is palindrome or not
   bool isPalindrome(Node* head) {
        Node* temp=new Node(head->val);
        Node* temp2=head->next;
        Node* orgh=temp;
        while(temp2!=NULL){
            temp->next=new Node(temp2->val);
            temp2=temp2->next;
            temp=temp->next;
        }
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        Node* newHead=prev;
        while(temp!=NULL){
            temp=temp->next;
        }
        while(orgh!=NULL){
            
            if(orgh->val!=newHead->val){
                return false;
            }
            orgh=orgh->next;
            newHead=newHead->next;
        }
        return true;
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
    bool check1=isPalindrome(a);
    string ans=check1?"YES":"NO";
    cout<<ans<<endl;
   Node* b=new Node(1);
    insertAtEnd(a,2);
    insertAtEnd(a,3);
    insertAtEnd(a,4);
    insertAtEnd(a,3);
    insertAtEnd(a,2);
    insertAtEnd(a,1);
    display(a);
    check1=isPalindrome(b);
    ans=check1?"YES":"NO";
    cout<<ans<<endl;
    cout<<endl;
}