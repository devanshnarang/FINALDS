#include<iostream>
#include<stack>
using namespace std;
//Minimum element in stack in constant space
int ME(stack<int> st){
    int ans=INT_MAX;
    while(!st.empty()){
        ans=min(ans,st.top());
        st.pop();
    }
    return ans;
}
int main()
{
	stack<int> st;
	st.push(4);
	st.push(1);
	st.push(34);
	st.push(109);
	st.push(412);
	st.push(23);
	st.push(345);
	st.push(6);
	cout<<"Minimum Element in stack is: "<<ME(st)<<endl;
   return 0;
}