#include<iostream>
using namespace std;
int Helper(int ans[],int k,int n){
    for(int i=0;i<n;i++){
        if(ans[i]==k){
            return i;
        }
    }
    return -1;
}
int main()
{
	int ans[5]={2,3,45,6,7};
	cout<<Helper(ans,45,5)<<endl;
	cout<<Helper(ans,100,5)<<endl;
   return 0;
}