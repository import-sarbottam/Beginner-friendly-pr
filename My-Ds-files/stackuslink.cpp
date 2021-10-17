#include<iostream>
using namespace std;
typedef struct node
{
	int value;
	struct node *next;
}stack;
stack *top=NULL;
void push(int data);
void pop();

int main()
{
	int data,prompt=1;
	while(prompt!=0)
	{
		cout<<"Enter <1>To push data\n"<<endl;
		cout<<"Enter <2>To pop data\n"<<endl;
		cout<<"Enter <0>To exit\n"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"\nEnter data to push"<<endl; cin>>data;
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
	stack *curr=NULL;
	curr= new stack;
	if(curr==NULL)
	{
		cout<<"!!!Stack overflow!!!\n\n"<<endl;
		return;
	}
	curr->value=data;
	curr->next=top;
	top=curr;
}
void pop()
{
	stack *curr=NULL;
	curr=top;
	if(top==NULL)
	{
		cout<<"!!!Stack Underflow!!!\n\n"<<endl;
		return;
	}
	else
	{
		cout<<"Popped value is: "<<curr->value<<"\n\n";
		top=curr->next;
		delete curr;
	}
} 
