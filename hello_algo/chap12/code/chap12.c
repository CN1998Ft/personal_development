#include <stdio.h>
#include <stdlib.h>

int dfs(int nums[], int target, int i, int j)
{
    if (i > j)
    {
        return -1;
    }
    int m = (i + j) / 2;
    if (nums[m] < target)
    {
        return dfs(nums, target, m + 1, j);
    }
    else if (nums[m] > target)
    {
        return dfs(nums, target, i, m - 1);
    }
    else
    {
        return m;
    }
}

TreeNode *dfs(int *preorder, int *inorderMap, int i, int l, int r, int size) {
    if (r - l < 0)
        return NULL;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = preorder[i];
    root->left = NULL;
    root->right = NULL;
    int m = inorderMap[preorder[i]];
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1, size);
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r, size);
    return root;
}

TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    int *inorderMap = (int *)malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i]] = i;
    }
    TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorderSize - 1, inorderSize);
    free(inorderMap);
    return root;
}

void move(int *src, int *srcSize, int *tar, int *tarSize)
{
    int pan = src[*srcSize - 1];
    src[*srcSize - 1] = 0;
    (*srcSize)--;
    tar[*tarSize] = pan;
    (*tarSize)++;
}

void dfs(int i, int *src, int *srcSize, int *buf, int *bufSize, int *tar, int *tarSize)
{
    if (i == 1)
    {
        move(src, srcSize, tar, tarSize);
        return;
    }
    dfs(i - 1, src, srcSize, tar, tarSize, buf, bufSize);
    move(src, srcSize, tar, tarSize);
    dfs(i - 1, buf, bufSize, src, srcSize, tar, tarSize);
}

void solveHanota(int *A, int *ASize, int *B, int *BSize, int *C, int *CSize)
{
    dfs(*ASize, A, ASize, B, BSize, C, CSize);
}

int main()
{
    printf("This is from chapter 12.\n");
    return 0;
}
