#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
	// 初始化队列 	
	LQueue Q;
	int flag = 0;

	do {
		system("cls");
		printf("\n\n===========链式队列操作==========\n");
		printf("1.初始化循环队列\n");
		printf("2.元素入队\n");
		printf("3.元素出队\n");
		printf("4.销毁队列\n");
		printf("5.清空队列\n");
		printf("6.判断队列是否为空\n");
		printf("7.获取队列头元素\n");
		printf("8.获取队列长度\n");
		printf("0.退出\n");
		printf("=====================\n");
		TraverseLQueue(&Q, LPrint);
		printf("\n");
		printf("=====================\n");
		printf("请输入您的选择：");
		switch (InputNumber()) {
		case 1:
			InitLQueue(&Q);
			flag = 1;
			break;
		case 2:
		{
			if (flag)
			{
				int e;
				printf("请输入数据:");
				e = InputNumber();
				EnLQueue(&Q, e);
			}
			else				printf("没有队列\n");
			break;
		}
		case 3:
			if (flag)
			{
				DeLQueue(&Q);
			}
			else				printf("没有队列\n");
			break;
		case 4:
			if (flag)
			{
				DestoryLQueue(&Q);
				flag = 0;
			}
			else				printf("没有队列\n");
			break;
		case 5:
			if (flag)
			{
				ClearLQueue(&Q);
			}
			else				printf("没有队列\n");
			break;
		case 6:
			if (flag)
			{
				IsEmptyLQueue(&Q);
			}
			else				printf("没有队列\n");
			break;
		case 7:
			if (flag)
			{
				GetHeadLQueue(&Q, 1);
			}
			else				printf("没有队列\n");
			break;
		case 8:
			if (flag)
			{
				int e;
				e = LengthLQueue(&Q);
				printf("队列长度为%d\n", e);
			}
			else				printf("没有队列\n");
			break;
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