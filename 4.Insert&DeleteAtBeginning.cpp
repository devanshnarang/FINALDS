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
    for (int i = n; i>=0; i--)
    {
        /* code */
        arr[i]=arr[i-1];

    }
    arr[0]=e;
    cout<<endl;
    cout<<"Array is: ";
    for (int i = 0; i <=n ; i++)
    {
        /* code */
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    //Delete at beginning
    for (int i = 0; i <n; i++)
    {
        /* code */
        arr[i]=arr[i+1];
    }
    cout<<"After delete at beginning: ";
    cout<<"Array is: ";
    for (int i = 0; i <n ; i++)
    {
        /* code */
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
   return 0;
}