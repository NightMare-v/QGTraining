#include <stdio.h>
#include <time.h>
#include "../inc/qgsort.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main() 
{
	int a[10] = { 0 };
	int n = 0;
	do
	{
		system("cls");
		printf("\n\n===========链式队列操作==========\n");
		printf("1.插入排序\n");
		printf("2.归并排序\n");
		printf("3.快速排序\n");
		printf("4.计数排序(暂禁用)\n");
		printf("5.颜色排序(暂禁用)\n");
		printf("0.退出\n");
		printf("=====================================\n");
		printf("请输入您的选择：");
		switch (InputNumber())
		{
		case 1: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			insertSort(a, 10);
			end = clock();
			printf("程序耗时%lfms\n", start - end);
			break;
		}
		case 2: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			MergeSort(a, 0, n);
			print(a, 10, -1);
			end = clock();
			printf("程序耗时%lfms\n", start - end);
			break;
		}
		case 3: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			QuickSort_Recursion(a, 0, n);
			print(a, 10, -1);
			end = clock();
			printf("程序耗时%lfms\n", start - end);
			break;
		}
		case 4: {
			printf("(暂禁用)");
			break;
			n = input_a(a);
			clock_t start, end;
			start = clock();
			CountSort(a, n);
			print(a, 10, -1);
			end = clock();
			printf("程序耗时%lfms\n", start - end);
			break;
		}
		case 5: {
			printf("(暂禁用)");
			break;
			n = input_a(a);
			clock_t start, end;
			start = clock();
			ColorSort(a, n);
			print(a, 10, -1);
			end = clock();
			printf("程序耗时%lfms\n", start - end);
			break;
		}
		case 0:
			printf("\n-->> 退出\n");
			exit(0);
			break;
		default:
			printf("没有这样的选项哦.\n");
			break;
		}
		system("pause");
	} while (1);
}