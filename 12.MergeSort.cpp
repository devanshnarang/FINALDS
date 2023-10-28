#include<iostream>
using namespace std;
void merge(int arr[],int l,int r,int mid){  
    //create two temporary arrays  
    int an=mid-l+1;  
    int bn=r-mid;  
    int a[an];  
    int b[bn];  
    for (int i = 0; i < an; i++)  
    {    
        a[i]=arr[l+i];  
    }  
    for (int i = 0; i < bn; i++)  
    {    
        b[i]=arr[mid+1+i];  
    }  
    int i=0;  
    int j=0;  
    int k=l;     
    while(i<an && j<bn){        
        if (a[i]<b[j])    
        {      
            arr[k++]=a[i++];          
        }    
        else{      
            arr[k++]=b[j++];    
        }     
    }  
    while(i<an){    
        arr[k++]=a[i++];      
    }  
    while(j<bn){    
        arr[k++]=b[j++];     
        }  
        cout<<endl;  
    return;  
}
void mergesort(int arr[],int l,int r){  
    if(l>=r){    
        return;  
    }  
    int mid=(l+r)/2;  
 
    mergesort(arr,l,mid);  
    mergesort(arr,mid+1,r);  
    merge(arr,l,r,mid);  
    return;  
}
int main(){  
    int n;  
    cin>>n;  
    int arr[n];  
    for (int i = 0; i < n; i++)  
    {    
        cin>>arr[i];  
    }  
    int l=0;  
    int r=n-1;  
    mergesort(arr,l,r);  
    for (int i = 0; i < n; i++)  
    {    
        cout<<arr[i]<<" ";  
    }      
    return 0;
}