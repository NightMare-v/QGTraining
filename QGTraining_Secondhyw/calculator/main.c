#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)


typedef int ElemType;

typedef struct Stack
{
	ElemType* elem;
	int top;
	int size;
} Stack;

void InitStack(Stack* s)
{
    s->top = -1; // Top index.
    s->elem = (ElemType*)malloc(sizeof(ElemType)); // Allocate memory to the array, sizes is the length of the array.
}

 void Push(Stack* s, char* data) {
    s->elem[++s->top] = data;
}

void Pop(Stack* s, char* data) {
    *data = s->elem[s->top];
    s->top--;
}

int IsEmpty(Stack* s) {
    if (s == NULL || s->top == -1)
    {
        return 1;
    }
    return 0;
}
char GetTop(Stack* s) {
    return s->elem[s->top];

}
void destroyStack(Stack* s)
{
    free(s->elem);
    s->size = 0;
    s->elem = NULL;
    return 0;
}
//参考
//中缀转后缀
void transform_mid_to_back(char* mid, char* BACK) {
    Stack s;
    InitStack(&s);
    
    char back[20];  //后缀表达式
    int i = 0;
    int j = 0;
    char useless;

    for (i = 0; mid; i++)
    {
        if (!(mid[i]>='0'&&mid[i]<='9'|| mid[i] == '+' || mid[i] == '-' 
            || mid[i] == '*' || mid[i] == '/' || mid[i] == '(' || mid[i] == ')'))
        {
            printf("输入可能有问题，请稍后重试\n");
            return 0;
        }
        if (mid[i] <= '9' && mid[i] >= '0')  //是数字，直接输出
        {
            back[j] = mid[i];
            j++;
        }
        else if (mid[i] == '(')  //是左括号，直接入栈
        {
            Push(&s, &mid[i]);
        }
        else if (mid[i] == ')')  //是右括号，栈中出栈直到第一个左括号出栈
        {
            while (GetTop(&s) != '(')
            {
                Pop(&s, &back[j]);
                j++;
            }
            Pop(&s, &useless);
        }
        else if (mid[i] == '*' || mid[i] == '/')  //是*/，出栈，直到栈空或者栈中遇到左括号或+-，当前符号入栈
        {
            while (!IsEmpty(&s) && (GetTop(&s) != '+' && GetTop(&s) != '-'))
            {
                Pop(&s, &back[j]);
                j++;
            }
            Push(&s, mid[i]);
        }
        else if (mid[i] == '+' || mid[i] == '-')  //是+-，出栈，直到栈空或者左括号当前符号入栈
        {
            while (!IsEmpty(&s) && GetTop(&s) != '(')
            {
                Pop(&s, &back[j]);
                j++;
            }
            Push(&s, mid[i]);
        }
        if (mid[i+1] == '\0')
        {
            back[j+1] = '\0';
            break;
        }
    }
    //中缀表达式遍历结束，要将栈中剩余符号依次弹出
 
    while (!IsEmpty(&s))
    {
        Pop(&s, &back[j]);
        j++;
    }
    back[j] = '\0';
    printf("中缀表达式： %s\n", mid);
    printf("后缀表达式： %s\n\n", back);
    strcpy(BACK, back);
    //destroyStack(&s);
    return 0;
}


void calculator(char* mid, char*BACK) {
    transform_mid_to_back(mid,BACK);
    int j=0, k=0, l = 0;
    int useless=0;
    Stack s;
    char fin[20]; //pop stack
    InitStack(&s);
    for (int i = 0; BACK; i++)
    {
        if (BACK[i] <= '9' && BACK[i] >= '0')  //是数字，stack
        {
            Push(&s, BACK[i]);
        }
        if (BACK[i] == '+' || BACK[i] == '-'
            || BACK[i] == '*' || BACK[i] == '/')
        {
            Pop(&s, &j);
            Pop(&s, &k);
            if (BACK[i] == '+')
            {
                l = j + k;
                Push(&s, &l);
            }
            if (BACK[i] == '-')
            {
                l = k - j;
                Push(&s, &l);
            }
            if (BACK[i] == '*')
            {
                l = j * k;
                Push(&s, &l);
            }
            if (BACK[i] == '/')
            {
                l = k / j;
                Push(&s, &l);
            }
        }
        if (BACK[i+1]=='\0')
        {
            //printf("%d\n", GetTop(&s));
            break;
        }
    }

}


int InputNumber()
{
    int num = 0; // Store converted numbers.
    int status = 0; // Flag status.
    char str[100]; // Receive string.
    do
    {
        scanf("%s", str);
        status = 1;
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
                    status = 0;
                }
            }
        }
        if (status == 0)
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
                status = 0;
            }
        }
    } while (status == 0);
    return num;
}

int main(){
    int flag = 0; // There is no stack.
    Stack* head = (Stack*)malloc(sizeof(Stack)); // Top pointer.
    head->elem = NULL;
    head->size = head->top = 0;
    while (1)
    {
        system("cls");
        printf("                    \n");
        printf("                    \n");
        printf("--------------------\n");
        printf(">>> 1.中缀表达式转后缀表达式   \n");
        printf(">>> 2.简易计算器          \n");
        printf(">>> 0.退出          \n");
        printf("--------------------\n");
        printf("--------------------\n");
        printf("请输入你的选择：");
        switch (InputNumber())
        {
        case 1:
        {
            char* BACK;
            printf("请输入中缀表达式：");
            char str1[20] = { 0 };
            char str2[20] = { 0 };
            scanf("%s", str1);
            calculator(str1,str2);

            break;
        }
        case 2:
            printf("简单的整数四则运算,按1即可");

            break;
        case 0:
        {
            exit(0);
        }
        default:
        printf("没有这样的选项哦.\n");
    }
    system("pause");
}
}