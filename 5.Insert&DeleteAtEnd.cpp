#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>arr[i];
    }
    cout<<"Enter element: ";
    int e;
    cin>>e;
    arr[n]=e;
    cout<<"After INSERTION array is: ";
    for (int i = 0; i <= n; i++)
    {
        /* code */
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
    cout<<"After DELETION array is: ";
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
   return 0;
}