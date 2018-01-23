#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define Errow -1
#define MaxSize 50
typedef int Status;
typedef int ElemType;

typedef struct
{
		ElemType data[MaxSize];
		int front,rear;
}SqQueue;

SqQueue* InitQueue()
{
		SqQueue *s=(SqQueue *)malloc(sizeof(SqQueue));
		s->front=s->rear=-1;
		return s;
}
void DestroyQueue(SqQueue *s)
{
		free(s);
}
Status QueueEmpty(SqQueue *s)
{
	return s->front==s->rear?Ok:Errow;		
}

Status enQueue(SqQueue *q,ElemType e)
{
		if(q->rear==MaxSize-1)
			return Errow;
		q->rear++;
		q->data[q->rear]=e;
		return Ok;
}
Status deQueue(SqQueue *q,ElemType *e)
{
		if(q->front==q->rear)
				return Errow;
		q->front++;
		*e=q->data[q->front];
		return Ok;
}
Status DisQueue(SqQueue *q)
{
		
		int initFront;
		initFront=q->front;
		while(initFront!=q->rear)
			printf(" %d",q->data[++initFront]);
		return Ok;
}

int main(void)
{
		SqQueue *sqqueue=InitQueue();
		enQueue(sqqueue,10);
		enQueue(sqqueue,50);
		enQueue(sqqueue,100);
		DisQueue(sqqueue);
		return 0;
}

