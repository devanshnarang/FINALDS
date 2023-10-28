#include<iostream>
using namespace std;
class Queue{
    int front;
    int back;
    vector<int> v;
    public:
    Queue(){
        this->front=-1;
        this->back=-1;
    }
        void enqueue(int data){
            v.push_back(data);
            this->back++;
            if (this->back==0)
            {
                this->front++;
            }
			return;
        }
        void dequeue(){
            if (this->front==this->back)
            {
                this->front=-1;
                this->back=-1;
                this->v.clear();
            }else{
                this->front++;
            } 
        }
        int frontele(){
            if (this->front==-1)
            {
                return -1;
            }
            return v[this->front];
        }
        bool isEmpty(){
            return this->front==-1;
        }
		int getSize(){
			return this->back-this->front+1;
		}
};

int main()
{
	Queue qu;
	qu.enqueue(1);
	qu.enqueue(2);
	qu.enqueue(3);
	qu.enqueue(4);
	qu.enqueue(5);
	qu.enqueue(6);
	qu.dequeue();
	int si=qu.getSize();
	cout<<"Size of queue is: "<<si<<endl;
	int fr=qu.frontele();
	cout<<"Front element of Queue is: "<<fr<<endl;
	bool iE=qu.isEmpty();
	cout<<"Is the Queue empty? "<<iE<<endl;
   return 0;
}