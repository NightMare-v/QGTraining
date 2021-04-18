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
		printf("\n\n===========��ʽ���в���==========\n");
		printf("1.��������\n");
		printf("2.�鲢����\n");
		printf("3.��������\n");
		printf("4.��������(�ݽ���)\n");
		printf("5.��ɫ����(�ݽ���)\n");
		printf("0.�˳�\n");
		printf("=====================================\n");
		printf("����������ѡ��");
		switch (InputNumber())
		{
		case 1: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			insertSort(a, 10);
			end = clock();
			printf("�����ʱ%lfms\n", start - end);
			break;
		}
		case 2: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			MergeSort(a, 0, n);
			print(a, 10, -1);
			end = clock();
			printf("�����ʱ%lfms\n", start - end);
			break;
		}
		case 3: {
			n=input_a(a);
			clock_t start, end;
			start = clock();
			QuickSort_Recursion(a, 0, n);
			print(a, 10, -1);
			end = clock();
			printf("�����ʱ%lfms\n", start - end);
			break;
		}
		case 4: {
			printf("(�ݽ���)");
			break;
			n = input_a(a);
			clock_t start, end;
			start = clock();
			CountSort(a, n);
			print(a, 10, -1);
			end = clock();
			printf("�����ʱ%lfms\n", start - end);
			break;
		}
		case 5: {
			printf("(�ݽ���)");
			break;
			n = input_a(a);
			clock_t start, end;
			start = clock();
			ColorSort(a, n);
			print(a, 10, -1);
			end = clock();
			printf("�����ʱ%lfms\n", start - end);
			break;
		}
		case 0:
			printf("\n-->> �˳�\n");
			exit(0);
			break;
		default:
			printf("û��������ѡ��Ŷ.\n");
			break;
		}
		system("pause");
	} while (1);
}