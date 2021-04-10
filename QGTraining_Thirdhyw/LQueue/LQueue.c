#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)



void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (LQueue*)malloc(sizeof(LQueue)); //��ʼ����ͷ���β��ָ��ָ��ͷ���
	Q->front->next = NULL;
    printf("�ɹ���������.\n");
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
    printf("�����ٶ���\n");
}

Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return TRUE;
    }
    else
    {
        printf("���в�Ϊ��\n");
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue* Q, void* e) {
    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    else
    {
        e = Q->front->next->data;
        printf("�����е�ͷԪ��Ϊ%d\n", e);
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
	Node* temp = (Node*)malloc(sizeof(Node)); //�����½��
	if (temp) //����ڴ����ɹ�
	{
		temp->data = data; //��ʼ���½�������Ϊe
		temp->next = NULL; //����ֻ�ܴӶ�β����������һ������ʼ��ΪNULL
		Q->rear->next = temp; //����β����ָ��ָ���½��,����½��Ϊ��һ�������q->rear->next�൱��q->front->next
		Q->rear = temp; //��ָ���β��ָ��ָ���½��
	}
}

Status DeLQueue(LQueue* Q) {

    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return FALSE;
    }
    else {
        Node* temp = Q->front->next; //��ʼ��tempΪҪ���ӵĽ���ָ��
        if (Q->front->next == Q->rear) //���Ҫ���ӵĽ��Ϊ���һ�����,ʹq->rearָ��ͷ����ֹ�������յ�ָ��
            Q->rear = Q->front;
        Q->front->next = temp->next; //ʹ��һ������Ϊ��ͷ,���û����һ�������ΪNULL
        free(temp); //ɾ��Ҫ���ӵĽ��
        printf("�ɹ��Ƴ�����\n");
        return TRUE;
    }

}

//�ݲ�������
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
    printf("����ն���\n");
    return TRUE;
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (Q->front == Q->rear)
    {
        printf("û�ж��л����Ϊ��");
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
                printf("�����������\n");
                status = TRUE;
            }
        }
    } while (status == FALSE);
    return num;
}