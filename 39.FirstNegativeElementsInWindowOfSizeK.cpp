#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//first negative in sliding window of size K;
vector<int> Helper(int v[],int k,int s){
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        /* code */
        if(dq.empty() || v[i]>dq.back()){
            dq.push_back(v[i]);
        }
        else{
            while(!dq.empty() && v[i]<dq.back()){
                dq.pop_back();
            }
            dq.push_back(v[i]);
        }
    }
    ans.push_back(dq.front());
    for (int i = k; i < s; i++)
    {
        /* code */
        if (dq.front()==v[i-k])
        {
            /* code */
            dq.pop_front();
        }
        if(dq.empty() || v[i]>dq.back()){
            dq.push_back(v[i]);
        }
        else{
            while(!dq.empty() && v[i]<dq.back()){
                dq.pop_back();
            }
            dq.push_back(v[i]);
        }
        ans.push_back(dq.front());
    }
    return ans;
}
int main()
{
	int v[9]={1,2,-1,4,5,-6,7,8,-2};
	vector<int> final=Helper(v,3,9);
	cout<<"First negative elements in windows of size 3 in the array is: ";
	for (int i = 0; i < final.size(); i++)
	{
		/* code */
		if(final[i]>=0){
			cout<<"INT_MIN"<<"  ";
			continue;
                }
		cout<<final[i]<<"  ";
	}
	cout<<endl;
   return 0;
}
