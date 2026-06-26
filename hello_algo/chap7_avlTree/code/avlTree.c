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

TreeNode *rightRotate(TreeNode *node)
{
    TreeNode *child, *grandchild;
    child = node->left;
    grandchild = child->right;
    child->right = node;
    node->left = grandchild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode *leftRotate(TreeNode *node)
{
    TreeNode *child, *grandchild;
    child = node->right;
    grandchild = child->left;
    child->left = node;
    node->right = grandchild;
    updateHeight(node);
    updateHeight(child);
    return child;
}

TreeNode *rotate(TreeNode *node)
{
    int bf = balanceFactor(node);
    if (bf > 1)
    {
        if (balanceFactor(node->left) >= 0)
        {
            return rightRotate(node);
        }
        else
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (bf < -1)
    {
        if (balanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }
        else
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

void insert(AVLTree *tree, int val)
{
    tree->root = insertHelper(tree->root, val);
}

TreeNode *insertHelper(TreeNode *node, int val)
{
    if (node == NULL)
    {
        return newTreeNode(val);
    }
    if (val < node->val)
    {
        node->left = insertHelper(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = insertHelper(node->right, val);
    }
    else
    {
        return node;
    }
    updateHeight(node);
    node = rotate(node);
    return node;
}

void removeItem(AVLTree *tree, int val)
{
    TreeNode *root = removeHelper(tree->root, val);
}

TreeNode *removeHelper(TreeNode *node, int val)
{
    TreeNode *child, *grandchild;
    if (node == NULL)
        return NULL;
    if (val < node->val)
    {
        node->left = removeHelper(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = removeHelper(node->right, val);
    }
    else
    {
        if (node->left == NULL || node->right == NULL)
        {
            child = node->left;
            if (node->right != NULL)
            {
                child = node->right;
            }
            if (child == NULL)
            {
                return NULL;
            }
            else
            {
                node = child;
            }
        }
        else
        {
            TreeNode *temp = node->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            int tempVal = temp->val;
            node->right = removeHelper(node->right, temp->val);
        }
    }
    updateHeight(node);
    node = rotate(node);
    return node;
}

int main()
{
    return 0;
}
