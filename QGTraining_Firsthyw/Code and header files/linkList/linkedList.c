#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    if ((*L)!=NULL)
    {
        printf("�ɹ���ʼ������.\n");
        return ERROR;
    }
    *L = (LinkedList*)malloc(sizeof(LNode));
    if (*L == NULL)
    {
        return OVERFLOW;
    }
    (*L)->next = NULL;
    printf("�ɹ���ʼ������.\n");

    return SUCCESS;
}//�����

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L) {
    LinkedList p;
    p = (*L);
    while (p != NULL)
    {
        p = p->next;
        free(*L);
        *L = p;
    }
    printf("�ɹ���������.\n");
}//�����

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL)
    {
        printf("���˵����⡣\n������ܲ����ڣ�����ֻ��һ���ڵ㡣\n");
        return ERROR;
    }
    q->next = p->next;
    p->next = q;
    printf("�ɹ���������\n");
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList L = (LinkedList)malloc(sizeof(LNode));
    L = p;
    if (L == NULL || L->next == NULL)
    {
        printf("���˵�����.\n");
        return ERROR;
    }
    LinkedList q;
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
    free(q);
    printf("�ɹ�ɾ���ڵ�.\n");
    return SUCCESS;
}//�����

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    LinkedList p = L->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

void visit(ElemType e)
{
    printf("%d->", e);
}
//˵ʵ������ҿ�����
//δ�Ķ�������


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if (L == NULL || L->next == NULL)
    {
        printf("���˵�����.\n������ܲ����ڣ�����ֻ��һ���ڵ�.\n");
        return ERROR;
    }
    int j = 1;
    LinkedList p = L->next;
    if (e == 1)
    {
        return ERROR;
    }
    if (e <= 1)
    {
        return ERROR;
    }
    while (p && e > j)
    {
        p = p->next;
        j++;
        if (p == NULL)
        {
            printf("δ�ҵ����ݣ�������\n");
            return ERROR;
        }
    }
    printf("���ҵ����� %d.\n", p->data);
    return SUCCESS;
}//���޸�

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L) {
    if (L == NULL)
    {
        printf("���˵�����.\n������ܲ�����.\n");
        return ERROR;
    }
    LinkedList p,  q,  r;
    p = (*L)->next;
    (*L)->next = NULL;
    q = r = NULL;
    while (p) {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    (*L)->next = r;
    return SUCCESS;
}//�����

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if (L == NULL || L->next == NULL)
    {
        printf("���˵�����.\n������ܲ����ڣ�����ֻ��һ���ڵ�.\n");
        return ERROR;
    }
    LinkedList fast, slow;
    slow = L;
    fast = L->next;
    while (1)
    {
        if (!fast || !fast->next)
        {
            printf("�ⲻ��ѭ������.\n");
            return SUCCESS;
        }
        else if (fast == slow || fast->next == slow)
        {
            printf("����һ��ѭ������.\n");
            return SUCCESS;
        }
        else
        {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
}//�����

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList L) {
    LinkedList cur = L->next;  //Ŀǰ�ڵ�
    LinkedList pre;             //ǰ�ڵ�
    LinkedList phead = (LinkedList*)malloc(sizeof(LNode));
    phead->next = NULL;
    LinkedList ph = phead;

    while (cur && cur->next)
    {
        pre = cur;
        ph->next = pre->next; // First point to the second node in two groups.
        ph = ph->next; // Move ph pointer.  �����ڵ�����˵ߵ�
        cur = cur->next->next; // Move the cur pointer for the next round of swaps.   �����˵������������ڶ�������
        ph->next = pre; // Point to the first node in two sets.   �ڶ���������ż����Ϊ����������
        ph = ph->next; // Move ph pointer.      
    }
    ph->next = cur; // Finally point to the remaining element if cur is NULL or odd.
    return phead;
}//�����

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList L) {
    if (L == NULL || L->next == NULL)
    {
        return L;
    }
    LinkedList fast,  slow;
    fast = slow = L;
    while (fast != NULL)
    {
        if (fast->next == NULL)
        {
            fast = fast->next;
        }
        else
        {
            fast = fast->next->next;
        }
        slow = slow->next;
    }
    return slow;
}//�����


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

int LinkedList_length(LinkedList L)
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
    LinkedList head;
    LinkedList p, s;
    ElemType x, cycle = 1;
    head = (LinkedList)malloc(sizeof(LNode));
    p = head;
    while (cycle)
    {
        printf("���������ݣ�����������˳���:");
        if (scanf("%d", &x) == 1)
        {
            s = (LinkedList)malloc(sizeof(LNode));
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
