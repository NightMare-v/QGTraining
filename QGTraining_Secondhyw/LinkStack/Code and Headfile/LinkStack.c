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
	printf("成功初始化栈.\n");
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
	printf("成功将 %d 入栈.\n", data);
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)
{
	StackNode* p = bottom;
	if (s->count == 0)
	{
		printf("栈是空的.\n");
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
		printf("成功将 %d 出栈.\n", *data);
		return SUCCESS;
	}
}

//7
Status isEmptyLStack(LinkStack* s)
{
    if (s->count == 0)
    {
        printf("栈是空的.\n");
        return SUCCESS;
    }
    printf("栈不是空的.\n");
    return ERROR;
}

//8
Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (s->top == NULL)
    {
        printf("现在没有栈或者栈是空的.\n");
        return ERROR;
    }
    *e = s->top->data;
    printf("栈顶的元素是 %d.\n", *e);
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
    printf("成功清空栈.\n");
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
    printf("成功销毁栈.\n");
    return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)
{
    if (s->top == NULL)
    {
        printf("现在没有栈.\n");
        return ERROR;
    }
    *length = s->count;
    printf("栈的长度是 %d.\n", *length);
    return SUCCESS;
}

Status printStack(LinkStack* s)
{
    StackNode* p = NULL;
    if (s->top == NULL)
    {
        printf("没有栈.\n");
        return ERROR;
    }
    else if ( s->count == 0)
    {
        printf("栈是空的.\n");
        return ERROR;
    }
    for (p = bottom->next; p; p = p->next)
    {
        printf("|%d", p->data);
    }
    printf("\n");
    return SUCCESS;
}

// 输入整数检测
//沿用
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
            printf("没有这种输入，请重试:");
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
                printf("溢出，请重试:");
                status = ERROR;
            }
        }
    } while (status == ERROR);
    return num;
}