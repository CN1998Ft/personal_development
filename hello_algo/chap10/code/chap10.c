#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *num, int len, int target)
{
    int i = 0, j = len - 1;
    while ( i <= j)
    {
        int m = i + (j - i) / 2; // To avoid the i + j exceed the int max value.
        if (num[m] < target)
        {
            i  = m + 1;
        }
        else if (num[m] > target)
        {
            j = m - 1;
        }
        else
        {
            return m;
        }
    }
    printf("The %d is not found in the list.\n", target);
    return -1;
}

int binarySearchLCRO(int *num, int len, int target)
{
    int i = 0, j = len;
    while ( i < j)
    {
        int m = i + (j - i) / 2; // To avoid the i + j exceed the int max value.
        if (num[m] < target)
        {
            i  = m + 1;
        }
        else if (num[m] > target)
        {
            j = m - 1;
        }
        else
        {
            return m;
        }
    }
    printf("The %d is not found in the list.\n", target);
    return -1;
}

int binarySearchInsertionSimple(int *nums, int numSize, int target)
{
    int i = 0, j = numSize - 1;
    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (nums[m] < target)
        {
            i = m + 1;
        }
        else if (nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            return m;
        }
    }
    return i;
}

int binarySearchInsertion(int *nums, int numSize, int target)
{
    int i = 0, j = numSize - 1;
    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (nums[m] < target)
        {
            i = m + 1;
        }
        else if (nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return i;
}

int binarySearchLeftEdge(int *nums, int numSize, int target)
{
    int i = binarySearchInsertion(nums, numSize, target);
    if (i == numSize || nums[i] != target) return -1;
    return i;
}

int binarySearchRightEdge(int *nums, int numSize, int target)
{
    int i = binarySearchInsertion(nums, numSize, target+1);
    int j = i - 1;
    if (j == -1 || nums[i] != target) return -1;
    return j;
}

int *twoSumBruteForce(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++i)
        {
            if (nums[i] + nums[j] == target)
            {
                int *res = malloc(sizeof(int) * 2);
                res[0] = i, res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} HashTable;

HashTable *find(HashTable *h, int key)
{
    HashTable *tmp;
    HASH_FIND_INT(h, &key, tmp);
    return tmp;
}

void insert(HashTable **h, int key, int val)
{
    HashTable *t = find(*h, key);
    if (t == NULL)
    {
        HashTable *tmp = malloc(sizeof(HashTable));
        tmp->key = key, tmp->val = val;
        HASH_ADD_INT(*h, key, tmp);
    }
    else
    {
        t->val = val;
    }
}

int *twoSumHashTable(int *nums, int numsSize, int target, int *returnSize)
{
    HashTable *hashtable = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        HashTable *t = find(hashtable, target - nums[i]);
        if (t != NULL)
        {
            int *res = malloc(sizeof(int) * 2);
            res[0] = t->val, res[1] = i;
            *returnSize = 2;
            return res;
        }
        insert(&hashtable, nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[12];
    nums[1] = 3;
    nums[2] = 4;
    nums[3] = 5;
    nums[4] = 6;
    nums[5] = 7;
    nums[6] = 8;
    nums[7] = 9;
    nums[8] = 10;
    nums[9] = 11;
    nums[10] = 12;
    nums[11] = 13;
    int target = 8;
    int len = sizeof(nums) / 4;
    printf("%d\n", len);
    int target_index;
    target_index = binarySearch(nums, len, target);
    printf("Found the target_index: %d.\n", target_index);
    int itarget_index;
    itarget_index = binarySearchLCRO(nums, len, target);
    printf("Found the target_index: %d.\n", itarget_index);
    return 0;
}
