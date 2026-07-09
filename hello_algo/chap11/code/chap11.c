#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selectionSort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[k])
            {
                k = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}

void bubbleSort(int nums[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void bubbleSortWithFlag(int nums[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main()
{
    int nums[10];
    nums[0] = 111;
    nums[1] = 0;
    nums[2] = 11;
    nums[3] = 22;
    nums[4] = 12;
    nums[5] = 10;
    nums[6] = 1;
    nums[7] = 8;
    nums[8] = 21;
    nums[9] = 18;
    selectionSort(nums, 10);
    bubbleSort(nums, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("The sorted %dth item is: %d.\n", i, nums[i]);
    }
    return 0;
}
