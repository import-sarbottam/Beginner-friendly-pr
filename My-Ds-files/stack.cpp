#include<iostream>
using namespace std;
#define Max 10
int stack[Max];
int top=-1;
void push(int data);
void pop();

int main()
{
	int data,prompt=1;
	while(prompt!=0)
	{
		cout<<"Enter <1>To push data"<<endl;
		cout<<"Enter <2>To pop data"<<endl;
		cout<<"Enter <0>To exit"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"Enter data to push"<<endl; cin>>data;
					push(data);
					break;
			case 2: pop();
					break;
			case 0: break;
		}
	}
	return 0;
}
void push(int data)
{
	if(top==Max-1)
	{
		cout<<"!!!Stack overflow!!!"<<endl;
		return;
	}
	else
	{
		stack[++top]=data;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<"!!!Stack underflow!!!"<<endl;
		return;
	}
	else
	{
		cout<<stack[top--]<<"\n\n";
	}
}
