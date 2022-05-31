#include <iostream>
using namespace std;
struct Node
{
	int key;
	Node* lptr;
	Node* rptr;
	Node* parent;
	static Node* srch;
};
class BST
{
	Node* root;
	public:
		void creation();
		static int maximumm;
		static int minimumm;
		void insert(int);
		void maximum();
		void minimum();
		void traverse();
		void inOrderTrv(Node* );
		void preOrderTrv(Node*);
		void postOrderTrv(Node*);
		void successor(int v);
		void Search(int);
};
int BST::maximumm=0;
int BST::minimumm=0;
void BST :: creation()
{
	int val,ch;
	do
	{
		cout<<"Enter Data: ";
		cin>>val;
		insert(val);
		cout<<"Have another Node:\n1.Yes  2.No \n";
		cin>>ch;
	}while(ch==1);
}

void BST :: insert(int v)
{
	Node* newnode= new Node;
	Node* temp= new Node;
	newnode->key=v;
	newnode->lptr=NULL;
	newnode->rptr=NULL;
	if(!root)
	{
		root=newnode;
		cout<<"ROOT NOOT IS INSERTED\n";
	}
	else
	{
		temp=new Node;
		temp=root;
		while(temp)
		{
			if(temp->key> newnode->key)
			{
				if(temp->lptr==NULL)
				{
				temp->lptr=newnode;
				temp->parent=newnode;
				break;
				}
				temp=temp->lptr;
				cout<<"Inserted at Left\n";
			}
			else if(temp->key<=newnode->key)
			{
				if(temp->rptr==NULL)
				{
					temp->rptr=newnode;
					temp->parent=newnode;
					break;
				}
				temp=temp->rptr;
				cout<<"Inserted at Right\n";
			}
		}
	}
}
void BST :: maximum()
{
	int v;
	Node* maxi;
	maxi=root;
	if(!root)
	{
		cout<<"No tree exist\n";
		return;
	}
	while(maxi!=NULL)
	{	
		maximumm=v=maxi->key;
		maxi=maxi->rptr;
	}
	cout<<"MAX in BST is: "<<maximumm<<endl;

}
void BST :: minimum()
{
	int v;
	Node* mini;
	mini=root;
	if(!root)
	{
		cout<<"No tree exist\n";
		return;
	}
	while(mini)
	{
		v=mini->key;
		mini=mini->lptr;
	}
	cout<<"Minimum in BST is: "<<v<<endl;
	//return minimum;
}
void BST :: traverse()
{
	Node* trv;
	trv=root;
	int ch;
	cout<<" 1.Inorder\n";
	cout<<" 2.Preorder\n";
	cout<<" 3.Postorder\n";
	cout<<" 4.Back to main\n";
	cout<<" Enter choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			inOrderTrv(trv);
			cout<<endl;
			return;
		case 2:
			cout<<endl;
			preOrderTrv(trv);
			return;
		case 3:
			cout<<endl;
			postOrderTrv(trv);
			return;
		case 4:
			ch=4;
	}while(ch!=4);
}
void BST::preOrderTrv(Node* rt)
{
	if(rt)
	{
		if(rt->key){
			cout<<"D";
		}
		else
		{
		
    	cout<<rt->key<<"\t";
    	preOrderTrv(rt->lptr);
    	preOrderTrv(rt->rptr);
       }
	}
}
void BST :: inOrderTrv(Node* rt)
{
	
	if(rt)
	{
		inOrderTrv(rt->lptr);
		cout<<rt->key<<" ";
		inOrderTrv(rt->rptr);	
	}
} 
void BST :: postOrderTrv(Node* rt)
{
	if(rt)
	{
		postOrderTrv(rt->lptr);
		postOrderTrv(rt->rptr);
		cout<<rt->key;
	}
}
void BST :: successor(int x)
{
	Node* temp=root; int suc;
	if(root==NULL)
	{
		cout<<"Tree Not Exist\n";
		return;
	}
	Search(x);
	
}
void BST :: Search(int v)
{
	bool found=false;
	Node* temp=root;
	while(temp)
	{
		if(temp->key==v)
		{
			temp->key=-1;
			cout<<"Data exist in BST\n";
			found=true;
			return;
		}
		else if(temp->key>v)
		{
		
			temp=temp->lptr;
		}
		else
			temp=temp->rptr;
	}
	cout<<"Not found in BST.\n";
	if(found==false)
	exit(-1);
	
}
int main()
{
	int ch,v; bool found;
	BST tree;
			cout<<"       DEVELOPED BY MUHAMMAD ASIM\n\n";
	do
	{
		cout<<"    Main Menu\n";
		cout<<"1. Creation\n";
		cout<<"2. Insertion\n";
		cout<<"3. Maximum\n";
		cout<<"4. Minimum\n";
		cout<<"5. Traverse Tree\n";
		cout<<"6. Successoor\n";
		cout<<"7. predessor\n";
		cout<<"8. Search\n";
		cout<<"9. Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
		
		case 1:
			tree.creation();
			break;
		case 2:
			cout<<"Enter Data to insert: ";cin>>v;
			tree.insert(v);
			break;
		case 3:
			tree.maximum();
			break;
		case 4:
			tree.minimum();
			break;
		case 5:
			tree.traverse();
			break;
		case 6:
			cout<<"Enter Node  for Successor: ";
			cin>>v;
			tree.successor(v);
			break;
		case 7:
			cout<<" ";
			break;
		case 8:
			cout<<"Enter Node  for Search: ";
			cin>>v;
			tree.Search(v);
			break;
		case 9: 
			exit(-1);
		}	
	}while(1);
	return 0;
}
