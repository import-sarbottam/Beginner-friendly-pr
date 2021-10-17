/*Adding a little comment*/
#include<iostream>
#include<queue>
using namespace std;
class tree
{
	public:
	int data;
	tree *left,*right;
};
tree *root=NULL;

void append(int value);
void pretrav(class tree*temp);
void intrav(class tree*temp);
void posttrav(class tree*temp);
void leveltrav();
void display();
int max(class tree*temp);
int min(class tree*temp);
int findheight(class tree*temp);
class tree* search(int value);
void delnode(int value);
void delleaf(tree *ptr,tree* par);
void del_1child(tree *ptr,tree* par);
void del_2child(tree *ptr);
void deltree(tree *temp);
void mirror(tree *temp);

int main()
{
	int data,prompt=1;
	do
	{
		cout<<"Enter <1>To Enter data into the tree\n"<<endl;
		cout<<"Enter <2>To Display data\n"<<endl;
		cout<<"Enter <3>To search for the maximum value in the binary tree\n"<<endl;
		cout<<"Enter <4>To search for the minimum value in the binary tree\n"<<endl;
		cout<<"Enter <5>To find the height of the binary tree\n"<<endl;
		cout<<"Enter <6>To search for a value in the binary tree\n"<<endl;
		cout<<"Enter <7>To delete a value from the binary tree\n"<<endl;
		cout<<"Enter <8>To delete the binary tree\n"<<endl;
		cout<<"Enter <9>To create a mirror image of the binary tree\n"<<endl;
		cout<<"Enter <0>To exit\n"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"\nEnter data: "<<endl; cin>>data;
					append(data);
					break;
			case 2: display(); break;
			case 3:	data=max(root);
					cout<<"Maximum value is: "<<data<<endl;
					break;
			case 4:	data=min(root);
					cout<<"Minimum value is: "<<data<<endl;
					break;
			case 5: data=findheight(root);
					cout<<"Height of the tree is: "<<data<<endl;
					break;
			case 6: cout<<"\nEnter data to search: "<<endl; cin>>data;
					search(data);
					break;
			case 7: cout<<"\nEnter value to delete: "<<endl; cin>>data;
					delnode(data);
					break;
			case 8:	deltree(root);
					break;
			case 9:	mirror(root);
					break;
			case 0: break;
		}
	}while(prompt!=0);
	return 0;
}

