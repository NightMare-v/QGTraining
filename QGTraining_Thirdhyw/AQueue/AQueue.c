#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

//已完成
void InitAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;			//初始化前后指针都指向0
    printf("成功建立队列.\n");
    return TRUE;
}

void DestoryAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;
    printf("已销毁队列\n");
    return TRUE;
}

//已完成
Status IsFullAQueue(const AQueue* Q) {
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        printf("队列已满\n");
        return TRUE;
    }
    else
    {
        printf("队列未满\n");
        return FALSE;
    }
}

//已完成
Status IsEmptyAQueue(const AQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return TRUE;
    }
    else
    {
        printf("队列不为空\n");
        return FALSE;
    }
}

//已完成
Status GetHeadAQueue(AQueue* Q, void* e) {
    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return TRUE;
    }
    else printf("队列中的头元素为%d\n", Q->data[Q->front+1]);
    return TRUE;
}
//返回int对接数据
int LengthAQueue(AQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return 0;
    }
    else
    return (Q->rear - Q->front + MAXQUEUE ) % (MAXQUEUE);
}

//入队
//已完成
Status EnAQueue(AQueue* Q, void* data) {
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        return FALSE;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        Q->data[Q->rear] = data;			//否则将进队元素赋值给后指针所指的位置，后指针往后移动一格
        return TRUE;
    }

}

//出队
//已完成
Status DeAQueue(AQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return TRUE;
    }
    else
    {
        Q->front = (Q->front + 1) % (MAXQUEUE);
        printf("成功移出队列\n");
        return TRUE;
    }

}

//已完成
void ClearAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;
    printf("已清空队列\n");
    return TRUE;
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) {
    if (Q->front == Q->rear)
    {
        printf("没有队列或队列为空");
    }
    else
    {
        for (int i = Q->front+1; i <= Q->rear; i++)
        {
            APrint(Q->data[i]);
            
        }
        //printf("\n");
        return TRUE;
    }
}

void APrint(void* q) {
    printf("%d->", q);
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
        status = TRUE;
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
                    status = FALSE;
                }
            }
        }
        if (status == FALSE)
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
                printf("溢出，请重试\n");
                status = TRUE;
            }
        }
    } while (status == FALSE);
    return num;
}