#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct TreeNode
{
    int val;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode
*newTreeNode(int val)
{
    TreeNode *node;

    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Common node structure terminology:
// Root node: the top most node of the binary tree
// Leaf node: The end of binary tree and have no child nodes.
// Edge: The line that connects two nodes, the pointer between nodes.
// Level: increase from the top with Root node as level 1.
// Degree: number of child node of a node, with possible values as 0, 1, 2.
// Height of the binary tree: the number of edges from root to the furthest
// leaf node.
// Depth of a node: number of edges from the root to the node.
// Height of a node: number of edges from futhest leaf node to the node.
//
// **Height** is the bottom up approach.
// **Depth** is the top down approach.


// Common tree types:
//
// 1. Perfect Binary Tree
// Every level is completely filled with two child nodes. And leaf node has 0
// degree and other nodes have 2 degrees. If the height of the tree is h. The
// total number of nodes is 2 to the power of h+1 and minus 1. $2^(h+1) - 1$
//
// 2. Complete Binary Tree
// Only allows the bottom level to be incomplete. And all the leaf node has to
// be from left to right order.
//
// 3. Full Binary Tree
// All nodes except leaf nodes have to two child nodes, 2 degrees.
//
// 4. Balanced Binary Tree
// The absolute difference between the height of the left and right subtrees
// of any node does not exceed 1. I think it means that any node at known
// height or depth, the height of the the nodes on left and right subtrees will
// be smaller or equal to 1.

// The degenerate structure of the tree will become a linked list.


// The Binary tree traversal

int *levelOrder(TreeNode *root, int *size)
{
    int front, rear;
    int index, *arr;

    TreeNode *node;
    TreeNode **queue;

    queue = (TreeNode **)malloc(sizeof(TreeNode *) * MAX_SIZE);

    front = 0;
    rear = 0;
    queue[rear++] = root;
    arr = (int *)malloc(sizeof(int) * MAX_SIZE);
    index = 0;
    while (front < rear)
    {
        node = queue[front++];
        arr[index++] = node->val;

        if (node->left != NULL)
        {
            queue[rear++] = node->left;
        }
        if (node->right != NULL)
        {
            queue[rear++] = node->right;
        }
    }

    *size = index;
    arr = realloc(arr, sizeof(int) * (*size));

    free(queue);
    return arr;
}

// Preorder, inorder, and Postorder Traversal

void preOrder(TreeNode *root, int *size)
{
    if (root == NULL) return;

    int *arr;
    arr[(*size)++] = root->val;
    preOrder(root->left, size);
    preOrder(root->right, size);
}

void inOrder(TreeNode *root, int *size)
{
    if (root == NULL) return;

    inOrder(root->left, size);
    int *arr;
    arr[(*size)++] = root->val;
    inOrder(root->right, size);
}

void postOrder(TreeNode *root, int *size)
{
    if (root == NULL) return;

    postOrder(root->left, size);
    postOrder(root->right, size);
    // int *arr = (int *)malloc(sizeof(int) * size);
    arr[(*size)++] = root->val;
}

typedef struct
{
    int *tree;
    int size;
} ArrayBinaryTree;

ArrayBinaryTree *newArrayBinaryTree(int *arr, int arrSize)
{
    ArrayBinaryTree *abt = (ArrayBinaryTree *)malloc(sizeof(ArrayBinaryTree));
    abt->tree = malloc(sizeof(int) * arrSize);
    memcpy(abt->tree, arr, sizeof(int) * arrSize);
    abt->size = arrSize;
    return abt;
}

void delArrayBinaryTree(ArrayBinaryTree *abt)
{
    free(abt->tree);
    free(abt);
}

int size_a(ArrayBinaryTree *abt)
{
    return abt->size;
}

int val(ArrayBinaryTree *abt, int i)
{
    if (i < 0 || i >= size_a(abt))
        return INT_MAX;
    return abt->tree[i];
}

int *levelOrder_a(ArrayBinaryTree *abt, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * size_a(abt));
    int index = 0;

    for (int i = 0; i < size_a(abt); i++)
    {
        if (val(abt, i) != INT_MAX)
            res[index++] = val(abt, i);
    }
    *returnSize = index;
    return res;
}

void dfs(ArrayBinaryTree *abt, int i, char *order, int *res, int *index)
{
    if (val(abt, i) == INT_MAX)
        return;
    if (strcmp(order, "pre") == 0)
        res[(*index)++] = val(abt, i);
    dfs(abt, left(i), order, res, index);
    if (strcmp(order, "in") == 0)
        res[(*index)++] = val(abt, i);
    if(strcmp(order, "post") == 0)
        res[(*index)++] = val(abt, i);
}

int *preOrder_a(ArrayBinaryTree *abt, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * size_a(abt));
    int index = 0;
    dfs(abt, 0, "pre", res, &index);
    *returnSize = index;
    return res;
}

int *inOrder_a(ArrayBinaryTree *abt, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * size_a(abt));
    int index = 0;
    dfs(abt, 0, "in", res, &index);
    *returnSize = index;
    return res;
}

int *postOrder_a(ArrayBinaryTree *abt, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * size_a(abt));
    int index = 0;
    dfs(abt, 0, "post", res, &index);
    *returnSize = index;
    return res;
}

// Binary Search tree:
// left subtree < root < right subtree.
// And each level should follow this root.

TreeNode *search(BinarySearchTree *bst, int num)
{
    while (cur != NULL)
    {
        if (cur->val < num)
        {
            cur = cur->right;
        }
        else if (cur->val > num)
        {
            cur = cur->left;
        }
        else
        {
            break;
        }
    }
    return cur;
}

void insert(BinarySearchTree *bst, int num)
{
    if (bst->root == NULL)
    {
        bst->root = newTreeNode(num);
        return;
    }
    TreeNode *cur = bst->root, *pre = NULL;
    while (cur != NULL)
    {
        if (cur->val == num)
        {
            return;
        }
        pre = cur;
        if (cur->val < num)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    TreeNode *node = newTreeNode(num);
    if (pre->val < num)
    {
        pre->right = node;
    }
    else
    {
        pre->left = node;
    }
}

void removeItem(BinarySearchTree *bst, int num)
{
    if (bst->root == NULL)
        return;
    TreeNode *cur = bst->root, *pre = NULL;
    while (cur != NULL)
    {
        if (cur->val == num)
            break;
        pre = cur;
        if (cur->val < num)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    if (cur == NULL)
        return;
    if (cur->left == NULL || cur->right == NULL)
    {
        TreeNode *child = cur->left  != NULL ? cur->left : cur->right;
        if (pre->left == cur)
        {
            pre->left = child;
        }
        else
        {
            pre->right = child;
        }
        free(cur);
    }
    else
    {
        TreeNode *tmp = cur->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        removeItem(bst, tmp->val);
        cur->val = tmpVal;
    }
}

int main()
{

    TreeNode *n1 = newTreeNode(1);
    TreeNode *n2 = newTreeNode(2);
    TreeNode *n3 = newTreeNode(3);
    TreeNode *n4 = newTreeNode(4);
    TreeNode *n5 = newTreeNode(5);
    TreeNode *n6 = newTreeNode(6);
    TreeNode *n7 = newTreeNode(7);
    TreeNode *p = newTreeNode(0);
    // TreeNode *n8 = newTreeNode(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    n1->left = p;
    p->left = n2;

    int size;
    int *traversed_level = levelOrder(n1, &size);
    printf("The size of the traversed tree (array) is %d.\n", size);
    printf("The last of the array is %d.\n", traversed_level[7]);
    return 0;
}
