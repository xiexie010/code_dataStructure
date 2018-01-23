#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define Errow -1

typedef int Status;
typedef int ElemType;
typedef struct linknode
{
		ElemType data;
		struct linknode *next;
}LiStack;

LiStack* InitStack()
{
		LiStack *s=(LiStack *)malloc(sizeof(LiStack));
		s->next=NULL;
		return s;
}
void DestroyStack(LiStack* s)
{
		LiStack *p=s,*q=s->next;
		while(q!=NULL)
		{
				free(p);
				p=q;
				q=p->next;
		}
		free(q);
}

Status StackEmpty(LiStack *s)
{
		return s->next==NULL?Ok:Errow;
}

void Push(LiStack *s,ElemType e)
{
		LiStack *p;
		p=(LiStack *)malloc(sizeof(LiStack));
		p->next=s->next;
		p->data=e;
		s->next=p;
}
Status Pop(LiStack *s, ElemType *e)
{
		LiStack *p;
		if(s->next==NULL)
				return Errow;
		p=s->next;
		*e=p->data;
		s->next=p->next;
		free(p);
		return Ok;
}

Status GetTop(LiStack *s,ElemType *e)
{
		if(s->next==NULL)
				return Errow;
		*e=s->next->data;
		return Ok;
}
//遍历
void DisStack(LiStack *s)
{
		LiStack *p=s->next;
		while(p!=NULL)
		{
				printf(" %d",p->data);
				p=p->next;
		}
		printf("\n");
}

int main(void)
{
		LiStack *liStack=InitStack();
		ElemType e1=10;
		ElemType e2=20;
		ElemType e3=30;
		Push(liStack,e1);
		Push(liStack,e2);
		Push(liStack,e3);
		DisStack(liStack);
		ElemType e4;
		GetTop(liStack,&e4);
		printf("栈顶的值是%d\n",e4);
}


