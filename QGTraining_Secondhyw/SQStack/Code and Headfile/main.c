#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
    int flag = 0; // There is no stack.
    SqStack* head = (SqStack*)malloc(sizeof(SqStack)); // Top pointer.
    head->elem = NULL;
    head->size = head->top = 0;
    while (1)
    {
        system("cls");
        printf("                    \n");
        printf("     �����               \n");
        printf("--------------------\n");
        printf(">>> 1.��ʼ��ջ      \n");
        printf(">>> 2.��ջ          \n");
        printf(">>> 3.��ջ          \n");
        printf(">>> 4.���ջ        \n");
        printf(">>> 5.����ջ        \n");
        printf(">>> 6.���ջ����    \n");
        printf(">>> 7.�ж�ջ�Ƿ�Ϊ��\n");
        printf(">>> 8.�õ�ջ��Ԫ��  \n");
        printf(">>> 9.�˳�          \n");
        printf("--------------------\n");
        printStack(head);
        printf("--------------------\n");
        printf("���������ѡ��");
        switch (InputNumber())
        {
            case 1:
            {
                head = (SqStack*)malloc(sizeof(SqStack));
                printf("����ջ�ĳ��ȣ�");
                initStack(head, InputNumber());
            }
            flag = 1;
            break;
            case 2:
                if (flag == 1)
                {
                    printf("��������Ҫ��ջ�����ݣ�");
                    pushStack(head, InputNumber());
                }
                else
                {
                    printf("����û��ջ�����ȳ�ʼ��ջ.\n");
                }
                break;
            case 3:
                if (flag == 1)
                {
                    ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                    popStack(head, e);
                }
                else
                {
                    printf("����û��ջ�����ȳ�ʼ��ջ.\n");
                }
                break;
            case 4:
                if (flag == 1)
                {
                    clearStack(head);
                }
                else
                {
                    printf("����û��ջ�����ȳ�ʼ��ջ.\n");
                }
                break;
            case 5:
                if (flag == 1)
                {
                    destroyStack(head);
                    flag = 0;
                }
                else
                {
                    printf("����û��ջ�����ȳ�ʼ��ջ.\n");
                }
                break;
            case 6:
            {
                int* length = (int*)malloc(sizeof(int));
                stackLength(head, length);
            }
            break;
            case 7:
                if (flag == 1)
                {
                    isEmptyStack(head);
                }
                else
                {
                    printf("����û��ջ.\n");
                }
                break;
            case 8:
                if (flag == 1)
                {
                    ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                    getTopStack(head, e);
                }
                else
                {
                    printf("����û��ջ.\n");
                }
                break;
            case 9:
            {
                exit(0);
            }
            default:
                printf("û��������ѡ��Ŷ.\n");
        }
        system("pause");
    }
}