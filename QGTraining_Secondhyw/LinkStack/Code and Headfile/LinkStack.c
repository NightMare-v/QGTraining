#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

StackNode* bottom = NULL;
// LinkStack.
Status initLStack(LinkStack* s)
{
	s->count = 0;
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->data = NULL ;
	s->top->next = NULL;
	bottom = s->top;
	printf("�ɹ���ʼ��ջ.\n");
	return SUCCESS;
}

Status pushLStack(LinkStack* s, ElemType data)
{
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = data;
	p->next = NULL;
	s->top->next = p;
	s->top = p;
	s->count++;
	printf("�ɹ��� %d ��ջ.\n", data);
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)
{
	StackNode* p = bottom;
	if (s->count == 0)
	{
		printf("ջ�ǿյ�.\n");
		return ERROR;
	}
	else
	{
		*data = s->top->data;
		for (; p; p = p->next) {
			if (p->next == s->top) {
				free(p->next);
				p->next = NULL;
				s->top = p;
				s->count--;
				break;
			}
		}
		printf("�ɹ��� %d ��ջ.\n", *data);
		return SUCCESS;
	}
}

//7
Status isEmptyLStack(LinkStack* s)
{
    if (s->count == 0)
    {
        printf("ջ�ǿյ�.\n");
        return SUCCESS;
    }
    printf("ջ���ǿյ�.\n");
    return ERROR;
}

//8
Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (s->top == NULL)
    {
        printf("����û��ջ����ջ�ǿյ�.\n");
        return ERROR;
    }
    *e = s->top->data;
    printf("ջ����Ԫ���� %d.\n", *e);
    return SUCCESS;
}

//4
Status clearLStack(LinkStack* s)
{
    StackNode* p = NULL;
    s->count = 0;
    s->top = bottom;
    p = bottom->next;
    while (p)
    {
        p = bottom->next;
        free(bottom);
        bottom = p;
    }
    printf("�ɹ����ջ.\n");
    return SUCCESS;
}

//5
Status destroyLStack(LinkStack* s)
{
    StackNode* p = NULL;
    s->count = 0;
    s->top = NULL;
    while (p)
    {
        p = bottom->next;
        free(bottom);
        bottom = p;
    }
    printf("�ɹ�����ջ.\n");
    return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)
{
    if (s->top == NULL)
    {
        printf("����û��ջ.\n");
        return ERROR;
    }
    *length = s->count;
    printf("ջ�ĳ����� %d.\n", *length);
    return SUCCESS;
}

Status printStack(LinkStack* s)
{
    StackNode* p = NULL;
    if (s->top == NULL)
    {
        printf("û��ջ.\n");
        return ERROR;
    }
    else if ( s->count == 0)
    {
        printf("ջ�ǿյ�.\n");
        return ERROR;
    }
    for (p = bottom->next; p; p = p->next)
    {
        printf("|%d", p->data);
    }
    printf("\n");
    return SUCCESS;
}

// �����������
//����
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
            printf("û���������룬������:");
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