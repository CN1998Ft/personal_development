#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int val;
  int height;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *newTreeNode(int val)
{
  TreeNode *node;

  node = (TreeNode *)malloc(sizeof(TreeNode));
  node->val = val;
  node->height = 0;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int height(TreeNode *node)
{
    if (node != NULL)
    {
        return node->height;
    }
    return -1;
}

void updateHeight(TreeNode *node)
{
    int lh = height(node->left);
    int rh = height(node->right);
    if (lh > rh)
    {
        node->height = lh + 1;
    }
    else
    {
        node->height = rh + 1;
    }
}

int balanceFactor(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

int main()
{
    return 0;
}
