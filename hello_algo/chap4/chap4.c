#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

ListNode *newListNode(int val)
{
    ListNode *node;
    node = (ListNode *) malloc(sizeof(ListNode));
    node->val = val;
    // Manually build the reference between each node.
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// void insert(ListNode *n0, ListNode *p)
// {
//     ListNode *n1 = n0->next;
//     p->next = n1;
//     n0->next = p;
// }

// void removeItem(ListNode *n0)
// {
//     // Remove the first node after n0
//     if (!n0->next)
//     {
//         return;
//     }
//     ListNode *p = n0->next;
//     ListNode *n1 = p->next;
//     n0->next = n1;
//     free(p);
// }

ListNode *access(ListNode *head, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (head == NULL)
        {
            return NULL;
        }
        head = head->next;
    }
    return head;
}

int find(ListNode *head, int target)
{
    int index = 0;
    while (head)
    {
        if (head->val == target)
        {
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}

typedef struct {
    int *arr;
    int capacity;
    int size;
    int extendRatio;
} MyList;

MyList *newMyList()
{
    MyList *nums = malloc(sizeof(MyList));
    nums->capacity = 10;
    nums->arr = malloc(sizeof(int) * nums->capacity);
    nums->size = 0;
    nums->extendRatio = 2;
    return nums;
}

void delMyList(MyList *nums)
{
    free(nums->arr);
    free(nums);
}

int size(MyList *nums)
{
    return nums->size;
}

int capacity(MyList *nums)
{
    return nums->capacity;
}

int get(MyList *nums, int index)
{
    assert(index >= 0 && index < nums->size);
    return nums->arr[index];
}

void set(MyList *nums, int index, int num)
{
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = num;
}

void extendCapacity(MyList *nums)
{
    int newCapacity = capacity(nums) * nums->extendRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;

    for (int i = 0; i < size(nums); i++)
    {
        extend[i] = nums->arr[i];
    }
    free(temp);

    nums->arr = extend;
    nums->capacity = newCapacity;
}

void add(MyList *nums, int num)
{
    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }
    nums->arr[size(nums)] = num;
    nums->size++;
}

void insert(MyList *nums, int index, int num)
{
    assert(index >= 0 && index < size(nums));
    if (size(nums) == capacity(nums))
    {
        extendCapacity(nums);
    }
    for (int i = size(nums); i > index; --i)
    {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size++;
}

int removeItem(MyList *nums, int index)
{
    assert(index >= 0 && index < size(nums));
    int num = nums->arr[index];
    for (int i = index; i < size(nums) - 1; i++)
    {
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size--;
    return num;
}

int *toArray(MyList *nums)
{
    return nums->arr;
}

int main() {
    printf("Testing from chap4.\n");

    ListNode* n0 = newListNode(1);
    ListNode* n1 = newListNode(3);
    ListNode* n2 = newListNode(2);
    ListNode* n3 = newListNode(5);
    ListNode* n4 = newListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printf("The value of n1 is: %d.\n", n0->next->val);

    MyList *newList = newMyList();
    printf("The size of the new list is %d.\n",size(newList));

    return 0;
}
