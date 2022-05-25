#include <stdio.h>
#include <stdlib.h>

typedef struct height {
	int data;
	struct height* left;
	struct height* right;
}*NODE;

int DEPTH(NODE node)
{
	if (node == NULL)
		return -1;
	else {

		int lDepth = DEPTH(node->left);
		int rDepth = DEPTH(node->right);

		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}
NODE newNode(int data)
{
	NODE node
		= (NODE)malloc(sizeof(struct height));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	NODE root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Height of tree is %d", DEPTH(root));

	getchar();
	return 0;
}
