#include<iostream>
using namespace std;
void heapify(int arr[],int n,int curr){
    while ((2*curr+1)<=n)
    {
        /* code */
        int leftchild=2*curr+1;
        int rightchild=2*curr+2;
        int maxchild=leftchild;
        if (rightchild<=n && arr[rightchild]>arr[maxchild])
        {
            /* code */
            maxchild=rightchild;
        }
        if (arr[maxchild]<arr[curr])
        {
            /* code */
            return;
        }
        swap(arr[maxchild],arr[curr]);
        curr=maxchild;
    } 
}
void remove(int arr[],int &size){
    swap(arr[0],arr[size]);
    size--;
    heapify(arr,size,0);
}
void heapSort(int arr[],int n){
    //1.heapify
    for (int i = n/2-1; i >= 0; i--)
    {
        /* code */
        heapify(arr,n,i);
    }
    //keep deleting elements from max heap until size becomes 0
    while(n>0){
        remove(arr,n);
    }
}
int main()
{
    int arr[6]={3,-1,0,2,-9,10};
    cout<<"Array is: ";
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    heapSort(arr,6);
    cout<<"After Sorting Array is: ";
    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   return 0;
}