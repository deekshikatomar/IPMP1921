#include<bits/stdc++.h>

/ tree node structure *
struct node* newNode (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


struct node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
	int index = *index_ptr; 
	if (index == n)
		return NULL;

	
	struct node *temp = newNode ( pre[index] );
	(*index_ptr)++;


	if (preLN[index] == 'N')	
	{
	temp->left = constructTreeUtil(pre, preLN, index_ptr, n);
	temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
	}

	return temp;
}


struct node *constructTree(int pre[], char preLN[], int n)
{
	
	int index = 0;

	return constructTreeUtil (pre, preLN, &index, n);
}


/
void printInorder (struct node* node)
{
	if (node == NULL)
		return;


	printInorder (node->left);


	printf("%d ", node->data);


	printInorder (node->right);
}


int main()
{
	struct node *root = NULL;

	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int n = sizeof(pre)/sizeof(pre[0]);
	root = constructTree (pre, preLN, n);
	printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder (root);

	return 0;
}
