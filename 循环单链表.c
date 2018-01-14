#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
		ElemType data;
	    struct LNode *next;
}LoopLinkList;

LoopLinkList* CreateList(ElemType a[],int n)
{
		LoopLinkList *L,*s,*r;
		int i;
		L=(LoopLinkList *)malloc(sizeof(LoopLinkList));
		r=L;
		for(i=0;i<n;i++)
		{
				s=(LoopLinkList *)malloc(sizeof(LoopLinkList));
				s->data=a[i];
				r->next=s;
				r=s;
		}
		r->next=L;
		return L;
}

//计算节点=x的个数
int count(LoopLinkList *L,ElemType x)
{
		int n=0;
		LoopLinkList *p=L->next;
		while(p!=L)
		{
				if(p->data==x)
						n++;
				p=p->next;
		}
		return n;
}

int main(void)
{
		ElemType a[7]={10,20,30,20,50,20,20};
		LoopLinkList *loopLinkList=CreateList(a,7);
		printf("x=20的数有：%d\n",count(loopLinkList,20));
		return 0;
}
