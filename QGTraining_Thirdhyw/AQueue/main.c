#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
	// ��ʼ������ 	
	AQueue Q;
	int flag = 0;

	do {
		system("cls");
		printf("\n\n===========ѭ�����в���==========\n");
		printf("1.��ʼ��ѭ������\n");
		printf("2.Ԫ�����\n");
		printf("3.Ԫ�س���\n");
		printf("4.���ٶ���\n");
		printf("5.��ն���\n");
		printf("6.�ж϶����Ƿ�Ϊ��\n");
		printf("7.�ж϶����Ƿ�����\n");
		printf("8.��ȡ����ͷԪ��\n");
		printf("9.��ȡ���г���\n");
		printf("0.�˳�\n");
		printf("=====================\n");
		TraverseAQueue(&Q, APrint);
		printf("\n");
		printf("=====================\n");
		printf("����������ѡ��");
		switch (InputNumber()) {
		case 1:
			InitAQueue(&Q);
			flag = 1;
			break;
		case 2:
		{
			if (flag)
			{
				int e;
				printf("����������:");
				e = InputNumber();
				EnAQueue(&Q, e);
			}
			else				printf("û�ж���\n");
			break;
		}
		case 3:
			if (flag)
			{
				DeAQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 4:
			if (flag)
			{
				DestoryAQueue(&Q);
				flag = 0;
			}
			else				printf("û�ж���\n");
			break;
		case 5:
			if (flag)
			{
				ClearAQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 6:
			if (flag)
			{
				IsEmptyAQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 7:
			if (flag)
			{
				IsFullAQueue(&Q);
			}
			else				printf("û�ж���\n");
			break;
		case 8:
			if (flag)
			{
				GetHeadAQueue(&Q, 1);
			}
			else				printf("û�ж���\n");
			break;
		case 9:
			if (flag)
			{
				int e;
				e=LengthAQueue(&Q);
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