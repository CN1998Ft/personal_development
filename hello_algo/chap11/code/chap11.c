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

void insertionSort(int nums[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int nums[], int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[left])
        {
            j--;
        }
        while (i < j && nums[i] <= nums[left])
        {
            i++;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}

void quickSort(int nums[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

int medianThree(int nums[], int left, int mid, int right)
{
    int l = nums[left], m = nums[mid], r = nums[right];
    if ((l <= m && m <= r) || (r <= m && m <= l))
    {
        return mid;
    }
    if ((m <= l && l <= r) || (r <= l && l <= m))
    {
        return left;
    }
    return right;
}

int partitionMedian(int nums[], int left, int right)
{
    int med = medianThree(nums, left, (left + right) / 2, right);
    swap(nums, left, med);
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[left])
        {
            j--;
        }
        while (i < j && nums[i] <= nums[right])
        {
            i++;
        }
        swap(nums, i, j);
    }
    swap(nums, i, left);
    return i;
}

void quickSortTailCall(int nums[], int left, int right)
{
    while (left < right)
    {
        int pivot = partition(nums, left, right);
        if (pivot - left < right - pivot)
        {
            quickSortTailCall(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else
        {
            quickSortTailCall(nums, pivot + 1, right);
            right = pivot - 1;
        }
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
