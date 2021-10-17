#include<iostream>
using namespace std;

typedef struct record
{
	int x;
	struct record *next;
}NODE;
void append(int n);
void display();
void insertbeg(int a);
void dellast();
void delfirst();
void delnode(int a);
void delnode_val(int a);
void insaftnode(int n,int a);
void insaftval(int n,int a);
void search(int a);
void dellist();
void revlist();
void asc();
void dsc();
NODE *start=NULL;

int main()
{
	int prompt,data,beg,n;
	cout<<"<=**********************************************************=>"<<endl;
	cout<<"<=*************************Welcome**************************=>"<<endl;
	cout<<"<=**Enter <0> to exit                                     **=>"<<endl;
	cout<<"<=**<1>To Enter data                                      **=>"<<endl;
	cout<<"<=**<2>To display data                                    **=>"<<endl;
	cout<<"<=**<3>To insert data at beginning                        **=>"<<endl;
	cout<<"<=**<4>To delete data at the end                          **=>"<<endl;
	cout<<"<=**<5>To delete data at the beginning                    **=>"<<endl;
	cout<<"<=**<6>To delete a given node(by node number)             **=>"<<endl;
	cout<<"<=**<7>To delete a given node(by value)                   **=>"<<endl;
	cout<<"<=**<8>To insert a value after a given node               **=>"<<endl;
	cout<<"<=**<9>To insert a value after a given value              **=>"<<endl;
	cout<<"<=**<10>To search for a value in the linked list          **=>"<<endl;
	cout<<"<=**<11>To delete current linked list                     **=>"<<endl;
	cout<<"<=**<12>To Reverse the linked list                        **=>"<<endl;
	cout<<"<=**<13>To sort list by ascending order                   **=>"<<endl;
	cout<<"<=**<14>To sort list by descending order                  **=>"<<endl;
	do
	{
		cout<<"\n \nEnter your choice: "; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"Enter data: "; cin>>data;
					append(data);
					break;
			case 2: display();
					break;
			case 3: cout<<"Enter data: "; cin>>beg;
					insertbeg(beg);
					break;
			case 4: dellast();
					break;
			case 5: delfirst();
					break;
			case 6: cout<<"Enter the number of the node you want to delete: "; cin>>n;
					delnode(n);
					break;
			case 7: cout<<"Enter the value in the node you want to delete: ";cin>>n;
					delnode_val(n);
					break;
			case 8: cout<<"Enter the node number: "; cin>>n;
					cout<<"Enter the data: "; cin>>data;
					insaftnode(n,data);
					break;
			case 9: cout<<"Enter the value after which you want to insert data: "; cin>>n;
					cout<<"Enter the data: "; cin>>data;
					insaftval(n,data);
					break;
			case 10: cout<<"Enter the number to search: "; cin>>data;
					 search(data);
					 break;
			case 11: dellist();
					 cout<<"!!!Current linked list is deleted!!!"<<endl;
					 break;
			case 12: revlist(); break;
			case 13: asc(); break;
			case 14: dsc(); break;
			case 0:  dellist();
					 return 0;
		}
	}while(prompt!=0);
	return 0;
}
void append(int n)
{
	NODE *temp=NULL,*curr=NULL;
	temp=new NODE;
	if(temp==NULL)
	{
		cout<<"!!!Memory allocation failed!!!";
		cout<<"Displaying current linked list";
		display();
	}
	else
	{
		temp->x=n;
		temp->next=NULL;
	}
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=temp;
	}
}
void display()
{
	NODE *curr;
	curr=start;
	int count=1;
	cout<<"\n Displaying current linked list: \n";
	while(curr!=NULL)
	{
		cout<<"Data number "<<count<<" is: "<<curr->x<<endl;
		curr=curr->next;
		count++;
	}
}
void insertbeg(int a)
{
	NODE *curr;
	curr= new NODE;
	if(curr==NULL)
	{
		cout<<"!!!Memory allocation failed!!!";
		cout<<"Displaying current linked list";
		display();
	}
	else
	{
		curr->x=a;
		curr->next=NULL;
	}
	if(start==NULL)
	{
		start=curr;
	}
	else
	{
		curr->next=start;
		start=curr;
	}
}
void dellast()
{
	NODE *curr,*temp;
	curr=start;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;	
	}
	temp=curr->next;
	curr->next=NULL;
	delete temp;
}
void delfirst()
{
	NODE *temp;
	temp=start;
	start=temp->next;
	delete temp;
}
void delnode(int a)
{
	NODE *prev,*curr;
	int count=0;
	prev=start;
	while((count!=a-1) && (prev!=NULL))
	{
		count++;
		prev=prev->next;
	}
	if(prev==NULL)
	{
		cout<<"!!!Node doesnot exist!!!";
		return;
	}
	else
	{
		curr=prev->next;
		prev->next=curr->next;
		delete curr;
	}
	
}
void delnode_val(int a)
{
	NODE *prev,*curr;
	prev=start;
	while(prev->next->x!=a)
	{	
		prev=prev->next;
	}
	if(prev->next!=NULL)
	{	
		curr=prev->next;
		prev->next=curr->next;
		delete curr;
	}
	else if(prev==NULL)
	{
		cout<<"!!!Value doesnot exist!!!";
		return;	
	}
}
void insaftnode(int n,int a)
{
	NODE *temp,*prev,*curr;
	int count=1;
	curr= new NODE;
	if(curr==NULL)
	{
		cout<<"!!!Memory allocation failed!!!";
		cout<<"Displaying current linked list";
		display();
	}
	else
	{
		curr->x=a;
		curr->next=NULL;
	}
	prev=start;
	while(count!=n)
	{
		prev=prev->next;
		count++;
	}
	temp=prev->next;
	prev->next=curr;
	curr->next=temp;
}
void insaftval(int n,int a)
{
	NODE *temp,*prev,*curr;
	curr= new NODE;
	if(curr==NULL)
	{
		cout<<"!!!Memory allocation failed!!!";
		cout<<"Displaying current linked list";
		display();
	}
	else
	{
		curr->x=a;
		curr->next=NULL;
	}
	prev=start;
	while(prev->x!=n)
	{
		prev=prev->next;
		if(prev==NULL)
		{
			cout<<"!!! Value doesnot exist !!!\n\n";
			return;
		}
	}
	temp=prev->next;
	prev->next=curr;
	curr->next=temp;
}
void search(int a)
{
	NODE *curr=start;
	int count=1;
	while((curr!=NULL) && (curr->x!=a))
	{
		curr=curr->next;
		count++;
	}
	if(curr->x==a)
	{
		cout<<"Value found at position number "<<count<<endl;
	}
	else
	{
		cout<<"!!!Value not found!!!"<<endl;
	}
}
void dellist()
{
	NODE *curr;
	while(start!=NULL)
	{
		curr=start;
		start=start->next;
		delete curr;
	}
}
void revlist()
{
	NODE *curr=start, *next=NULL, *prev=NULL;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
}
void asc()
{
	NODE *curr=start, *next=NULL;
	int temp;
	while(curr->next!=NULL)
	{
		next=curr->next;
		while(next!=NULL)
		{
			if(next->x<curr->x)
			{
				temp=curr->x;
				curr->x=next->x;
				next->x=temp;
			}
			next=next->next;
		}
		curr=curr->next;
	}
}
void dsc()
{
	NODE *curr=start, *next=NULL;
	int temp;
	while(curr->next!=NULL)
	{
		next=curr->next;
		while(next!=NULL)
		{
			if(next->x>curr->x)
			{
				temp=curr->x;
				curr->x=next->x;
				next->x=temp;
			}
			next=next->next;
		}
		curr=curr->next;
	}
}
