#include <bits/stdc++.h>
using namespace std;

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

void printAncestors(struct Node *root, int key)
{
	if (root == NULL) return;

	stack<struct Node* > st;

	while (1)
	{
		while (root && root->data != key)
		{
			st.push(root); 
			root = root->left; 
		}

		if (root && root->data == key)
			break;
		if (st.top()->right == NULL)
		{
			root = st.top();
			st.pop();


			while (!st.empty() && st.top()->right == root)
			{root = st.top();
			st.pop();
			}
		}

		root = st.empty()? NULL: st.top()->right;
	}

	while (!st.empty())
	{
		cout<<st.top()->data<<" ";
		st.pop();
	}
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->right->right = newNode(9);
	root->right->right->left = newNode(10);

	cout<<"Following are all keys and their ancestors"<<endl;
	for (int key = 1; key <= 10; key++)
	{
		cout<<key<<":"<<" ";
		printAncestors(root, key);
		cout<<endl;
	}

	return 0;
}

