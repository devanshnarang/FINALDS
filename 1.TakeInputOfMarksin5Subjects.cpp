#include<iostream>
using namespace std;
int main()
{
    int arr[3][7];
    for (int i = 0; i < 3; i++)
    {
        /* code */
        int sum=0;
        for (int j = 0; j < 5; j++)
        {
            /* code */
            cin>>arr[i][j];
            sum+=arr[i][j];
        } 
        arr[i][5]=sum;
        arr[i][6]=sum/5;
    }   
    cout<<"Total and Average marks are: "<<endl;
    cout<<"Student 1:  "<<arr[0][5]<<"   "<<arr[0][6]<<endl;  
    cout<<"Student 2:  "<<arr[1][5]<<"   "<<arr[1][6]<<endl;
    cout<<"Student 3:  "<<arr[2][5]<<"   "<<arr[2][6]<<endl;  
    return 0;
}