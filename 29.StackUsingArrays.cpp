#include<iostream>
using namespace std;
class Stack{ 
    int capacity;
    int* arr; 
    int top; 
    public:
    Stack(int c){ 
        this->capacity=c; 
        arr=new int[c]; 
        this->top=-1;
	} 
    void push(int data){
        if(this->top==this->capacity-1){
            cout<<"Overflow"<<endl; 
            return ; 
		} 
        this->top++; 
        this->arr[this->top]=data; 
    } 
    int pop(){ 
        if(this->top==-1){ 
            cout<<"underflow";
            return -1; 
        } 
		int x=this->arr[this->top];
        this->top--; 
		return x;
    } 
    int getTop(){ 
        if (this->top==-1) 
        {
            cout<<"Underflow";
            return INT_MIN; 
        } 
        return this->arr[this->top]; 
    } 
    bool isEmpty(){ 
        return this->top==-1; 
    } 
    int size(){ 
        return this->top + 1; 
    } 
    bool isFull(){ 
        return this->top==this->capacity-1; 
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
