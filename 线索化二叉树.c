#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define Ok 1
#define No 0
typedef int Status;
typedef int ElemType;
typedef struct node
{
		ElemType data;
		int ltag,rtag;
		struct node *lchild;
		struct node *rchild;
}TBTNode;

//创建二叉树
TBTNode * CreateTBTNode( char *str)
{
		TBTNode *St[MaxSize],*p;
		int top = -1,k,j=0;
		char ch;
		TBTNode *b=NULL;
		ch = str[j];
		while(ch!='\0')
		{
				switch(ch)
				{
						case '(':top++,St[top]=p;k=1;break;//开始处理左孩子节点
						case ')':top--;break;
						case ',':k=2;break;//开始处理右孩子节点
						default:
						p=(TBTNode*)malloc(sizeof(TBTNode));
						p->data=ch;
						p->lchild=p->rchild=NULL;
						if(b==NULL)
								b=p;
						else
						{
								switch(k)
								{
										case 1:St[top]->lchild=p;break;
										case 2:St[top]->rchild=p;break;
								}
						}
				}
				j++;
				ch=str[j];
		}
		return b;
}
void DispTBTNode(TBTNode *b)
{
		if(b!=NULL)
		{
				printf("%c ",b->data);
				if(b->lchild!=NULL||b->rchild!=NULL)
				{ 
						printf("(");
						DispTBTNode(b->lchild);
						if(b->rchild!=NULL)printf(",");
						DispTBTNode(b->rchild);
						printf(")");
				}
		}
}
TBTNode *pre;
/** 中序线索 **/
void Thread(TBTNode *p)
{
		if(p!=NULL)
		{
				Thread(p->lchild);
				if(p->lchild==NULL)
				{
						p->lchild=pre;
						p->ltag=1;
				}
				else
						p->ltag=0;
				if(pre->rchild==NULL)
				{
						pre->rchild=p;
						pre->rtag=1;
				}
				else 
						pre->rtag=0;
				pre=p;
				Thread(p->rchild);
		}
}

TBTNode *CreaThread(TBTNode *b)
{
		TBTNode *root;
		root=(TBTNode *)malloc(sizeof(TBTNode));
		root->ltag=0;root->rtag=1;
		root->rchild=b;
		if(b==NULL)
				root->lchild=root;
		else
		{
				root->lchild=b;
				pre=root;
				Thread(b);
				pre->rchild=root;
				pre->rtag=1;
				root->rchild=pre;
		}
		return root;
}
//遍历线索化二叉树
void ThInOrder(TBTNode *tb)
{
		TBTNode *p=tb->lchild;
		while(p!=tb)
		{
				while(p->ltag==0)
						p=p->lchild;
				printf("%c ",p->data);
				while(p->rtag==1&&p->rchild!=tb)
				{
						p=p->rchild;
						printf("%c ",p->data);
				}
				p=p->rchild;
		}
}

int main(void)
{
		TBTNode *b=CreateTBTNode("A(B(D(,G)),C(E,F))");
		DispTBTNode(b);
		TBTNode *tb=CreaThread(b);
		ThInOrder(tb);
		return 0;
}
