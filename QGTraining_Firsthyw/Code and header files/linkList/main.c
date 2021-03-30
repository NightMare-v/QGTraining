#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
    LinkedList head; // Head of LinkedList.
    head = NULL;
    int flag = 0; // Whether exist LinkedList.
    while (SUCCESS)
    {
        system("cls");
        printf("\n由于在命令行设置似乎好看的界面过于憨憨我就没搞了\n\n---------------------------\n");
        printf(">>> 1.制表.                \n");
        printf(">>> 2.显示表格.            \n");
        printf(">>> 3.初始化表格.          \n");
        printf(">>> 4.销毁表格.            \n");
        printf(">>> 5.插入数据.            \n");
        printf(">>> 6.删除数据.            \n");
        printf(">>> 7.搜索数据.            \n");
        printf(">>> 8.颠倒表格.            \n");
        printf(">>> 9.奇偶数颠倒.          \n");
        printf(">>> 10.寻找中间节点.       \n");
        printf(">>> 11.判断表格是否循环.   \n");
        printf(">>> 12.退出.               \n");
        printf("---------------------------\n");
        if (flag)
        {
            TraverseList(head, visit); // Print LinkedList.
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
                TraverseList(head, visit);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 3://已完成
            InitList(&head);
            flag = 0;
            break;
        case 4:
            if (flag)
            {
                DestroyList(&head);
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
                LinkedList p;
                p = head;
                for (int temp = 1; temp < i; temp++)
                {
                    p = p->next;
                    if (p == NULL)
                    {
                        printf("没有这样的位置，请重试\n");
                        break;
                    }
                }
                LinkedList q;
                q = (LinkedList)malloc(sizeof(LNode));
                q->data = x;
                InsertList(p, q);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 6://已完成
            if (flag)
            {
                ElemType x;
                printf("想在哪个位置删除数据吗? ");
                scanf("%d", &x);
                DeleteList(head, &x);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 7://已完成
            if (flag)
            {
               ElemType e;
                printf("想搜索哪个位置的数据? ");
                scanf("%d", &e);
                SearchList(head, e);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 8:
            if (flag)
            {
                ReverseList(&head);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 9://进行了修改，不懂既然要返回表为什么还要传地址去更改原表
            //功能8已成功运行，9为同等原理，由于懒得改回去了，干脆就一个一级指针一个二级指针吧
            if (flag)
            {
                head = ReverseEvenList(head);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 10://进行了与上同理的修改
            if (flag)
            {
                LinkedList mid, temp = head;
                mid = FindMidNode(head);
                if (LinkedList_length(head) % 2 == 0)
                {
                    printf("中间节点的数据是 %d\n", mid->data);
                }
                else // The length of LinkList is even.Print the middle two values of the LinkedList.
                {
                    while (temp->next != mid) // Find the middle node which is near the head node.
                    {
                        temp = temp->next;
                    }
                    printf("中间节点的数据是 %d 和 %d\n", temp->data, temp->next->data);
                }
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 11:
            if (flag)
            {
                IsLoopList(head);
            }
            else
            {
                printf("没有表格.\n");
            }
            break;
        case 12:
            exit(0);
        default:
            break;
        }
        system("pause");
    }
    return 0;
}