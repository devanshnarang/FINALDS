#include<iostream>
using namespace std;
class Node{
  public:
  int val;
  Node* next;
  Node(int data){
    this->val=data;
    this->next=NULL;
  } 
};
class Queue{
  Node* head;
  Node* tail;
  int size;
  public:
  Queue(){
    this->head=NULL;
    this->tail=NULL;
	size=0;
  }
  void enqueue(int data){
    Node* newNode=new Node(data);
    if (this->head==NULL)
    {
    this->head=newNode;
    this->tail=newNode;
    }else{
      this->tail->next=newNode;
      this->tail=newNode;
    }  
    this->size++;
  }
  void dequeue(){
    if (this->head==NULL)
    {
      return;
    }else{
      Node* oldHead=this->head;
      Node* newHead=this->head->next;
      this->head=newHead;
      if (this->head==NULL)
      {
        this->tail=NULL;
      }
      oldHead->next=NULL;
	  cout<<"Pop out element is: "<<oldHead->val;
      delete oldHead;
      this->size--;
    } 
  }
  int getSize(){
    return this->size;
  }
  bool isEmpty(){
    return this->head==NULL;
  }
  int front(){
    if (this->head==NULL)
    {
      return -1;
    }
	return this->head->val;    
  }
};
int main(){
	Queue qu;
	qu.enqueue(1);
	qu.enqueue(2);
	qu.enqueue(3);
	qu.enqueue(4);
	qu.enqueue(5);
	qu.enqueue(6);
	qu.dequeue();
	int si=qu.getSize();
	cout<<"Size of queue is: "<<si<<endl;
	int fr=qu.front();
	cout<<"Front element of Queue is: "<<fr<<endl;
	bool iE=qu.isEmpty();
	cout<<"Is the Queue empty? "<<iE<<endl;
}