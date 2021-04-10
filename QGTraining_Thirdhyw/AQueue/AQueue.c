#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

//�����
void InitAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;			//��ʼ��ǰ��ָ�붼ָ��0
    printf("�ɹ���������.\n");
    return TRUE;
}

void DestoryAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;
    printf("�����ٶ���\n");
    return TRUE;
}

//�����
Status IsFullAQueue(const AQueue* Q) {
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        printf("��������\n");
        return TRUE;
    }
    else
    {
        printf("����δ��\n");
        return FALSE;
    }
}

//�����
Status IsEmptyAQueue(const AQueue* Q) {
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

//�����
Status GetHeadAQueue(AQueue* Q, void* e) {
    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return TRUE;
    }
    else printf("�����е�ͷԪ��Ϊ%d\n", Q->data[Q->front+1]);
    return TRUE;
}
//����int�Խ�����
int LengthAQueue(AQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return 0;
    }
    else
    return (Q->rear - Q->front + MAXQUEUE ) % (MAXQUEUE);
}

//���
//�����
Status EnAQueue(AQueue* Q, void* data) {
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
    {
        return FALSE;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        Q->data[Q->rear] = data;			//���򽫽���Ԫ�ظ�ֵ����ָ����ָ��λ�ã���ָ�������ƶ�һ��
        return TRUE;
    }

}

//����
//�����
Status DeAQueue(AQueue* Q) {
    if (Q->rear == Q->front)
    {
        printf("����Ϊ��\n");
        return TRUE;
    }
    else
    {
        Q->front = (Q->front + 1) % (MAXQUEUE);
        printf("�ɹ��Ƴ�����\n");
        return TRUE;
    }

}

//�����
void ClearAQueue(AQueue* Q) {
    Q->front = Q->rear = 0;
    printf("����ն���\n");
    return TRUE;
}

Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q)) {
    if (Q->front == Q->rear)
    {
        printf("û�ж��л����Ϊ��");
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