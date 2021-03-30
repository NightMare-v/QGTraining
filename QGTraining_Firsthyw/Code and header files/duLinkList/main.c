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
        printf("\n建议看单链表就好，这个双链表emm\n\n---------------------------\n");
        printf(">>> 1.制表.                \n");
        printf(">>> 2.显示表格.            \n");
        printf(">>> 3.初始化表格.          \n");
        printf(">>> 4.销毁表格.            \n");
        printf(">>> 5.尾插法插入数据.      \n");
        printf(">>> 6.头插法插入数据.      \n");
        printf(">>> 7.删除数据.            \n");
        printf(">>> 8.退出.                \n");
        printf("---------------------------\n");
        if (flag)
        {
            TraverseList_DuL(head, visit); // Print DuLinkedList.
        }
        else
        {
            printf("没有表格.\n");
        }
        printf("---------------------------\n");
        printf("----->>> 请输入你的选择：");
        switch (InputNumber())
        {
        case 1:
            head = Create();
            flag = 1;
            break;
        case 2://已完成
            if (flag)
            {
                TraverseList_DuL(head, visit);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 3://已完成
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
                printf("没有表格.\n");
            }
            break;
        case 5://已完成
            if (flag)
            {
                int i;
                ElemType x;
                printf("想在哪个位置插入数据吗? ");
                scanf("%d", &i);
                printf("请输入数据:");
                scanf("%d", &x);
                DuLinkedList p;
                p = head;
                for (int temp = 1; temp <= i; temp++)
                {
                    p = p->next;
                    if (p == NULL)
                    {
                        printf("没有这样的位置，请重试\n");
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
                printf("没有表格.\n");
            }
            break;
        case 6://已完成
            if (flag)
            {
                int i;
                ElemType x;
                printf("想在哪插入数据吗? ");
                scanf("%d", &i);
                printf("请输入数据:");
                scanf("%d", &x);
                DuLinkedList p;
                p = head;
                for (int temp = 1; temp < i; temp++)
                {
                    p = p->next;
                    if (p==NULL)
                    {
                        printf("没有这样的位置，请重试\n");
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
                printf("没有表格.\n");
            }
            break;
        case 7://已完成
            if (flag)
            {
                ElemType x;
                printf("想在哪个位置删除数据吗? ");
                scanf("%d", &x);
                DeleteList_DuL(head, &x);
            }
            else
            {
                printf("没有表格.\n");
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
