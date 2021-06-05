#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

int max(int inorder[], int strt, int end);

node* newNode(int data);

node* buildTree (int inorder[], int start, int end)
{
	if (start > end)
		return NULL;

	int i = max (inorder, start, end);

	node *root = newNode(inorder[i]);

	if (start == end)
		return root;

	root->left = buildTree (inorder, start, i - 1);
	root->right = buildTree (inorder, i + 1, end);

	return root;
}

int max (int arr[], int strt, int end)
{
	int i, max = arr[strt], maxind = strt;
	for(i = strt + 1; i <= end; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			maxind = i;
		}
	}
	return maxind;
}

node* newNode (int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

void printInorder (node* node)
{
	if (node == NULL)
		return;

	printInorder (node->left);

	cout<<node->data<<" ";

	printInorder (node->right);
}

/* Driver code*/
int main()
{

	int inorder[] = {5, 10, 40, 30, 28};
	int len = sizeof(inorder)/sizeof(inorder[0]);
	node *root = buildTree(inorder, 0, len - 1);

	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
	return 0;
}


