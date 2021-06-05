#include <bits/stdc++.h>
using namespace std;

struct node
{
	int key;
	struct node* left;
	struct node* right;
};
struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void addGreaterUtil(struct node *root, int *sum_ptr)
{
	if (root == NULL)
		return;

	addGreaterUtil(root->right, sum_ptr);

	*sum_ptr = *sum_ptr + root->key;

	root->key = *sum_ptr;

	addGreaterUtil(root->left, sum_ptr);
}

void addGreater(struct node *root)
{
	int sum = 0;
	addGreaterUtil(root, &sum);
}

void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->key << " " ;
	printInorder(node->right);
}

// Driver Code
int main()
{
	node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(13);

	cout << "Inorder traversal of the "
		<< "given tree" << endl;
	printInorder(root);

	addGreater(root);
	cout << endl;
	cout << "Inorder traversal of the "
		<< "modified tree" << endl;
	printInorder(root);

	return 0;
}


