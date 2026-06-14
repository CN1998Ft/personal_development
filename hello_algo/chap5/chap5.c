#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define INT_MAX_hello  2
#define MAX_SIZE 20

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    // struct ListNode *prev;
} ListNode;

ListNode *newListNode(int val)
{
    ListNode *node = malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = val;
    return node;
}

typedef struct
{
    ListNode *top;
    int size;
} LinkedListStack;

LinkedListStack *newLinkedListStack()
{
    LinkedListStack *s = malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void delLinkedListStack(LinkedListStack *s)
{
    while (s->top)
    {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}

int size_l(LinkedListStack *s)
{
    return s->size;
}

bool isEmpty_l(LinkedListStack *s)
{
    return size_l(s) == 0;
}

void push_l(LinkedListStack *s, int num)
{
    ListNode *n = (ListNode *)malloc(sizeof(ListNode));
    n->next = s->top;
    n->val = num;
    s->top = n;
    s->size++;
}

int peek_l(LinkedListStack *s)
{
    if (s->size == 0)
    {
        printf("Stack is empty.\n");
        return INT_MAX_hello;
    }
    return s->top->val;
}

int pop_l(LinkedListStack *s)
{
    int val = peek_l(s);
    ListNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return val;
}

typedef struct
{
    int *data;
    int size;
} ArrayStack;

ArrayStack *newArrayStack()
{
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    stack->data = malloc(sizeof(int) * MAX_SIZE);
    stack->size = 0;
    return stack;
}

void delArrayStack(ArrayStack *stack)
{
    free(stack->data);
    free(stack);
}

int size_a(ArrayStack *stack)
{
    return stack->size;
}

bool isEmpty_a(ArrayStack *stack)
{
    return stack->size == 0;
}

void push_a(ArrayStack *stack, int num)
{
    if (stack->size == MAX_SIZE)
    {
        printf("The stack is full.\n");
        return;
    }
    stack->data[stack->size] = num;
    stack->size++;
}

int peek_a(ArrayStack *stack)
{
    if (stack->size == 0)
    {
        printf("Stack is empty.\n");
        return INT_MAX_hello;
    }
    return stack->data[stack->size - 1];
}

int pop_a(ArrayStack *stack)
{
    int val = peek_a(stack);
    stack->size--;
    return val;
}

typedef struct
{
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

LinkedListQueue *newLinkedListQueue()
{
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;
    return queue;
}

void delLinkedListQueue(LinkedListQueue *queue)
{
    while (queue->front != NULL)
    {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    free(queue);
}

int size_lq(LinkedListQueue *queue)
{
    return queue->queSize;
}

bool empty_lq(LinkedListQueue *queue)
{
    return (size_lq(queue) == 0);
}

void push_lq(LinkedListQueue *queue, int num)
{
    ListNode *node = newListNode(num);
    if (queue->front == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize++;
}

int peek_lq(LinkedListQueue *queue)
{
    assert(size_lq(queue) && queue->front);
    return queue->front->val;
}

int pop_lq(LinkedListQueue *queue)
{
    int num = peek_lq(queue);
    ListNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    queue->queSize--;
    return num;
}

// void printLinkedListQueue(LinkedListQueue *queue)
// {
//     int *arr = malloc(sizeof(int) * queue->queSize);
//     int i;
//     ListNode *node;
//     for (i = 0, node = queue->front; i < queue->queSize; i++)
//     {
//         arr[i] = node->val;
//         node = node->next;
//     }
//     printArray(arr, queue->queSize);
//     free(arr);
// }

typedef struct
{
    int *nums;
    int front;
    int queSize;
    int queCapacity;
} ArrayQueue;

ArrayQueue *newArrayQueue(int capacity)
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->queCapacity = capacity;
    queue->nums = (int *)malloc(sizeof(int) * queue->queCapacity);
    queue->front = queue->queSize = 0;
    return queue;
}

void delArrayQueue(ArrayQueue *queue)
{
    free(queue->nums);
    free(queue);
}

int capacity_aq(ArrayQueue *queue)
{
    return queue->queCapacity;
}

int size_aq(ArrayQueue *queue)
{
    return queue->queSize;
}

bool empty_aq(ArrayQueue *queue)
{
    return queue->queSize == 0;
}

int peek_aq(ArrayQueue *queue)
{
    assert(size_aq(queue) != 0);
    return queue->nums[queue->front];
}

void push_aq(ArrayQueue *queue, int num)
{
    if (size_aq(queue) == capacity_aq(queue))
        {
            printf("The queue is full.\n");
            return;
        }
    int rear = (queue->front * queue->queSize) % queue->queCapacity;
    queue->nums[rear] = num;
    queue->queSize++;
}

int pop_aq(ArrayQueue *queue)
{
    int num = peek_aq(queue);
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize--;
    return num;
}

int *toArray(ArrayQueue *queue, int *queSize)
{
    *queSize = queue->queSize;
    int *res = (int *)calloc(queue->queSize, sizeof(int));
    int j = queue->front;
    for (int i = 0; i < queue->queSize; i++)
    {
        res[i] = queue->nums[j % queue->queCapacity];
        j++;
    }
    return res;
}

int main()
{
    printf(" =========== This is the Linked List Stack section. =========== \n");
    LinkedListStack *Stack = newLinkedListStack();
    for (int i = 0; i < 10; i++)
    {
        push_l(Stack, i);
    }
    printf("The size of the Stack is: %d.\n", size_l(Stack));
    int size_stack = size_l(Stack);

    for (int i = 0; i < size_stack; i++)
    {
        int x = pop_l(Stack);
        printf("The %dth popped value is: %d.\n", i, x);
    }

    printf("\n =========== This is the Array Stack section. =========== \n");

    ArrayStack *Stack_a = newArrayStack();
    for (int i = 0; i < 10; i++)
    {
        push_a(Stack_a, i);
    }
    printf("The size of the Stack array version is: %d.\n", size_a(Stack_a));
    int size_stack_array = size_a(Stack_a);

    for (int i = 0; i < size_stack_array; i++)
    {
        int x = pop_a(Stack_a);
        printf("The %dth popped value is: %d.\n", i, x);
    }

    printf("\n =========== This is the List Queue section. =========== \n");
    LinkedListQueue *queue = newLinkedListQueue();

    int i = 0;
    while ( i < 20 )
    {
        push_lq(queue, i);
        i += 2;
    }
    int size_LQ = size_lq(queue);
    printf("The size of the List Queue is: %d.\n", size_LQ);

    for (int i = 0; i < size_LQ; i++)
    {
        int x = pop_lq(queue);
        printf("The %dth popped value is: %d.\n", i, x);
    }

    printf("\n =========== This is the List Queue section. =========== \n");
    ArrayQueue *queue_a = newArrayQueue(20);

    int i_aq = 0;
    while ( i_aq < 20 )
    {
        push_aq(queue_a, i_aq);
        printf("The value pushed in is: >>>%d<<<.\n", i_aq);
        i_aq += 2;
    }
    int size_AQ = size_aq(queue_a);
    printf("The size of the List Queue is: %d.\n", size_LQ);

    for (int i = 0; i < size_AQ; i++)
    {
        int x = pop_aq(queue_a);
        printf("The %dth popped value is: %d.\n", i, x);
    }

    return 0;
}
