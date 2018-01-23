#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define Errow -1
typedef int Status;
typedef int ElemType;

typedef struct qnode
{
	ElemType data;
	struct qnode *next;
}QNode;

typedef struct
{
		QNode *front;
		QNode *rear;
}LiQueue;

LiQueue* InitQueue()
{
		LiQueue *q=(LiQueue *)malloc(sizeof(LiQueue));
		q->front=q->rear=NULL;
		return q;
}
void DestroyQueue(LiQueue *q)
{
		QNode *p=q->front,*r;
		if(p!=NULL)
		{
				r=p->next;
				while(r!=NULL)
				{
						free(p);
						p=r;
						r=p->next;
				}
		}
		free(p);
		free(q);
}
Status QueueEmpty(LiQueue *q)
{
		return q->rear==NULL?Ok:Errow;
}

void enQueue(LiQueue *q,ElemType e)
{
		QNode *p;
		p=(QNode *)malloc(sizeof(QNode));
		p->data=e;
		p->next=NULL;
		if(q->rear==NULL)
				q->front=q->rear=p;
		else
		{
				q->rear->next=p;
				q->rear=p;
		}
}
Status deQueue(LiQueue *q,ElemType *e)
{
		QNode *t;
		if(q->rear==NULL)
				return Errow;
		t=q->front;
		if(q->front==q->rear)
				q->front=q->rear=NULL;
		else
				q->front=q->front->next;
		*e=t->data;
		free(t);
		return Ok;
}
void DisQueue(LiQueue *q)
{
		QNode *s=q->front;
		while(s!=q->rear)
		{
				printf(" %d",s->data);
				s=s->next;
		}
		printf(" %d",q->rear->data);
		printf("\n");
}
int main(void)
{
	LiQueue *liQueue=InitQueue();
	enQueue(liQueue,10);
	enQueue(liQueue,100);
	enQueue(liQueue,50);
	DisQueue(liQueue);
	return 0;

}


