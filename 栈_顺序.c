#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROW -1
#define MaxSize 100

typedef char ElemType;
typedef int Status;

typedef struct 
{
		ElemType data[MaxSize];
		int top;
}SqStack;
//初始化栈
SqStack* InitStack()
{
		SqStack *s=(SqStack *)malloc(sizeof(SqStack));
		s->top=-1;
		return s;
}
//销毁栈
void DestroyStack(SqStack *s)
{
		free(s);
}
//判断栈是否为空
Status StackEmpty(SqStack *s)
{
		return s->top==-1?OK:ERROW;
}
Status Push(SqStack *s,ElemType e)
{
		if(s->top==MaxSize-1)
			return ERROW;
		s->top++;
		s->data[s->top]=e;
		return OK;
}
Status Pop(SqStack *s,ElemType *e)
{
		if(s->top==-1)
				return ERROW;
		*e=s->data[s->top];
		s->top--;
		return OK;
}
Status GetTop(SqStack *s,ElemType *e)
{
		if(s->top==-1)
				return ERROW;
		*e=s->data[s->top];
		return OK;
}
//判断一个字符串是否为对称串
Status symmetry(ElemType str[])
{
		int i;
		ElemType e;
		SqStack *st=InitStack();
		for(i=0;str[i]!='\0';i++)
				Push(st,str[i]);
		for(i=0;str[i]!='\0';i++)
		{
				Pop(st,&e);
				if(str[i]!=e)
				{
						DestroyStack(st);
						return ERROW;
				}
		}
		DestroyStack(st);
		return OK;
}
int main(void)
{
		SqStack *sqStack = InitStack();
		Push(sqStack,10);
		Push(sqStack,20);
		ElemType e;
		GetTop(sqStack,&e);
		printf("当前栈顶的数是%d\n",e);
		Push(sqStack,100);
		GetTop(sqStack,&e);
		printf("当前栈顶的数是%d\n",e);
		Pop(sqStack,&e);
		printf("退出的数据是%d\n",e);
		GetTop(sqStack,&e);
		printf("当前栈顶的数是%d\n",e);
		ElemType  sstr[]="aabbaa";
		char *a;
		a=symmetry(sstr)==OK?"是":"不是";
		printf("sstr%s对称串\n",symmetry(sstr)==OK?"是":"不是");
		

		return 0;
}

