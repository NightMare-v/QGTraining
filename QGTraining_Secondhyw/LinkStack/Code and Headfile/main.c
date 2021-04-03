#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

int main()
{
    int flag = 0; // There is no stack.
    LinkStack* head = (LinkStack*)malloc(sizeof(StackNode));
    head->count = 0;
    head->top = NULL;
    while (1)
    {
        while (1)
        {
            system("cls");
            printf("                    \n");
            printf("     已完成               \n");
            printf("--------------------\n");
            printf(">>> 1.初始化栈      \n");
            printf(">>> 2.入栈          \n");
            printf(">>> 3.出栈          \n");
            printf(">>> 4.清空栈        \n");
            printf(">>> 5.销毁栈        \n");
            printf(">>> 6.检测栈长度    \n");
            printf(">>> 7.判断栈是否为空\n");
            printf(">>> 8.得到栈顶元素  \n");
            printf(">>> 9.退出          \n");
            printf("--------------------\n");
            printStack(head);
            printf("--------------------\n");
            printf("请输入你的选择：");
            switch (InputNumber())
            {
            case 1:
                //大括号为作用域，出域会销毁
            {
                initLStack(head);
            }
            flag = 1;
            break;
            case 2:
                if (flag == 1)
                {
                    printf("请输入需要入栈的数据：");
                    pushLStack(head, InputNumber());
                }
                else
                {
                    printf("现在没有栈，请先初始化栈.\n");
                }
                break;
            case 3:
                if (flag == 1)
                {
                    ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                    popLStack(head, e);
                }
                else
                {
                    printf("现在没有栈，请先初始化栈.\n");
                }
                break;
            case 4:
                if (flag == 1)
                {
                    clearLStack(head);
                    initLStack(head);
                }
                else
                {
                    printf("现在没有栈，请先初始化栈.\n");
                }
                break;
            case 5:
                if (flag == 1)
                {
                    destroyLStack(head);
                    flag = 0;
                }
                else
                {
                    printf("现在没有栈，请先初始化栈.\n");
                }
                break;
            case 6:
            {
                int* length = (int*)malloc(sizeof(int));
                LStackLength(head, length);
            }
            break;
            case 7:
                if (flag == 1)
                {
                    isEmptyLStack(head);
                }
                else
                {
                    printf("现在没有栈.\n");
                }
                break;
            case 8:
                if (flag == 1)
                {
                    ElemType* e = (ElemType*)malloc(sizeof(ElemType));
                    getTopLStack(head, e);
                }
                else
                {
                    printf("现在没有栈.\n");
                }
                break;
            case 9:
            {
                exit(0);
            }
            default:
                printf("没有这样的选项哦.\n");
            }
            system("pause");
        }
    }
}