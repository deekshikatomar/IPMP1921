#include <stdio.h>
#include <stdlib.h>

int max(int l, int r) { return (l > r ? l : r); }

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void print(struct Node *root)
{
	if (root != NULL)
	{
		print(root->left);
		printf("%d ",root->data);
		print(root->right);
	}
}

struct Node *pruneUtil(struct Node *root, int k, int *sum)
{
	if (root == NULL) return NULL;

	int lsum = *sum + (root->data);
	int rsum = lsum;

	root->left = pruneUtil(root->left, k, &lsum);
	root->right = pruneUtil(root->right, k, &rsum);

	*sum = max(lsum, rsum);

	if (*sum < k)
	{
		free(root);
		root = NULL;
	}

	return root;
}

struct Node *prune(struct Node *root, int k)
{
	int sum = 0;
	return pruneUtil(root, k, &sum);
}

int main()
{
	int k = 45;
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(12);
	root->right->right->left = newNode(10);
	root->right->right->left->right = newNode(11);
	root->left->left->right->left = newNode(13);
	root->left->left->right->right = newNode(14);
	root->left->left->right->right->left = newNode(15);

	printf("Tree before truncation\n");
	print(root);

	root = prune(root, k); // k is 45

	printf("\n\nTree after truncation\n");
	print(root);

	return 0;
}
