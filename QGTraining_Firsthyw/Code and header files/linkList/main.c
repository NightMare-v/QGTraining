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
        printf("\n�����������������ƺ��ÿ��Ľ�����ں����Ҿ�û����\n\n---------------------------\n");
        printf(">>> 1.�Ʊ�.                \n");
        printf(">>> 2.��ʾ���.            \n");
        printf(">>> 3.��ʼ�����.          \n");
        printf(">>> 4.���ٱ��.            \n");
        printf(">>> 5.��������.            \n");
        printf(">>> 6.ɾ������.            \n");
        printf(">>> 7.��������.            \n");
        printf(">>> 8.�ߵ����.            \n");
        printf(">>> 9.��ż���ߵ�.          \n");
        printf(">>> 10.Ѱ���м�ڵ�.       \n");
        printf(">>> 11.�жϱ���Ƿ�ѭ��.   \n");
        printf(">>> 12.�˳�.               \n");
        printf("---------------------------\n");
        if (flag)
        {
            TraverseList(head, visit); // Print LinkedList.
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
                TraverseList(head, visit);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 3://�����
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
                LinkedList p;
                p = head;
                for (int temp = 1; temp < i; temp++)
                {
                    p = p->next;
                    if (p == NULL)
                    {
                        printf("û��������λ�ã�������\n");
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
                printf("û�б��.\n");
            }
            break;
        case 6://�����
            if (flag)
            {
                ElemType x;
                printf("�����ĸ�λ��ɾ��������? ");
                scanf("%d", &x);
                DeleteList(head, &x);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 7://�����
            if (flag)
            {
               ElemType e;
                printf("�������ĸ�λ�õ�����? ");
                scanf("%d", &e);
                SearchList(head, e);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 8:
            if (flag)
            {
                ReverseList(&head);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 9://�������޸ģ�������ȻҪ���ر�Ϊʲô��Ҫ����ַȥ����ԭ��
            //����8�ѳɹ����У�9Ϊͬ��ԭ���������øĻ�ȥ�ˣ��ɴ��һ��һ��ָ��һ������ָ���
            if (flag)
            {
                head = ReverseEvenList(head);
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 10://����������ͬ����޸�
            if (flag)
            {
                LinkedList mid, temp = head;
                mid = FindMidNode(head);
                if (LinkedList_length(head) % 2 == 0)
                {
                    printf("�м�ڵ�������� %d\n", mid->data);
                }
                else // The length of LinkList is even.Print the middle two values of the LinkedList.
                {
                    while (temp->next != mid) // Find the middle node which is near the head node.
                    {
                        temp = temp->next;
                    }
                    printf("�м�ڵ�������� %d �� %d\n", temp->data, temp->next->data);
                }
            }
            else
            {
                printf("û�б��.\n");
            }
            break;
        case 11:
            if (flag)
            {
                IsLoopList(head);
            }
            else
            {
                printf("û�б��.\n");
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