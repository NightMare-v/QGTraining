#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
    DuLinkedList head; // Head of DuLinkedList.
    head = NULL;
    int flag = 0; // Whether exist DuLinkedList.
    while (SUCCESS)
    {
        system("cls");
        printf("\n���鿴������ͺã����˫����emm\n\n---------------------------\n");
        printf(">>> 1.�Ʊ�.                \n");
        printf(">>> 2.��ʾ���.            \n");
        printf(">>> 3.��ʼ�����.          \n");
        printf(">>> 4.���ٱ��.            \n");
        printf(">>> 5.β�巨��������.      \n");
        printf(">>> 6.ͷ�巨��������.      \n");
        printf(">>> 7.ɾ������.            \n");
        printf(">>> 8.�˳�.                \n");
        printf("---------------------------\n");
        if (flag)
        {
            TraverseList_DuL(head, visit); // Print DuLinkedList.
        }
        else
        {
            printf("û�б��.\n");
        }
        printf("---------------------------\n");
        printf("----->>> ���������ѡ��");
        switch (InputNumber())
        {
        case 1:
            head = Create();
            flag = 1;
            break;
        case 2://�����
            if (flag)
            {
                TraverseList_DuL(head, visit);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 3://�����
            InitList_DuL(&head);
            flag = 0;
            break;
        case 4:
            if (flag)
            {
                DestroyList_DuL(&head);
                flag = 0;
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 5://�����
            if (flag)
            {
                int i;
                ElemType x;
                printf("�����ĸ�λ�ò���������? ");
                scanf("%d", &i);
                printf("����������:");
                scanf("%d", &x);
                DuLinkedList p;
                p = head;
                for (int temp = 1; temp <= i; temp++)
                {
                    p = p->next;
                    if (p == NULL)
                    {
                        printf("û��������λ�ã�������\n");
                        break;
                    }
                }
                DuLinkedList q;
                q = (DuLinkedList)malloc(sizeof(DuLNode));
                q->data = x;
                InsertAfterList_DuL(p, q);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 6://�����
            if (flag)
            {
                int i;
                ElemType x;
                printf("�����Ĳ���������? ");
                scanf("%d", &i);
                printf("����������:");
                scanf("%d", &x);
                DuLinkedList p;
                p = head;
                for (int temp = 1; temp < i; temp++)
                {
                    p = p->next;
                    if (p==NULL)
                    {
                        printf("û��������λ�ã�������\n");
                        break;
                    }
                }
                DuLinkedList q;
                q = (DuLinkedList)malloc(sizeof(DuLNode));
                q->data = x;
                InsertBeforeList_DuL(p, q);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 7://�����
            if (flag)
            {
                ElemType x;
                printf("�����ĸ�λ��ɾ��������? ");
                scanf("%d", &x);
                DeleteList_DuL(head, &x);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 8:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
