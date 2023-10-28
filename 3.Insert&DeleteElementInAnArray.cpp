#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	int i;
	for(i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int pos;
	cin >> pos;
	int ele;
	cin >> ele;
	if(pos > n){
		cout<<"Invalid";
	}
	else
	{
		for (i = n-1; i >= pos-1; i--)
		arr[i+1] = arr[i];
		arr[pos-1] = ele;
		cout <<"Array after insertion is:";
		for (i = 0; i <= n; i++){
			cout << arr[i] <<"  ";
		}
	}
    cout<<endl;
    //Deletion
    cout<<"Enter position to be deleted: ";
    int d;
    cin>>d;
    for (int i = d-1; i < n; i++)
    {
        /* code */
        swap(arr[i],arr[i+1]);
    }
    cout<<endl;
    n=n-1;
    cout <<"Array after deletion is:";
	for (i = 0; i <= n; i++){
		cout << arr[i] <<"  ";
    }
	return 0;
}