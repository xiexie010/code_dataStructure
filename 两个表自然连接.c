#include <stdio.h>
#include <stdlib.h>

#define MaxCol 10

typedef int ElemType;

typedef struct Node1
{
		ElemType data[MaxCol];
		struct Node1 *next;
}DList;
typedef struct Node2
{
		int Row,Col;
		DList *next;
}HList;

HList* CreateTable()
{
		int i,j;
		DList *r,*s;
		HList *h=(HList *)malloc(sizeof(HList));
		h->next=NULL;
		printf("请输入行数，列数。\n");
		scanf("%d %d",&h->Row,&h->Col);
		for(i=0;i<h->Row;i++)
		{
				printf("第%d行：",i+1);
				s=(DList *)malloc(sizeof(DList));
				for(j=0;j<h->Col;j++)
				{	
					scanf(" %d",&s->data[j]);
				//	printf("data[%d]是%d\n",j,s->data[j]);
				}
				if(h->next==NULL)
						h->next=s;
				else
						r->next=s;
				r=s;
		}
		r->next=NULL;
		return h;
}
void DisTable(HList *h)
{
		int j;
		DList *p=h->next;
		while(p!=NULL)
		{
				for(j=0;j<h->Col;j++)
					printf(" %d",p->data[j]);
				printf("\n");
				p=p->next;
		}
}
//两个表自然连接，制定的两个列对应相等。
HList* LinkTable(HList *h1,HList *h2)
{
		int i,j,k;
		DList *p=h1->next,*q,*s,*r;
		printf("连接的字段是：第1个表序号，第2个表序号：");
		scanf("%d %d",&i,&j);
		HList *h=(HList *)malloc(sizeof(HList));
		h->Row=0;
		h->Col=h1->Col+h2->Col;
		h->next=NULL;
		while(p!=NULL)
		{
			q=h2->next;
			while(q!=NULL)
			{
					if(p->data[i-1]==q->data[j-1])
					{
							s=(DList *)malloc(sizeof(DList));
							for(k=0;k<h1->Col;k++)
								s->data[k]=p->data[k];
							for(k=0;k<h2->Col;k++)
								s->data[h1->Col+k]=q->data[k];
							if(h->next==NULL)
								h->next=s;
							else
								r->next=s;
							r=s;
							h->Row++;
					}
					q=q->next;
			}
			p=p->next;
		}
		r->next=NULL;
		return h;
}

int main(void)
{
	HList *h1=CreateTable();
	HList *h2=CreateTable();
	HList *h=LinkTable(h1,h2);
	printf("合并之后的表为：\n");
	DisTable(h);
	return 0;
}
