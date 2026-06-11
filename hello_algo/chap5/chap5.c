#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int INT_MAX = 2;
const int MAX_SIZE = 20;

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    // struct ListNode *prev;
} ListNode;

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
        return INT_MAX;
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
        return INT_MAX;
    }
    return stack->data[stack->size - 1];
}

int pop_a(ArrayStack *stack)
{
    int val = peek_a(stack);
    stack->size--;
    return val;
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
    return 0;
}
