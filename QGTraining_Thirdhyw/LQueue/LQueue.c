#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)



void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (LQueue*)malloc(sizeof(LQueue)); //初始化队头与队尾的指针指向头结点
	Q->front->next = NULL;
    printf("成功建立队列.\n");
    return TRUE;
}

void DestoryLQueue(LQueue* Q) {

	Node* temp = Q->front->next;
	while (temp)
	{
		Node* tp = temp;
		temp = temp->next;
		free(tp);
	}
	temp = Q->front;
	Q->front = Q->rear = NULL;
	free(temp);
    printf("已销毁队列\n");
}

Status IsEmptyLQueue(const LQueue* Q) {
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

Status GetHeadLQueue(LQueue* Q, void* e) {
    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return FALSE;
    }
    else
    {
        e = Q->front->next->data;
        printf("队列中的头元素为%d\n", e);
        return TRUE;
    }
}

int LengthLQueue(LQueue* Q) {

	Node* temp = Q->front;
	int i = 0;
	while (temp != Q->rear)
	{
		++i;
		temp = temp->next;
	}
	return i;
}

Status EnLQueue(LQueue* Q, void* data) {
	Node* temp = (Node*)malloc(sizeof(Node)); //创建新结点
	if (temp) //如果内存分配成功
	{
		temp->data = data; //初始化新结点的数据为e
		temp->next = NULL; //队列只能从队尾插入所以下一个结点初始化为NULL
		Q->rear->next = temp; //将队尾结点的指针指向新结点,如果新结点为第一个结点则q->rear->next相当于q->front->next
		Q->rear = temp; //将指向队尾的指针指向新结点
	}
}

Status DeLQueue(LQueue* Q) {

    if (Q->rear == Q->front)
    {
        printf("队列为空\n");
        return FALSE;
    }
    else {
        Node* temp = Q->front->next; //初始化temp为要出队的结点的指针
        if (Q->front->next == Q->rear) //如果要出队的结点为最后一个结点,使q->rear指向头结点防止出现悬空的指针
            Q->rear = Q->front;
        Q->front->next = temp->next; //使下一个结点成为队头,如果没有下一个结点则为NULL
        free(temp); //删除要出队的结点
        printf("成功移出队列\n");
        return TRUE;
    }

}

//暂不做区分
void ClearLQueue(LQueue* Q) {

	Node* temp = Q->front->next;
	while (temp)
	{
		Node* tp = temp;
		temp = temp->next;
		free(tp);
	}
	temp = Q->front;
	Q->front = Q->rear = NULL;
	free(temp);
    printf("已清空队列\n");
    return TRUE;
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (Q->front == Q->rear)
    {
        printf("没有队列或队列为空");
    }
    else
    {
        if (Q->front == Q->rear)
            return;
        Node* temp = Q->front->next;
        while (temp != Q->rear)
        {
            LPrint(temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void LPrint(void* q) {
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