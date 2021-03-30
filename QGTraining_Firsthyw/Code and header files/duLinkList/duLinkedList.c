#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    if ((*L)!=NULL)
    {
        printf("�ɹ���ʼ������.\n");
        return ERROR;
    }
    *L = (DuLinkedList*)malloc(sizeof(DuLNode));
    if ((*L) == NULL)
    {
        return OVERFLOW;
    }
    (*L)->next = NULL;
    printf("�ɹ���ʼ������.\n");

    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p;
    p = (*L);
    while (p != NULL)
    {
        p = p->next;
        free(*L);
        *L = p;
    }
    printf("�ɹ���������.\n");
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL)
    {
        printf("���˵����⡣\n������ܲ����ڣ�����ֻ��һ���ڵ�,��������λ�ô���\n");
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    p->next->prior = q->prior;
    q->prior = p->prior;
    printf("�ɹ���������\n");
    return SUCCESS;
}//�޸�
//���ڱ������½ڵ���������Ǳߴ�ò�û�д����������������Ҫ���½ڵ���Ƶöഫ�����ݣ���û����
//����ͷ�巨˼·Ϊ���������ҽڵ㣬���½ڵ㣬��ڵ�next�����½ڵ㣬�½ڵ�next�����ҽڵ㡣

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p == NULL)
    {
        printf("���˵����⡣\n������ܲ����ڣ�����ֻ��һ���ڵ㡣\n");
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    p->next->prior = q->prior;
    q->prior = p->prior;
    printf("�ɹ���������\n");
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    DuLinkedList L = (DuLinkedList)malloc(sizeof(DuLNode));
    L = p;
    if (L == NULL || L->next == NULL)
    {
        return ERROR;
    }
    DuLinkedList q;
    q = L->next;
    while (q->data != *e)
    {
        p = q;
        q = q->next;
        if (q->next == NULL)
        {
            printf("����û��������λ�ã�������\n");
            return ERROR;
        }
    }
    p->next = q->next;
    q->next->prior = p->prior;
    free(q);
    printf("�ɹ�ɾ���ڵ�.\n");
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

void visit(ElemType e)
{
    printf("%d<-->", e);
}

int InputNumber()
{
    int num = 0; // Store converted numbers.
    int status = 0; // Flag status.
    char str[100]; // Receive string.
    do
    {
        scanf("%s", str);
        status = SUCCESS;
        for (int i = 0; str[i] != '\0'; i++)
        {
            // Check for illegal characters.
            if (i == 0)
            {
                if (str[i] == '-' || str[i] == '+')
                    continue;
            }
            else
            {
                if (str[i] < '0' || str[i] > '9')
                {
                    status = ERROR;
                }
            }
        }
        if (status == ERROR)
        {
            printf("\nû���������룬������:");
        }
        else
        {
            int i = 0;
            // Convert string to number.
            for (i = 0, num = 0; str[i] != '\0'; i++)
            {
                if (i == 0)
                {
                    if (str[i] == '-' || str[i] == '+')
                    {
                        continue;
                    }
                    else
                    {
                        num *= 10;
                        num += (str[i] - 48);
                    }
                }
                else
                {
                    num *= 10;
                    num += (str[i] - 48);
                }
            }
            if (str[0] == '-')
            {
                num = -num;
            }
            // Check if the number entered is out of bounds.
            if (i >= 10)
            {
                printf("�����������:");
                status = ERROR;
            }
        }
    } while (status == ERROR);
    return num;
}

int DuLinkedList_length(DuLinkedList L)
{
    int k = 0;
    while (L != NULL)
    {
        k++;
        L = L->next;
    }
    return k;
}

void* Create()
{
    DuLinkedList head;
    DuLinkedList p, s;
    ElemType x, cycle = 1;
    head = (DuLinkedList)malloc(sizeof(DuLNode));
    p = head;
    while (cycle)
    {
        printf("���������ݣ�����������˳���:");
        if (scanf("%d", &x) == 1)
        {
            s = (DuLinkedList)malloc(sizeof(DuLNode));
            s->data = x;
            p->next = s;
            p = s;
        }
        else
        {
            cycle = 0;
        }
    }
    printf("�ɹ���������\n");
    p->next = NULL;
    return head;
}
