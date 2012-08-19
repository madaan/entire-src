//sg
/* simple program to read a tree
 * 
 */
#include<iostream>
#include<string>
#include<queue>
using namespace std;
/* A NODE OF THE TREE*/

template <class T>
struct TreeNode
{
	T  data;
	TreeNode * left,*right;
	TreeNode(T data)
	{
		
		this->data=data;
		left=right=NULL;
	}
};
/*CLASS REPRESENTING A TREE*/
template <class T>
class Tree
{
	TreeNode<T> * head;
	public:
	Tree(T  data)
	{
		head=new TreeNode<T>(data);
	}
	
	TreeNode<T>* getHead()
	{
		return head;
	}
	template<class L>
	friend istream& operator >> (istream& i,Tree<L>& t);
	void inorder(TreeNode<T>* head);
	void preorder(TreeNode<T>* head);
	void postorder(TreeNode<T>* head);
	int height(TreeNode<T>* head);
	int internalNodes(TreeNode<T>* head);
	int totalNodes(TreeNode<T>* head);
	int leafNodes(TreeNode<T>* head);
	void treeStatPrinter();
	void prettyPrint();
};
template<class T>
void Tree<T>::prettyPrint()
{
	queue<TreeNode<T>*> ready;
	queue<TreeNode<T>*> print;
	TreeNode<T>* curr,*currP;
	int ht=height(head);
	int nl=ht+1;
	//whitespace
	int wsBEG=1<<ht;//white space start
	int wsIBW=1<<nl;//white space in between
	/*ready queue at any time stores the nodes that belong to the 
	 * same level only*/
	 
	/*add head to ready queue*/
	ready.push(head);
	do
	{
	//fill print queue
	while(!ready.empty())
	{
		curr=ready.front();
		if(curr==NULL) 
		{
		print.push(NULL);
		ready.pop();  //delete the null
		continue;
		}
		ready.pop();
		//fill print queue
		print.push(curr);
	}
	for(int i=0;i<wsBEG+2;i++)
	{
		cout<<" ";
	}
	//print all of these and refill the ready queue
	while(!print.empty())
	{
		currP=print.front();
		print.pop();
	
		if(currP==NULL)
		{
			cout<<" ";
		}
		else
		{
		cout<<currP->data;
		ready.push(currP->left);
		ready.push(currP->right);
		}
			for(int i=0;i<wsIBW;i++)
		{
		cout<<" ";
		}
	}
	wsIBW=wsIBW>>1;
	
	wsBEG=wsBEG>>1;
	
	cout<<"\n\n";
	}while(--nl);
	
	
}
template<class T>
void Tree<T>::treeStatPrinter()
{
	cout<<"\n\t\tTREE STATS\n\n";
	cout<<"_____________________\n";
	cout<<"\tInorder Trace = ";inorder(head);cout<<"\n";
	cout<<"\n\tHeight = "<<height(head)<<"\n";
	cout<<"\n\tInternal Nodes = "<<internalNodes(head)<<"\n";
	cout<<"\n\tLeaf Nodes = "<<leafNodes(head)<<"\n";
	cout<<"\n\tTotal Nodes = "<<totalNodes(head)<<"\n";
	cout<<"_____________________\n";
}
template<class T>
int Tree<T>::height(TreeNode<T>* head)
{
	if((!head)||(!head->right&&!head->left))
	return 0;
	int lh=height(head->left);
	int rh=height(head->right);
	return 1+((lh>rh)?lh:rh);
}
template<class T>
int Tree<T>::internalNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 0;
	//ok not a leaf
	return 1+internalNodes(head->left)+internalNodes(head->right);
}
template<class T>
int Tree<T>::leafNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 1;
	//ok not a leaf
	return leafNodes(head->left)+leafNodes(head->right);
}

template<class T>
int Tree<T>::totalNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 1;
	//ok not a leaf
	return 1+totalNodes(head->left)+totalNodes(head->right);

}
template <class T>
void Tree<T>::inorder(TreeNode<T>* head)
{
	if(head)
	{
	inorder(head->left);
	cout<<" "<<head->data;
	inorder(head->right);
	}
}
template <class T>
void Tree<T>::preorder(TreeNode<T>* head)
{
	if(head)
	{
	cout<<" "<<head->data;
	preorder(head->left);
	preorder(head->right);
	}
}
template <class T>
void Tree<T>::postorder(TreeNode<T>* head)
{
	if(head)
	{
	postorder(head->left);
	postorder(head->right);
	cout<<" "<<head->data;
	}
}
template <class T>
istream& operator >> (istream& i,Tree<T>& t)
{
	//this will help in reading the tree in depth order
	TreeNode<T> * stack[100];
		
	int top=-1;
	/*Any type that has to be used with tree must define it's
	 * own input,output and null check operators*/
	T lv,rv;
	bool complete=false;
	TreeNode<T> * curr=t.head,*lc,*rc;
	while(!complete)
	{
		cout<<"\n";
		cout<<"Enter left child of  "<<curr->data<<" : ";
		cin>>lv;
		cout<<"Enter right child of "<<curr->data<<" : ";
		cin>>rv;
		if((lv==0)&&(rv==0)) //at a leaf
		{
			if(top==-1) //no  more to process
			{
				complete=true;
				break;
			}
			else //go to the next node
			{
				curr=stack[top];
				top--;
				continue;
			}
		}
		else if((lv==0)&&(rv!=0)) //only right child is there
		{
		rc=new TreeNode<T>(rv);
		top++;
		stack[top]=rc;
		curr->right=rc;
		}
		else if((lv!=0)&&(rv==0)) //only left child is there
		{
		lc=new TreeNode<T>(lv);
		top++;
		stack[top]=lc;
		curr->left=lc;
		}
		else //not a leaf, gotta update the l and r childs
		{
		lc=new TreeNode<T>(lv);
		top++;
		stack[top]=lc;
		rc=new TreeNode<T>(rv);
		top++;
		stack[top]=rc;
		curr->left=lc;
		curr->right=rc;
		}
		curr=stack[top];
		top--;
		}
return i;
}

	
int main()
{
	float rootVal;
	cout<<"Enter root node value " ;
	cin>>rootVal;
	Tree<float> * t=new  Tree<float>(rootVal);
	cin>>(*t);
	t->prettyPrint();
	//t->treeStatPrinter();
	return 0;
}
