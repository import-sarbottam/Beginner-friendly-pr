#include<iostream>
using namespace std;
#define max 10
int queue[max];
int front=-1,rear=-1;
void store(int data);
void retrieve();

int main()
{
	int data,prompt=1;
	while(prompt!=0)
	{
		cout<<"Enter <1>To store data\n"<<endl;
		cout<<"Enter <2>To retrieve data\n"<<endl;
		cout<<"Enter <0>To exit\n"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"\nEnter data to store"<<endl; cin>>data;
					store(data);
					break;
			case 2: retrieve();
					break;
			case 0: break;
		}
	}
	return 0;
}
void store(int data)
{
	if(rear==max-1)
	{
		cout<<"!!! Queue overflow !!!\n\n"<<endl;
		return;
	}
	if(rear==-1)
	{
		front++;
	}
	queue[++rear]=data;
}
void retrieve()
{
	if(rear==-1)
	{
		cout<<"!!! Queue underflow !!!\n\n"<<endl;
		return;
	}
	cout<<"Retrieved data is: "<<queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
		++front;
}
