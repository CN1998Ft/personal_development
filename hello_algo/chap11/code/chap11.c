#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

void merge(int *nums, int left, int mid, int right)
{
    int tmpSize = right - left + 1;
    int *tmp = (int *)malloc(sizeof(int) * tmpSize);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            tmp[k++] = nums[i++];
        }
        else
        {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = nums[i++];
    }
    while (j <= right)
    {
        tmp[k++] = nums[j++];
    }
    for (k = 0; k < tmpSize; ++k)
    {
        nums[left + k] = nums[j++];
    }
    free(tmp);
}

void mergeSort(int *nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
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

void siftDown(int nums[], int n, int i)
{
    while (1)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if (l < n && nums[l] > nums[ma])
        {
            ma = l;
        }
        if (r < n && nums[r] > nums[ma])
        {
            ma = r;
        }
        if (ma == i) break;
        int temp = nums[i];
        nums[i] = nums[ma];
        nums[ma] = temp;
        i = ma;
    }
}

void heapSort(int nums[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        siftDown(nums, n, i);
    }
    for (int i = n - 1; i > 0; --i)
    {
        int tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        siftDown(nums, i, 0);
    }
}

void bucketSort(float nums[], int n)
{
    int k = n / 2;
    int *sizes = malloc(k * sizeof(int));
    float **buckets = malloc(k * sizeof(float *));
    for (int i = 0; i < k; ++i)
    {
        buckets[i] = (float *)malloc(n * sizeof(float));
        sizes[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int idx = (int)(nums[i] * k);
        buckets[idx][sizes[idx]++] = nums[i];
    }
    for (int i = 0; i < k; ++i)
    {
        qsort(buckets[i], sizes[i], sizeof(float), compare);
    }

    int idx = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < sizes[i]; ++j)
        {
            nums[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

void countingSortNaive(int nums[], int size)
{

    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }
    int *counter = calloc(m + 1, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        counter[nums[i]]++;
    }
    int i = 0;
    for (int num = 0; num < m + 1; num++)
    {
        for (int j = 0; j < counter[num]; j++, i++)
        {
            nums[i] = num;
        }
    }
    free(counter);
}

void countingSort(int nums[], int size)
{
    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > m )
        {
            m = nums[i];
        }
    }
    int *counter = calloc(m, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        counter[nums[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        counter[i + 1] += counter[i];
    }
    int *res = malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--)
    {
        int num = nums[i];
        res[counter[num] - 1] = num;
        counter[num]--;
    }
    memcpy(nums, res, size * sizeof(int));
    free(res);
    free(counter);
}

int digit(int num, int exp)
{
    return (num / exp) % 10;
}

void countingSortDigit(int nums[], int size, int exp)
{
    int *counter = (int *)malloc(sizeof(int) * 10);
    memset(counter, 0, sizeof(int) * 10);
    for (int i = 0; i < size; i++)
    {
        int d = digit(nums[i], exp);
        counter[d]++;
    }
    for (int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];
    }
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--)
    {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
    for (int i = 0; i < size; i++)
    {
        nums[i] = res[i];
    }
    free(res);
    free(counter);
}

void radixSort(int nums[], int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    for (int exp = 1; max >= exp; exp *= 10)
    {
        countingSortDigit(nums, size, exp);
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
