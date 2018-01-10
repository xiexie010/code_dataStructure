#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
} SqList;

//建立表
void CreateList(SqList *L,ElemType a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		L->data[i]=a[i];
	}
	L->length=n;
}

//顺序表基本运算算法
//初始化线性表
void InitList(SqList *L)
{
	L->length=0;
}

//销毁线性表
void DestroyList(SqList *L)
{
	free(L);
}

//判断线性表是否为空表
int ListEmpty(SqList *L)
{
	return L->length==0?1:0;
}

//求线性表的长度
int ListLength(SqList *L)
{
	return L->length;
}

//输出线性表DispList(L)
void DispList(SqList *L)
{
	int i;
	for(i=0;i<L->length;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
}

//求线性表中某个数据元素值GetElem;
int GetElem(SqList *L,int i,ElemType *e)
{
	if(i<1||i>L->length)
			return 0;
	*e=L->data[i-1];
	return 1;
}

//按元素值查找locateElem（L，e）
int LocateElem(SqList *L, ElemType e)
{
		int i=0;
		while(i<L->length&&L->data[i]!=e)
				i++;
		if(i>=L->length)
				return 0;
		else 
				return i+1;
}

//插入数据元素
int ListInsert(SqList *L,int i,ElemType e)
{
		int j;
		if(i<1||i>L->length+1)
				return 0;
		i--;
		for(j=L->length;j>i;j--)
				L->data[j]=L->data[j-1];
		L->data[i]=e;
		L->length++;
		return 0;
}
//删除数据元素
int ListDelete(SqList *L,int i,ElemType *e)
{
		
		int j;
		if(i<1||i>L->length)
				return 0;
		i--;
		*e=L->data[i];
		for(j=i;j<L->length;j++)
				L->data[j]=L->data[j+1];
		L->length--;
		
		return 0;
}




int main()
{
	SqList *sqList;
	sqList=(SqList *)malloc(sizeof(SqList));
	ElemType a[3];
	a[0]=10;
	a[1]=33;
	a[2]=53;
	InitList(sqList);
	CreateList(sqList,a,3);
//	printf("%d , %d\n",sqList->data[0],sqList->data[1]);
	DispList(sqList);	
	ElemType *de;
	de=(ElemType *)malloc(sizeof(ElemType));
	ListDelete(sqList,1,de);
	DispList(sqList);
	//printf("%d",sqList->data[15]);
	DestroyList(sqList);
	ElemType ie;
	ie=100;	
	ListInsert(sqList,sqList->length+1,ie);
	DispList(sqList);
	printf("%d\n",ListLength(sqList));
	printf("%d\n",LocateElem(sqList,ie));
	ElemType oe;
	GetElem(sqList,2,&oe);
	printf("%d\n",oe);
	return 0;		
}
