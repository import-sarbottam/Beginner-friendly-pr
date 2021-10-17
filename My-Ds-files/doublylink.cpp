#include<iostream>
using namespace std;

class NODE
{
	public:
	int value;
	class NODE *flink, *plink;
};
NODE *start=NULL;
void append(int data);
void display();
void display2();
void insbeg(int data);
void insaftnode();
void delnode(int data);
void revlist();

int main()
{
	int data,prompt=1;
	while(prompt!=0)
	{
		cout<<"Enter <1>To Enter data\n"<<endl;
		cout<<"Enter <2>To show data\n"<<endl;
		cout<<"Enter <3>To Enter data at beginning\n"<<endl;
		cout<<"Enter <4>To Enter data after a node\n"<<endl;
		cout<<"Enter <5>To Delete a given node\n"<<endl;
		cout<<"Enter <6>To reverse the linked list\n"<<endl;
		cout<<"Enter <0>To exit\n"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"\nEnter data: "; cin>>data;
					append(data);
					break;
			case 2: display2();
					break;
			case 3: cout<<"\nEnter data: "; cin>>data;
					insbeg(data);
					break;
			case 4: insaftnode();
					break;
			case 5: cout<<"Enter the number of the node you want to delete: "; cin>>data;
					delnode(data);
					break;
			case 6: revlist(); break;
			case 0: break;
		}
	}
	return 0;
}
void append(int data)
{
	NODE *curr,*temp;
	temp=new NODE;
	if(temp==NULL)
	{
		cout<<"!!! Memory allocation failed !!!\n\n";
		return;
	}
	temp->value=data;
	temp->flink=NULL;
	temp->plink=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(curr->flink!=NULL)
		{
			curr=curr->flink;
		}
		curr->flink=temp;
		temp->plink=curr;
	}
}
void display2()
{
	NODE *curr=start,*ptr=NULL;
	int count=0;
	if(start==NULL)
	{
		cout<<"!!! No data in current linked list !!!\n\n";
		return;
	}
	while(curr!=NULL)
	{
		ptr=curr;
		count++;
		cout<<"Data at node no "<<count<<" from forward is: "<<curr->value<<"\n";
		curr=curr->flink;
	}
	count=0;
	cout<<"----------------------------------------"<<endl;
	while(ptr!=NULL)
	{
		count++;
		cout<<"Data at node no "<<count<<" from backward is: "<<ptr->value<<"\n";
		ptr=ptr->plink;
	}
}
void display()
{
	NODE *curr;
	int count=0,check;
	curr=start;
	while(curr!=NULL)
	{
		count++;
		if(curr->plink==NULL)
		{
			cout<<"Data at "<<count<<" is: "<<curr->value<<"\n\n";
			cout<<"!!! You can only only go forward from here !!!\n\n";
			cout<<"Press <1> to go to next node, <0> to return\n\n"<<endl;
			cout<<"Enter your choice: "; cin>>check;
			if(check==1)
			{
				curr=curr->flink;
			}
			else
				return;
		}
		else if(curr->flink==NULL)
		{
			cout<<"Data at "<<count<<" is: "<<curr->value<<"\n\n";
			cout<<"!!! You can only only go backward from here !!!\n\n";
			cout<<"Press <2> to go to previous node, <0> to return\n\n"<<endl;
			cout<<"Enter your choice: "; cin>>check;
			if(check==2)
			{
				curr=curr->plink;
				count-=2;
			}
			else
				return;
		}
		else
		{
			cout<<"Data at "<<count<<" is: "<<curr->value<<"\n\n";
			cout<<"Press <1>To go to next node, <2>To go to previous node, <0> to return"<<endl;
			cout<<"Enter your choice: "; cin>>check;
			if(check==1)
			{
				curr=curr->flink;
			}
			else if(check==2)
			{
				curr=curr->plink;
				count-=2;
			}
			else
				return;
		}
	}
}
void insbeg(int data)
{
	NODE *temp;
	temp=new NODE;
	if(temp==NULL)
	{
		cout<<"!!! Memory allocation failed !!!\n\n";
		return;
	}
	temp->value=data;
	temp->flink=NULL;
	temp->plink=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->flink=start;
		start->plink=temp;
		start=temp;
	}
}
void insaftnode()
{
	int data,count=0,pos;
	NODE *curr=start,*temp=NULL;
	cout<<"\nEnter Data: "; cin>>data;
	temp=new NODE;
	if(temp==NULL)
	{
		cout<<"!!! Memory allocation failed !!!\n\n";
		return;
	}
	temp->value=data;
	temp->flink=NULL;
	temp->plink=NULL;
	cout<<"\nEnter node number: "; cin>>pos;
	while(count!=pos-1)
	{
		count++;
		curr=curr->flink;
	}
	if(curr==NULL)
	{
		cout<<"!!! Node doesnot exist !!!";
		return;
	}
	temp->plink=curr;
	temp->flink=curr->flink;
	curr->flink=temp;
}
void delnode(int data)
{
	NODE *curr=start,*temp;
	int count=0;
	if(data==1)
	{
		if(start->flink==NULL)
		{
			temp=start;
			start=NULL;
		}
		else
		{
			temp=start;
			start=start->flink;
			start->plink=NULL;
			temp->flink=NULL;
		}
		delete temp;
	}
	else
	{
		while((curr!=NULL) && (count<data-2))
		{
			count++;
			curr=curr->flink;
		}
		if(curr==NULL)
		{
			cout<<"!!! Node doesnot exist !!!\n\n";
		}
		temp=curr->flink;
		curr->flink=temp->flink;
		temp->flink->plink=curr;
		temp->flink=NULL;
		temp->plink=NULL;
		delete temp;
	}
}
void revlist()
{
	NODE *curr=start,*temp=NULL,*prev=NULL;
	while(curr!=NULL)
	{
		prev=curr;
		temp=curr->flink;
		curr->flink=curr->plink;
		curr->plink=temp;
		curr=temp;
	}
	start=prev;
}
