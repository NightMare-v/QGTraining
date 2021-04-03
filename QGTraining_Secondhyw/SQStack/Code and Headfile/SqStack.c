#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

// Array-based sequential stack.基于数组
Status initStack(SqStack* s, int sizes)
{
    if (sizes <= 0)
    {
        printf("栈的大小必须大于 0.\n");
        return ERROR;
    }
    else
    {
        s->size = sizes; // Array length.
        s->top = -1; // Top index.
        s->elem = (ElemType*)malloc(sizes * sizeof(ElemType)); // Allocate memory to the array, sizes is the length of the array.
        printf("成功建立一个大小为 %d 的栈.\n", sizes);
        return SUCCESS;
    }
}

Status pushStack(SqStack* s, ElemType data)
{
    if (s == NULL || (s->size <= s->top + 1))
    {
        printf("栈已满或栈是空的.\n");
        return ERROR;
    }
    else
    {
        //s->top = s->top + 1;
        //下面为简略写的方式
        s->elem[++s->top] = data;
        printf("成功将 %d 入栈.\n", data);
        return SUCCESS;
    }
}

Status popStack(SqStack* s, ElemType* data)
{
    if (s == NULL || s->top == -1)
    {
        printf("栈是空的.\n");
        return ERROR;
    }
    else
    {
        *data = s->elem[s->top];
        s->top--;
        //s->top = s->top - 1;
        //上面为简略写的方式
        printf("成功将 %d 出栈.\n", *data);
        return SUCCESS;
    }
}

//case 8
Status getTopStack(SqStack* s, ElemType* e)
{
    if (s == NULL || s->top == -1)
    {
        printf("现在没有栈或者栈是空的.\n");
        return ERROR;
    }
    else
    {
        *e = s->elem[s->top];
        printf("栈顶的元素是 %d.\n", *e);
        return SUCCESS;
    }
}

//case 5
Status destroyStack(SqStack* s)
{
    if (s == NULL || s->size == 0)
    {
        printf("请先初始化栈.\n");
        return ERROR;
    }
    else
    {
        free(s->elem);
        s->size = 0;
        s->elem = NULL;
        printf("成功销毁栈.\n");
        return SUCCESS;
    }
}

//case 4
Status clearStack(SqStack* s)
{
    if (s == NULL)
    {
        printf("现在栈已经是空的了.\n");
        return ERROR;
    }
    else
    {
        s->top = -1;
        printf("成功清空栈.\n");
        return SUCCESS;
    }
}

//case 6
Status stackLength(SqStack* s, int* length)
{
    if (s == NULL || s->size == 0)
    {
        printf("请先初始化栈.\n");
        return ERROR;
    }
    else
    {
        *length = s->top + 1;
        printf("栈的长度是 %d.\n", *length);
        return SUCCESS;
    }
}

//case 7
Status isEmptyStack(SqStack* s)
{
	if (s == NULL || s->top == -1)
	{
		printf("栈是空的.\n");
		return SUCCESS;
	}
	printf("栈不是空的.\n");
	return ERROR;
}

Status printStack(SqStack* s)
{
	if (s->size == 0)
	{
		printf("没有栈.\n");
		return ERROR;
	}
	else if (s == NULL || s->top == -1)
	{
        printf("栈是空的.\n");
		return ERROR;
	}
	for (int i = 0; i <= s->top; i++)
	{
		printf("|%d", s->elem[i]);
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

