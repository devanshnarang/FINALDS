#include<iostream>
using namespace std;
//Stack queues implementation using array and link list
class Node{ 
	public:
	int val; 
	Node* next;
	Node(int data){
		this->val=data;
		this->next=NULL;
		}
};
class Stack{
	Node* head;
	int capacity; 
	int currSize; 
	public:
	Stack(int c){ 
		this->capacity=c; 
		this->currSize=0;
		head=NULL; 
	}
	bool isEmpty(){
		return this->head==NULL;
	}
	bool isFull(){
		return this->currSize==this->capacity;
	}
	void push(int data){
		if (this->capacity==this->currSize) 
		{
			cout<<"Overflow";
			return;
		}
		Node* new_node=new Node(data);
		new_node->next=this->head; 
		this->head=new_node; 
		this->currSize++; 
	}
	int pop(){ 
		if (this->currSize==0)
		{
			cout<<"Underflow";
		    return -1;
		}
		Node* new_head=this->head->next;
		this->head->next=NULL;
		Node* tobeRemoved=this->head;
		int result=tobeRemoved->val;
		delete tobeRemoved;
		this->head=new_head;
		this->currSize--;
		return result;
	} 
	int getTop(){
		if (this->head==NULL) 
		{
			cout<<"Underflow";
			return -1;
		}
		return this->head->val;
		}
	int size(){
		return this->currSize;
	} 
};

int main()
{
	Stack st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	int popped=st.pop();
	cout<<"Element pop-out is: "<<popped<<endl;
	int top=st.getTop();
	cout<<"Top element is: "<<top<<endl;
	st.push(5);
	st.push(7);
	int s=st.size();
	cout<<"Size of stack is: "<<s<<endl;
	cout<<"Is Stack FULL? "<<st.isFull()<<endl;
	cout<<"Is Stack Empty? "<<st.isEmpty()<<endl;
   return 0;
}