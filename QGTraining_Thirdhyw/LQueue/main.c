#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
	// ��ʼ������ 	
	LQueue Q;
	int flag = 0;

	do {
		system("cls");
		printf("\n\n===========��ʽ���в���==========\n");
		printf("1.��ʼ��ѭ������\n");
		printf("2.Ԫ�����\n");
		printf("3.Ԫ�س���\n");
		printf("4.���ٶ���\n");
		printf("5.��ն���\n");
		printf("6.�ж϶����Ƿ�Ϊ��\n");
		printf("7.��ȡ����ͷԪ��\n");
		printf("8.��ȡ���г���\n");
		printf("0.�˳�\n");
		printf("=====================\n");
		TraverseLQueue(&Q, LPrint);
		printf("\n");
		printf("=====================\n");
		printf("����������ѡ��");
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
				printf("����������:");
				e = InputNumber();
				EnLQueue(&Q, e);
			}
			else				printf("û�ж���\n");
			break;
		}
		case 3:
			if (flag)
			{
				DeLQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 4:
			if (flag)
			{
				DestoryLQueue(&Q);
				flag = 0;
			}
			else				printf("û�ж���\n");
			break;
		case 5:
			if (flag)
			{
				ClearLQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 6:
			if (flag)
			{
				IsEmptyLQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 7:
			if (flag)
			{
				GetHeadLQueue(&Q, 1);
			}
			else				printf("û�ж���\n");
			break;
		case 8:
			if (flag)
			{
				int e;
				e = LengthLQueue(&Q);
				printf("���г���Ϊ%d\n", e);
			}
			else				printf("û�ж���\n");
			break;
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