#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nge(vector<int> &arr){
  int n=arr.size();
  vector<int> output(n,-1);
  stack<int> st;
  st.push(0);
  for (int i = 0; i < n; i++)
  {
    while(!st.empty()&& arr[i]>arr[st.top()])
    {
      output[st.top()]=arr[i];
      st.pop();
    }
    st.push(i); 
  }
  //for safety check
  while(not st.top()){
    output[st.top()]=-1;
    st.pop();
  }
  return output; 
}
vector<int> nger(vector<int> &arr){
    reverse(arr.begin(),arr.end());
  int n=arr.size();
  vector<int> output(n,-1);
  stack<int> st;
  st.push(0);
  for (int i = 0; i < n; i++)
  {
    while(!st.empty()&& arr[i]>arr[st.top()])
    {
      output[st.top()]=arr[i];
      st.pop();
    }
    st.push(i); 
  }
  //for safety check
  while(not st.top()){
    output[st.top()]=-1;
    st.pop();
  }
  reverse(output.begin(),output.end());
  return output; 
}
//next smaller element
vector<int> nse(vector<int> &arr){
  int n=arr.size();
  vector<int> output(n,-1);
  stack<int> st;
  st.push(0);
  for (int i = 0; i < n; i++)
  {
    while(!st.empty()&& arr[i]<arr[st.top()])
    {
      output[st.top()]=arr[i];
      st.pop();
    }
    st.push(i); 
  }
  //for safety check
  while(not st.top()){
    output[st.top()]=-1;
    st.pop();
  }
  return output; 
}
vector<int> nser(vector<int> &arr){
    reverse(arr.begin(),arr.end());
  int n=arr.size();
  vector<int> output(n,-1);
  stack<int> st;
  st.push(0);
  for (int i = 0; i < n; i++)
  {
    while(!st.empty()&& arr[i]<arr[st.top()])
    {
      output[st.top()]=arr[i];
      st.pop();
    }
    st.push(i); 
  }
  //for safety check
  while(not st.top()){
    output[st.top()]=-1;
    st.pop();
  }
  reverse(output.begin(),output.end());
  return output; 
}
int main(){
  int n;
  cin>>n;
  vector<int> v;
  while(n--){
    int x;
    cin>>x;
    v.push_back(x);
  }
  cout<<"NGE is: ";
  vector<int> resultnge=nge(v);
  for (int i = 0; i < resultnge.size(); i++)
  {
    cout<<resultnge[i]<<" ";
  }
  cout<<endl;
  cout<<"NSE is: ";
  vector<int> resultnse=nse(v);
  for (int i = 0; i < resultnse.size(); i++)
  {
    cout<<resultnse[i]<<" ";
  }
  cout<<endl;
  cout<<"PGE is: ";
  vector<int> resultnger=nger(v);
  for (int i = 0; i < resultnger.size(); i++)
  {
    cout<<resultnger[i]<<" ";
  }
  cout<<endl;
  cout<<"PSE is: ";
  vector<int> resultnser=nser(v);
  for (int i = 0; i < resultnser.size(); i++)
  {
    cout<<resultnser[i]<<" ";
  }
  cout<<endl;
  return 0;
}