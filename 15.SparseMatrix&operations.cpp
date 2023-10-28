#include<iostream>
using namespace std;
class sparse_matrix{
    int max;
    int **data;
    int row,col;
    int len;
    public:
    sparse_matrix(int r,int c,int m){
        max=m;
        row=r;
        col=c;
        len=0;
        data=new int *[max];
        for (int i = 0; i < max; i++)
        {
            /* code */
            data[i]=new int[3];
        }   
    }
    void insert(int r,int c,int val){
        if(r>row || c>col){
            cout<<"Wrong entry"<<endl;
        }
        else{
            data[len][0]=r;
            data[len][1]=c;
            data[len][2]=val;
            len++;
        }
    }
    void add(sparse_matrix b){
        if (row!=b.row || col!=b.col)
        {
            /* code */
            cout<<"Can't be added!"<<endl;
        }
        else{
            sparse_matrix sum(row,col,len+b.len);
            int i=0;
            int j=0;
            while (i<len && j<b.len)
            {
                /* code */
                if (data[i][0]==b.data[j][0] && data[i][1]==b.data[j][1])
                {
                    /* code */
                    sum.insert(data[i][0],data[i][1],data[i][2]+b.data[j][2]);
                    i++;
                    j++;
                }
                else if (data[i][0]<b.data[j][0] || (data[i][0]==b.data[j][0] && data[i][1]<b.data[j][1]))
                {
                    /* code */
                    sum.insert(data[i][0],data[i][1],data[i][2]);
                    i++;
                }
                else{
                    sum.insert(b.data[j][0],b.data[j][1],b.data[j][2]);
                    j++;  
                }      
            }
            while (i<len)
            {
                /* code */
                sum.insert(data[i][0],data[i][1],data[i][2]);
                i++;  
            }
            while(j<b.len){
                sum.insert(b.data[j][0],b.data[j][1],b.data[j][2]);
                j++;   
            } 
            sum.print();
        }
    }
    sparse_matrix transpose(){
        sparse_matrix result(col,row,len);
        int* count=new int[col+1];
        for (int i = 1; i <=col; i++)
        {
            /* code */
            count[i]=0;
        }
        for (int i = 0; i < len; i++)
        {
            /* code */
            count[data[i][1]]++;
        }
        int *index=new int[col+1];
        index[0]=0;
        for (int i = 1; i <= col; i++)
        {
            /* code */
            index[i]=index[i-1]+count[i-1];
        }
        for (int i = 0; i < len; i++)
        {
            /* code */
            int rpos=index[data[i][1]]++;
            result.data[rpos][0]=data[i][1];
            result.data[rpos][1]=data[i][0];
            result.data[rpos][2]=data[i][2];
            result.len++;
        }
        return result;
    }
    void print(){
        cout<<"row"<<"\t"<<"col"<<"\t"<<"value"<<endl;
        for (int i = 0; i < len; i++)
        {
            /* code */
            cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<endl;
        }
        return;
    }

};
int main()
{
    sparse_matrix a(3,3,3);
    a.insert(1,1,2);
    a.insert(2,2,2);
    a.insert(3,1,2);
    a.print();
    //cout<<"LO";
    sparse_matrix b(3,3,3);
    b.insert(1,1,2);
    b.insert(1,3,2);
    b.insert(2,3,2);
    //b.print();
    //a.add(b);
    //cout<<"HI";
    sparse_matrix trans=a.transpose();
    //cout<<"HI";
    trans.print();
   return 0;
}