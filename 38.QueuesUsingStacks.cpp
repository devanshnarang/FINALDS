#include<iostream>
#include<stack>
using namespace std;
//Implement Queue using Stacks
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()!=1){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st1.top();
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
        
    }
    
    int peek() {
        while(st1.size()!=1){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st1.top();
        //st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st1.empty();
    }
};
int main()
{
	MyQueue qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	cout<<"Peek Element is: "<<qu.peek()<<endl;
	qu.pop();
	cout<<"Peek Element is: "<<qu.peek()<<endl;
   return 0;
}