#include<iostream>
using namespace std;
class Node{
  public:
  int val;
  Node* next;
  Node(int data){
    val=data;
    next=NULL;
  }
};
class circularLinkedList{
  public:
  Node* head;
  circularLinkedList(){
    head=NULL;
  }
  void insertAtStart(int val){
    Node* new_node=new Node(val);
    if (head==NULL)
    {
      head=new_node;
      new_node->next=head;
//circular ll
      return;
    }
    Node* tail=head;
    while (tail->next!=head)
    {
      tail=tail->next;
    }
    
//tail is pointing to last node
    tail->next=new_node;
    new_node->next=head;
    head=new_node;    
  }
  void insertAtEnd(int val){
    Node* new_node=new Node(val);
    if (head==NULL)
    {
      head=new_node;
      new_node->next=head;
    }
    Node* temp=head;
    while (temp->next!=head)
    {
      temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;        
  }
  void printCircular(){
    Node* temp=head;
    for (int i = 0; i < 9; i++)
    {
      cout<<temp->val<<"->";
      temp=temp->next;
    }   
    cout<<endl; 
  }
  void deleteAtStart(){
    if (head==NULL)    {
      return;
    }
    Node* temp=head;
    Node* tail=head;
    while(tail->next!=head)
    {
      tail=tail->next;
    }
    head=head->next;
    tail->next=head;
    free(temp);  
  }
  void deleteAtEnd(){
    if (head==NULL)
    {
      return;
    }
    Node* tail=head;
    while (tail->next->next!=head)     {
      tail=tail->next;
    }
    Node* temp=tail->next;
    tail->next=head;
    free(temp);        
} 
}; 

int main(){
  circularLinkedList cll;
  cll.insertAtStart(3);
  cll.insertAtStart(2);
  cll.insertAtStart(1);
  cll.insertAtEnd(4);
  cll.printCircular();
  cll.deleteAtStart();
  cout<<"After deletion: ";
  cll.deleteAtEnd();
  cll.printCircular();
  return 0;
}