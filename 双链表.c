#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode
{
		ElemType data;
		struct DNode *prior;
		struct DNode *next;
}DLinkList;
//头插法
DLinkList* CreateListF(ElemType a[],int n)
{
	DLinkList *s,*rL;
	int i;
	rL=(DLinkList *)malloc(sizeof(DLinkList));
	rL->prior=rL->next=NULL;
	for(i=0;i<n;i++)
	{
			s=(DLinkList *)malloc(sizeof(DLinkList));
			s->data=a[i];
			s->next=rL->next;
			if(rL->next!=NULL)
					rL->next->prior=s;
			rL->next=s;
			s->prior=rL;
	}
	return rL;
}
//尾插法
DLinkList* CreateListR(ElemType a[],int n)
{
		DLinkList *s,*rL,*r;
		int i;
		rL=(DLinkList *)malloc(sizeof(DLinkList));
		rL->prior=rL->next=NULL;
		r=rL;
		for(i=0;i<n;i++)
		{
				s=(DLinkList *)malloc(sizeof(DLinkList));
				s->data=a[i];
				r->next=s;
				s->prior=r;
				r=s;
		}
		r->next=NULL;
		return rL;
}
		
void DisList(DLinkList *L)
{
		DLinkList *p=L->next;
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;	
		}
		printf("\n");
}
int ListInsert(DLinkList *L,int i,ElemType e)
{
		int j=0;
		DLinkList *p=L,*s;
		while(j<i-1&&p->next!=NULL)
		{
				j++;
				p=p->next;
		}
		if(p==NULL)
				return -1;
		else
		{
				s=(DLinkList *)malloc(sizeof(DLinkList));
				s->data=e;
				s->next=p->next;
				s->prior=p;
				if(p->next!=NULL)
					p->next->prior=s;
				p->next=s;
				return 1;
		}
}
int ListDelete(DLinkList *L,int i,ElemType *e)
{
		int j=0;
		DLinkList *p=L,*q;
		while(j<i-1&&p!=NULL)
		{
				j++;
				p=p->next;
		}
		if(p==NULL)
				return -1;
		else
		{
				q=p->next;
				if(q==NULL)
				{
						return -1;
				}
				*e=q->data;
				p->next=q->next;
				if(q->next!=NULL)
				{
						p->next->prior=p;
				}
				free(q);
				return 1;
		}
}

int main(void)
{
		ElemType a[6]={10,20,30,40,50,66};
		DLinkList *dLinkList1=CreateListF(a,6);
		DisList(dLinkList1);
		ElemType a2[6]={22,33,44,55,66,77};
		DLinkList *dLinkList2=CreateListR(a2,6);
		DisList(dLinkList2);
			
		ListInsert(dLinkList2,2,100);
		DisList(dLinkList2);
		ElemType e;
		ListDelete(dLinkList2,2,&e);
		DisList(dLinkList2);
		printf("删除的数是：%d\n",e);

		return 0;
}
