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
