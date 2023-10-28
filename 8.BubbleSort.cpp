#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &v){
int n=v.size();
    for (int i = 0; i < n-1; i++)
    {
        bool flag=false;
        for (int j = 0; j < n-1-i; j++)
        {
            if (v[j]>v[j+1])
            {
                flag=true;
                int temp=v[j+1];
                v[j+1]=v[j];
                v[j]=temp;
                }
        }
        if(!flag) break;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i]; 
    }
    bubblesort(v);
    cout<<"After sorting array is: ";
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    return 0;
}