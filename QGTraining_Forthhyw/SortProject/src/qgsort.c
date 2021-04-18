#include <stdio.h>
#include "../inc/qgsort.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)


//自定义的输出函数
void print(int a[], int n, int i) {
    if (i != -1)
    {
        printf("排序以下:\n%d:", i);
        for (int j = 0; a[j]; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    else
    {
        printf("排序以下:\n");
        for (int j = 0; a[j]; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}
//直接插入排序函数
void insertSort(int a[], int n)
{
    int i;
    for ( i = 1; a[i]; i++) {
        if (a[i] < a[i - 1]) {//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
            int j = i - 1;
            int x = a[i];
            while (j > -1 && x < a[j]) {  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;      //插入到正确位置
        }
        print(a, 10, i);
    }

}
//归并排序
/* 将序列对半拆分直到序列长度为1*/
void MergeSort(int* a, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (start >= end)
    {
        return;
    }

    MergeSort(a, start, mid);
    MergeSort(a, mid + 1, end);

    MergeArray(a, start, mid, end);
}

void MergeArray(int* a, int start, int mid, int end)
{
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));    //申请空间来存放两个有序区归并后的临时区域
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }

    //将临时区域中排序后的元素，整合到原数组中
    for (i = 0; a[i]!='\0'; i++)
    {
        a[start + i] = temp[i];
    }

    free(temp);
}


void QuickSort_Recursion(int* a, int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = a[low];
        while (i < j)
        {
            while (i < j && a[j] >= k)     // 从右向左找第一个小于k的数
            {
                j--;
            }

            if (i < j)
            {
                a[i++] = a[j];
            }

            while (i < j && a[i] < k)      // 从左向右找第一个大于等于k的数
            {
                i++;
            }

            if (i < j)
            {
                a[j--] = a[i];
            }
        }

        a[i] = k;

        // 递归调用
        QuickSort_Recursion(a, low, i - 1);     // 排序k左边
        QuickSort_Recursion(a, i + 1, high);    // 排序k右边
    }
}

void CountSort(int a[], int size)
{
    //计数数组，用于统计数组array中各个不同数出现的次数
    //由于数组array中的数属于0...RANDMAX-1之间，所以countArray的大小要够容纳RANDMAX个int型的值
    int* countArray = (int*)calloc(size, sizeof(int));
    //用于存放已经有序的数列
    int* sortedArray = (int*)calloc(size, sizeof(int));

    //统计数组array中各个不同数出现的次数，循环结束后countArray[i]表示数值i在array中出现的次数
    int index = 0;
    for (index = 0; index < size; ++index) {
        countArray[a[index]]++;
    }

    //统计数值比index小的数的个数，循环结束之后countArray[i]表示array中小于等于数值i的元素个数
    for (index = 1; index < size; ++index) {
        countArray[index] += countArray[index - 1];
    }

    for (index = size - 1; index >= 0; --index) {
        //因为数组的起始下标为0，所以要减一
        sortedArray[countArray[a[index]] - 1] = a[index];
        //这里减一是为了保证当有多个值为array[index]的元素时，后出现的值为array[index]的元素
        //放在后面，也就是为了保证排序的稳定性
        --countArray[a[index]];
    }

    memcpy(a, sortedArray, size * sizeof(int));
    free(sortedArray);
    free(countArray);
}

void ColorSort(int* a, int numsSize) {
    int i = 0, j = 0, k = numsSize - 1;
    int t = 0;
    for (i = 0; i <= k; i++) {
        if (a[i] == 0) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            j++;
        }
        else if (a[i] == 2) {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
            k--;
            i--;
        }
    }
}

int input_a(int a[])
{
    int i = 0;
    printf("输入过程中输入 \"/\" 退出输入\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d:", i + 1);
        a[i] = InputNumber();
        if (a[i] == -1)
        {
            a[i] = '\0';
            break;
        }
    }
    return i-1;
}

int InputNumber()
{
    int num = 0; // Store converted numbers.
    int status = 0; // Flag status.
    char str[100]; // Receive string.
    do
    {
        scanf("%s", str);
        status = 1;
        for (int i = 0; str[i] != '\0'; i++)
        {
            // Check for illegal characters.
            if (i == 0)
            {
                if (str[i] == '-' || str[i] == '+')
                    continue;
            }
            else
            {
                if (str[i] < '0' || str[i] > '9')
                {
                    status = 0;
                }
            }
        }
        if (status == 0)
        {
            printf("没有这种输入，请重试:");
        }
        else
        {
            int i = 0;
            // Convert string to number.
            for (i = 0, num = 0; str[i] != '\0'; i++)
            {
                if (i == 0)
                {
                    if (str[i] == '-' || str[i] == '+')
                    {
                        continue;
                    }
                    else
                    {
                        num *= 10;
                        num += (str[i] - 48);
                    }
                }
                else
                {
                    num *= 10;
                    num += (str[i] - 48);
                }
            }
            if (str[0] == '-')
            {
                num = -num;
            }
            // Check if the number entered is out of bounds.
            if (i >= 10)
            {
                printf("溢出，请重试\n");
                status = 1;
            }
        }
    } while (status == 0);
    return num;
}