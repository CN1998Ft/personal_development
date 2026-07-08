#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 0; i < 10; i++)
    {
        printf("The sorted %dth item is: %d.\n", i, nums[i]);
    }
    return 0;
}
