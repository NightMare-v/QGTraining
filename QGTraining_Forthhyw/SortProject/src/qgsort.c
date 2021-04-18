#include <stdio.h>
#include "../inc/qgsort.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)


//�Զ�����������
void print(int a[], int n, int i) {
    if (i != -1)
    {
        printf("��������:\n%d:", i);
        for (int j = 0; a[j]; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    else
    {
        printf("��������:\n");
        for (int j = 0; a[j]; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}
//ֱ�Ӳ���������
void insertSort(int a[], int n)
{
    int i;
    for ( i = 1; a[i]; i++) {
        if (a[i] < a[i - 1]) {//���� i ��Ԫ�ش��� i-1 Ԫ����ֱ�Ӳ��룻��֮����Ҫ�ҵ��ʵ��Ĳ���λ�ú��ڲ��롣
            int j = i - 1;
            int x = a[i];
            while (j > -1 && x < a[j]) {  //����˳����ҷ�ʽ�ҵ������λ�ã��ڲ��ҵ�ͬʱ���������е�Ԫ�ؽ��к��Ʋ�����������Ԫ���ڳ��ռ�
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = x;      //���뵽��ȷλ��
        }
        print(a, 10, i);
    }

}
//�鲢����
/* �����ж԰���ֱ�����г���Ϊ1*/
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
    int* temp = (int*)malloc((end - start + 1) * sizeof(int));    //����ռ�����������������鲢�����ʱ����
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

    //����ʱ������������Ԫ�أ����ϵ�ԭ������
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
            while (i < j && a[j] >= k)     // ���������ҵ�һ��С��k����
            {
                j--;
            }

            if (i < j)
            {
                a[i++] = a[j];
            }

            while (i < j && a[i] < k)      // ���������ҵ�һ�����ڵ���k����
            {
                i++;
            }

            if (i < j)
            {
                a[j--] = a[i];
            }
        }

        a[i] = k;

        // �ݹ����
        QuickSort_Recursion(a, low, i - 1);     // ����k���
        QuickSort_Recursion(a, i + 1, high);    // ����k�ұ�
    }
}

void CountSort(int a[], int size)
{
    //�������飬����ͳ������array�и�����ͬ�����ֵĴ���
    //��������array�е�������0...RANDMAX-1֮�䣬����countArray�Ĵ�СҪ������RANDMAX��int�͵�ֵ
    int* countArray = (int*)calloc(size, sizeof(int));
    //���ڴ���Ѿ����������
    int* sortedArray = (int*)calloc(size, sizeof(int));

    //ͳ������array�и�����ͬ�����ֵĴ�����ѭ��������countArray[i]��ʾ��ֵi��array�г��ֵĴ���
    int index = 0;
    for (index = 0; index < size; ++index) {
        countArray[a[index]]++;
    }

    //ͳ����ֵ��indexС�����ĸ�����ѭ������֮��countArray[i]��ʾarray��С�ڵ�����ֵi��Ԫ�ظ���
    for (index = 1; index < size; ++index) {
        countArray[index] += countArray[index - 1];
    }

    for (index = size - 1; index >= 0; --index) {
        //��Ϊ�������ʼ�±�Ϊ0������Ҫ��һ
        sortedArray[countArray[a[index]] - 1] = a[index];
        //�����һ��Ϊ�˱�֤���ж��ֵΪarray[index]��Ԫ��ʱ������ֵ�ֵΪarray[index]��Ԫ��
        //���ں��棬Ҳ����Ϊ�˱�֤������ȶ���
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
    printf("������������� \"/\" �˳�����\n");
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
            printf("û���������룬������:");
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
                printf("�����������\n");
                status = 1;
            }
        }
    } while (status == 0);
    return num;
}