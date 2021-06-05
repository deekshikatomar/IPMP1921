#include<bits/stdc++.h>

using namespace std;


class node
{
	public:
	int data;
	node* left;
	node* right;


	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		
	}
};


int largestBSTUtil(node* node, int *min_ref, int *max_ref,
					int *max_size_ref, bool *is_bst_ref);


int largestBST(node* node)
{
	int min = INT_MAX;
	int max = INT_MIN; 
	
	int max_size = 0; 
	bool is_bst = 0;
	
	largestBSTUtil(node, &min, &max,
					&max_size, &is_bst);
	
	return max_size;
}

int largestBSTUtil(node* node, int *min_ref, int *max_ref,
					int *max_size_ref, bool *is_bst_ref)
{

	
	if (node == NULL)
	{
		*is_bst_ref = 1; 
		return 0; 
	}
	
	int min = INT_MAX;

	bool left_flag = false;
	
	bool right_flag = false;
	
	int ls, rs; 

	*max_ref = INT_MIN;
	ls = largestBSTUtil(node->left, min_ref, max_ref,
						max_size_ref, is_bst_ref);
	if (*is_bst_ref == 1 && node->data > *max_ref)
		left_flag = true;
	
	
	min = *min_ref;
	
	*min_ref = INT_MAX;
	rs = largestBSTUtil(node->right, min_ref,
						max_ref, max_size_ref, is_bst_ref);
	if (*is_bst_ref == 1 && node->data < *min_ref)
		right_flag = true;
	
	if (min < *min_ref)
		*min_ref = min;
	if (node->data < *min_ref) 
		*min_ref = node->data;
	if (node->data > *max_ref)
		*max_ref = node->data;

	if(left_flag && right_flag)
	{
		if (ls + rs + 1 > *max_size_ref)
			*max_size_ref = ls + rs + 1;
		return ls + rs + 1;
	}
	else
	{
		*is_bst_ref = 0;
		return 0;
	}
}

/* Driver code*/
int main()
{
		
	
	node *root = new node(50);
	root->left = new node(10);
	root->right = new node(60);
	root->left->left = new node(5);
	root->left->right = new node(20);
	root->right->left = new node(55);
	root->right->left->left = new node(45);
	root->right->right = new node(70);
	root->right->right->left = new node(65);
	root->right->right->right = new node(80);
	
	
	cout<<" Size of the largest BST is "<< largestBST(root);

	return 0;
}


