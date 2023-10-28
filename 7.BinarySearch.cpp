#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &input,int target){  
	int lo=0;  
	int hi=input.size()-1;  
	while (lo<=hi)
	{        
		int mid=(hi+lo)/2;    
		if (input[mid]==target)    
		{      
			return mid;    
        }    
		else if (input[mid]<target)    
		{      
			lo=mid+1;    
		}    
		else{      
            hi=mid-1;    
			}  
	}  
    return -1;  
}
int main()
{
	vector<int> input;
	input.push_back(1);
	input.push_back(23);
	input.push_back(34);
	input.push_back(45);
	input.push_back(67);
	input.push_back(100);
	input.push_back(134);
	cout<<"Searching for 100: ";
	cout<<"Found or Not? "<<binarysearch(input,100)<<endl;
	cout<<"Searching for 200: ";
	cout<<"Found or Not? "<<binarysearch(input,200)<<endl;
   return 0;
}