void append(int value)
{
	tree *temp=NULL,*curr=NULL,*ptr=NULL;
	temp= new tree;
	if(temp==NULL)
	{
		cout<<"!!! Memory allocation failed !!!\n\n";
		return;
	}
	temp->data=value;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		curr=root;
		while(curr!=NULL)
		{
			ptr=curr;
			if(value>=curr->data)
				curr=curr->right;
			else
				curr=curr->left;
		}
		if(value<ptr->data)
			ptr->left=temp;
		else
			ptr->right=temp;
	}
}
void pretrav(class tree *temp)
{
	
	if(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		pretrav(temp->left);
		pretrav(temp->right);
	}
}
void intrav(class tree *temp)
{
	
	if(temp!=NULL)
	{
		intrav(temp->left);
		cout<<temp->data<<"\t";
		intrav(temp->right);
	}
}
void posttrav(class tree *temp)
{
	
	if(temp!=NULL)
	{
		posttrav(temp->left);
		posttrav(temp->right);
		cout<<temp->data<<"\t";
	}
}
void leveltrav()
{
	tree *curr=root,*temp=NULL;
	queue<tree*> q;
	if(root==NULL)
	{
		cout<<"!!! Tree is empty !!!\n\n";
		return;
	}
	q.push(curr);
	while(!q.empty())
	{
		temp=q.front();
		cout<<temp->data<<"\t";
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
		q.pop();	
	}
}
void display()
{
	int prompt=1;
	do
	{
		cout<<"Enter <0> To return to main program\n"<<endl;
		cout<<"Enter <1>To show data in preorder traversal\n"<<endl;
		cout<<"Enter <2>To show data in inorder traversal\n"<<endl;
		cout<<"Enter <3>To show data in postorder traversal\n"<<endl;
		cout<<"Enter <4>To show data in level order traversal\n"<<endl;
		cout<<"Enter your choice: "<<endl; cin>>prompt;
		switch(prompt)
		{
			case 1: cout<<"Data in preorder traversal is: ";
					pretrav(root); cout<<"\n"; 
					break;
			case 2: cout<<"Data in inorder traversal is: ";
					intrav(root); cout<<"\n";
					break;
			case 3: cout<<"Data in preorder traversal is: ";
					posttrav(root); cout<<"\n";
					break;
			case 4: cout<<"Data in level order traversal is: ";
					leveltrav(); cout<<"\n";
					break;
			case 0: return;
		}
	}while(prompt!=0);
}
int max(class tree *temp)
{
	if(root==NULL)
	{
		return -1;
	}
	else if(temp->right==NULL)
	{
		return temp->data;
	}
	else
	{
		return max(temp->right);
	}
}
int min(class tree *temp)
{
	if(root==NULL)
	{
		return -1;
	}
	else if(temp->left==NULL)
	{
		return temp->data;
	}
	else
	{
		return min(temp->left);
	}
}
int findheight(class tree *temp)
{
	int lheight,rheight;
	if(temp==NULL)
	{
		return 0;
	}
	else if(root->left==NULL && root->right==NULL)
	{
		return 0;
	}
	else
	{
		lheight=findheight(temp->left);
		rheight=findheight(temp->right);
	}
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}
class tree *search(int value)
{
	tree *curr;
	curr=root;
	while(curr->data!=value)
	{
		if(value<=curr->data)
			curr=curr->left;
		else
			curr=curr->right;
		if(curr==NULL)
		{
			cout<<"!!! Value not found !!!\n\n";
			return NULL;
		}
	}
	if(curr!=NULL)
	{
		cout<<"Value found at address: "<<curr<<endl;
		return curr;
	}
}
void delnode(int value)
{
	tree *ptr=root,*par=NULL;
	if(root==NULL)
	{
		cout<<"Tree is empty!"<<endl;
		return;
	}
	while(ptr->data!=value)
	{
		par=ptr;
		if(value<=ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
		if(ptr==NULL)
		{
			cout<<"!!! Value not found !!!";
			return;
		}
	}
	if(ptr->left!=NULL && ptr->right!=NULL)
		del_2child(ptr);
	else if(ptr->left!=NULL)
		del_1child(ptr,par);
	else if(ptr->right!=NULL)
		del_1child(ptr,par);
	else
		delleaf(ptr,par);
}
void delleaf(tree* ptr,tree* par)
{
	if(par==NULL)
		root=NULL;
	else if(par->right==ptr)
		par->right=NULL;
	else
		par->left=NULL;
	delete ptr;
}
void del_1child(tree* ptr,tree* par)
{
	if(par==NULL)
	{
		if(ptr->left!=NULL)
			root=ptr->left;
		else
			root=ptr->right;
	}
	else if(par->left!=NULL)
	{
		if(ptr->left!=NULL)
			par->left=ptr->left;
		else
			par->left=ptr->right;
	}
	else
	{
		if(ptr->left!=NULL)
			par->right=ptr->left;
		else
			par->right=ptr->right;
	}
	delete ptr;
}
void del_2child(tree *ptr)
{
	tree *succ=ptr->right,*succpar=ptr;
	while(succ->left!=NULL)
	{
		succpar=succ;
		succ=succ->left;
	}
	ptr->data=succ->data;
	if(succ->left==NULL && succ->right==NULL)
	{
		delleaf(succ,succpar);
	}
	else
		del_1child(succ,succpar);
}
void deltree(tree *temp)
{
	if(temp!=NULL)
	{
		deltree(temp->left);
		deltree(temp->right);
		delete temp;
	}
	root=NULL;
}
void mirror(tree *temp)
{
	tree *swap;
	if(temp==NULL)
		return;
	else
	{
		mirror(temp->left);
		mirror(temp->right);
		swap=temp->left;
		temp->left=temp->right;
		temp->right=swap;
	}
}
