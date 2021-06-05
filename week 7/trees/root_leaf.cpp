#include <bits/stdc++.h>
using namespace std;
#define bool int

class node
{
	public:
	int data;
	node* left;
	node* right;
};

bool hasPathSum(node* Node, int sum)
{
	if (Node == NULL)
	{
		return (sum == 0);
	}
	
	else
	{
		bool ans = 0;
	
		int subSum = sum - Node->data;
	
		if ( subSum == 0 && Node->left == NULL && Node->right == NULL )
		return 1;
		
		if(Node->left)
			ans = ans || hasPathSum(Node->left, subSum);
		if(Node->right)
			ans = ans || hasPathSum(Node->right, subSum);
	
		return ans;
	}
}

node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return(Node);
}

// Driver Code
int main()
{

	int sum = 21;
	
	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);
	
	if(hasPathSum(root, sum))
		cout << "There is a root-to-leaf path with sum " << sum;
	else
		cout << "There is no root-to-leaf path with sum " << sum;
	
	return 0;
}

