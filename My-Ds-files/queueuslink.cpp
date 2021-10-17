#include<iostream>
using namespace std;
typedef struct node
{
	int value;
	struct node *next;
}qu;
qu *front=NULL,*rear=NULL;
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
	qu *temp=NULL;
	temp=new qu;
	if(temp==NULL)
	{
		cout<<"!!! Queu overflow !!!\n\n"<<endl;
		return;
	}
	temp->value=data;
	temp->next=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
void retrieve()
{
	qu *temp;
	if(front==NULL)
	{
		cout<<"!!! Queu underflow !!!\n\n"<<endl;
		return;
	}
	temp=front;
	cout<<"Value retrieved is "<<front->value<<"\n\n";
	if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	else
	{
		front=front->next;
	}
	delete temp;
}
