#include <stdio.h>
#include <stdlib.h>
typedef struct SUM
{
    int info;
    struct SUM *left, *right;
}*NODE;
NODE createnode(int key)
{
    NODE newnode = (NODE)malloc(sizeof(struct SUM));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}
int sumofnodes(NODE root)
{
    int rightsubtree, leftsubtree, sum = 0;
    if(root != NULL)
    {
        leftsubtree = sumofnodes(root->left);
        rightsubtree = sumofnodes(root->right);
        sum = (root->info) + leftsubtree + rightsubtree;
        return sum;
    }
}

int main()
{

   NODE newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
   newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);

    printf("Sum of nodes in tree 1 = %d", sumofnodes(newnode));
    printf("\n");

   NODE node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);

    printf("Sum of nodes in tree 2 = %d", sumofnodes(node));
    printf("\n");


    NODE root = createnode(15);

    printf("Sum of nodes in tree 3 = %d", sumofnodes(root));
    printf("\n");
    return 0;
}
