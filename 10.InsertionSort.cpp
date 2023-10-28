#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int> &v){  
    int size=v.size();  
    for (int i = 1; i < size; i++)  
    {    
        int j=i-1;    
        int curr=v[i];    
        while(j>=0 && v[j]>curr){      
            v[j+1]=v[j];      
            j--;    
        }    
        v[j+1]=curr;  
    }  
}
int main(){  
    int n;  
    cin>>n;  
    vector<int> v(n);  
    for (int i = 0; i < n; i++)  
    {    
        cin>>v[i];  
    }  
    insertionsort(v);  
    for (int i = 0; i < n; i++)  
    {    
        cout<<v[i]<<" ";  
    } 
    cout<<endl;     
    return 0;
}