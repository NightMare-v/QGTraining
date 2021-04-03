#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

// Array-based sequential stack.��������
Status initStack(SqStack* s, int sizes)
{
    if (sizes <= 0)
    {
        printf("ջ�Ĵ�С������� 0.\n");
        return ERROR;
    }
    else
    {
        s->size = sizes; // Array length.
        s->top = -1; // Top index.
        s->elem = (ElemType*)malloc(sizes * sizeof(ElemType)); // Allocate memory to the array, sizes is the length of the array.
        printf("�ɹ�����һ����СΪ %d ��ջ.\n", sizes);
        return SUCCESS;
    }
}

Status pushStack(SqStack* s, ElemType data)
{
    if (s == NULL || (s->size <= s->top + 1))
    {
        printf("ջ������ջ�ǿյ�.\n");
        return ERROR;
    }
    else
    {
        //s->top = s->top + 1;
        //����Ϊ����д�ķ�ʽ
        s->elem[++s->top] = data;
        printf("�ɹ��� %d ��ջ.\n", data);
        return SUCCESS;
    }
}

Status popStack(SqStack* s, ElemType* data)
{
    if (s == NULL || s->top == -1)
    {
        printf("ջ�ǿյ�.\n");
        return ERROR;
    }
    else
    {
        *data = s->elem[s->top];
        s->top--;
        //s->top = s->top - 1;
        //����Ϊ����д�ķ�ʽ
        printf("�ɹ��� %d ��ջ.\n", *data);
        return SUCCESS;
    }
}

//case 8
Status getTopStack(SqStack* s, ElemType* e)
{
    if (s == NULL || s->top == -1)
    {
        printf("����û��ջ����ջ�ǿյ�.\n");
        return ERROR;
    }
    else
    {
        *e = s->elem[s->top];
        printf("ջ����Ԫ���� %d.\n", *e);
        return SUCCESS;
    }
}

//case 5
Status destroyStack(SqStack* s)
{
    if (s == NULL || s->size == 0)
    {
        printf("���ȳ�ʼ��ջ.\n");
        return ERROR;
    }
    else
    {
        free(s->elem);
        s->size = 0;
        s->elem = NULL;
        printf("�ɹ�����ջ.\n");
        return SUCCESS;
    }
}

//case 4
Status clearStack(SqStack* s)
{
    if (s == NULL)
    {
        printf("����ջ�Ѿ��ǿյ���.\n");
        return ERROR;
    }
    else
    {
        s->top = -1;
        printf("�ɹ����ջ.\n");
        return SUCCESS;
    }
}

//case 6
Status stackLength(SqStack* s, int* length)
{
    if (s == NULL || s->size == 0)
    {
        printf("���ȳ�ʼ��ջ.\n");
        return ERROR;
    }
    else
    {
        *length = s->top + 1;
        printf("ջ�ĳ����� %d.\n", *length);
        return SUCCESS;
    }
}

//case 7
Status isEmptyStack(SqStack* s)
{
	if (s == NULL || s->top == -1)
	{
		printf("ջ�ǿյ�.\n");
		return SUCCESS;
	}
	printf("ջ���ǿյ�.\n");
	return ERROR;
}

Status printStack(SqStack* s)
{
	if (s->size == 0)
	{
		printf("û��ջ.\n");
		return ERROR;
	}
	else if (s == NULL || s->top == -1)
	{
        printf("ջ�ǿյ�.\n");
		return ERROR;
	}
	for (int i = 0; i <= s->top; i++)
	{
		printf("|%d", s->elem[i]);
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

