#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
		ElemType data;
		struct LNode *next;
} LinkList;

LinkList* CreateListR(ElemType a[],int n)
{
		LinkList *L;
		LinkList *pre,*p;
		int i;
		L=(LinkList *)malloc(sizeof(LinkList));
		L->next=NULL;
		for(i=0;i<n;i++)
		{
				pre=L;
				while(pre->next!=NULL&&pre->next->data<a[i])
						pre=pre->next;
				p=(LinkList *)malloc(sizeof(LinkList));
				p->data=a[i];
				p->next=pre->next;
				pre->next=p;
		}		
		return L;
}
void DisList(LinkList *L)
{
		LinkList *p=L->next;
		while(p!=NULL)
		{
				printf("%d ",p->data);
				p=p->next;
		}
		printf("\n");
}
//初始化
LinkList* InitList(void)
{
		LinkList *L = (LinkList *)malloc(sizeof(LinkList));
		L->next=NULL;
		return L;
}
//销毁线性表
void DestoryList(LinkList *L)
{
		LinkList *pre=L,*p=pre->next;
		while(p!=NULL)
		{
				free(pre);
				pre=p;
				p=pre->next;
		}
		free(pre);
}
//判断是为空表
int ListEmpty(LinkList *L)
{
		return (L->next==NULL?1:0);
}
//线性表的长度
int ListLength(LinkList *L)
{
		int n;
		LinkList *p=L;
		while(p->next!=NULL)
		{
				n++;
				p=p->next;
		}
		return n;
}
//获得第n个元素值
int ListGetElem(LinkList *L,int n,ElemType *e)
{
		int j=0;
		LinkList *p=L;
		while(j<n&&p!=NULL)
		{
				j++;
				p=p->next;
		}
		if(p==NULL)
		{
				return -1;
		}
		else
		{
				*e=p->data;
				return 1;
		}
}	
//按元素值查找位置
int LocateElem(LinkList *L,ElemType e)
{
	int i=1;
	LinkList *p=L->next;
	while(p!=NULL&&p->data!=e)
	{
			p=p->next;
			i++;
	}
	if(p==NULL)
	{
			return -1;
	}
	else 
			return i;
}
//在插入数据元素
void ListInsert(LinkList *L,ElemType e)
{
		LinkList *pre=L,*p;
		while(pre->next!=NULL&&pre->next->data<e)
			pre=pre->next;
		p=(LinkList *)malloc(sizeof(LinkList));
		p->data=e;
		p->next=pre->next;
		pre->next=p;
}

//删除数据元素n
int ListDelete(LinkList *L,int n,ElemType *e)
{
		int j=0;
		LinkList *p=L,*q;
		while(j<n-1&&p!=NULL)
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
				return -1;
			*e=q->data;
			p->next=q->next;
			free(q);
			return 1;
		}
}

//1拆分两个表
void split(LinkList *L,LinkList *L2)
{
	LinkList *p=L->next,*q,*r1;			
	r1=L;
	while(p!=NULL)
	{
			r1->next=p;
			r1=p;
			p=p->next;
			q=p->next;
			p->next=L2->next;
			L2->next=p;
			p=q;
	}
	r1->next=NULL;
}
//合并两张表
LinkList* UnionList(LinkList *La,LinkList *Lb)
{
		LinkList *pa=La->next,*pb=Lb->next,*r,*s;
		LinkList *Lc=(LinkList *)malloc(sizeof(LinkList));
		r=Lc;
		while(pa!=NULL&&pb!=NULL)
		{
				if(pa->data<pb->data)
				{
						s=(LinkList *)malloc(sizeof(LinkList));
						s->data=pa->data;
						r->next=s;
						r=s;
						pa=pa->next;
				}
				else
				{
						s=(LinkList *)malloc(sizeof(LinkList));
						s->data=pb->data;
						r->next=s;
						r=s;
						pb=pb->next;
				}
		}
		while(pa!=NULL)
		{
				s=(LinkList *)malloc(sizeof(LinkList));
				s->data=pa->data;
				r->next=s;
				r=s;
				pa=pa->next;
		}
		while(pb!=NULL)
		{
				s=(LinkList *)malloc(sizeof(LinkList));
				s->data=pb->data;
				r->next=s;
				r=s;
				pb=pb->next;
		}
		r->next=NULL;
		return Lc;
}

//排序
void sort(LinkList *L)
{
		LinkList *p,*pre,*q;
		p=L->next->next;
		L->next->next=NULL;
		while(p!=NULL)
		{
				q=p->next;
				pre=L;
				while(pre->next!=NULL&&pre->next->data<p->data)
					pre=pre->next;
				p->next=pre->next;
				pre->next=p;
				p=q;
		}
}
int main(void)
{
		LinkList *linkList;
		ElemType a[10]={10000,111,23,44,55,66,77,8,99,1000};
		linkList=CreateListR(a,10);
		DisList(linkList);
		printf("是否为空表%d\n",ListEmpty(linkList));

		ElemType e;
		ListGetElem(linkList,2,&e);
		printf("第二个数是：%d\n",e);

		printf("23在第%d位\n",LocateElem(linkList,23));

		ListInsert(linkList,100);
		DisList(linkList);
		ListDelete(linkList,4,&e);
		DisList(linkList);
		printf("删除的数是%d\n",e);
		
		LinkList *linkList2=(LinkList *)malloc(sizeof(LinkList));
		linkList2->next=NULL;
		split(linkList,linkList2);
		DisList(linkList);
		DisList(linkList2);
		//sort(linkList);
		//DisList(linkList);
		LinkList *linkList3;
		sort(linkList2);
		linkList3=UnionList(linkList,linkList2);
		printf("合并之后的表为：\n");
		DisList(linkList3);
		return 0;
}

