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
		struct node *lchild;
		struct node *rchild;
}BTNode;

//创建二叉树
BTNode * CreateBTNode( char *str)
{
		BTNode *St[MaxSize],*p;
		int top = -1,k,j=0;
		char ch;
		BTNode *b=NULL;
		ch = str[j];
		while(ch!='\0')
		{
				switch(ch)
				{
						case '(':top++,St[top]=p;k=1;break;//开始处理左孩子节点
						case ')':top--;break;
						case ',':k=2;break;//开始处理右孩子节点
						default:
						p=(BTNode*)malloc(sizeof(BTNode));
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
void DispBTNode(BTNode *b)
{
		if(b!=NULL)
		{
				printf("%c ",b->data);
				if(b->lchild!=NULL||b->rchild!=NULL)
				{ 
						printf("(");
						DispBTNode(b->lchild);
						if(b->rchild!=NULL)printf(",");
						DispBTNode(b->rchild);
						printf(")");
				}
		}
}
//查找节点
BTNode* FindNode(BTNode *b,ElemType x)
{
		BTNode *p;
		if(b==NULL)
				return NULL;
		else if(b->data==x)
				return b;
		else
		{
				p=FindNode(b->lchild,x);
				if(p!=NULL)
						return p;
				else
						return FindNode(b->rchild,x);
		}
}
//查找孩子节点
BTNode *LchildNode(BTNode *p)
{
		return p->lchild;
}
//输出二叉树的高度
int BTNodeHeight(BTNode *p)
{
		int lchildh,rchildh;
		if(p==NULL)return 0;
		else
		{
				lchildh=BTNodeHeight(p->lchild);
				rchildh=BTNodeHeight(p->rchild);
				return lchildh>rchildh?(lchildh+1):(rchildh+1);
		}
}

/**三种遍历**/
//先序遍历
void PreOrder(BTNode *b)
{
		if(b!=NULL)
		{
				printf("%c ",b->data);
				PreOrder(b->lchild);
				PreOrder(b->rchild);
		}
}
//中序遍历
void InOrder(BTNode *b)
{
		if(b!=NULL)
		{
				InOrder(b->lchild);
				printf("%c ",b->data);
				InOrder(b->rchild);
		}
}
//后序遍历
void PostOrder(BTNode *b)
{
		if(b!=NULL)
		{
				PostOrder(b->lchild);
				PostOrder(b->rchild);
				printf("%c ",b->data);
		}
}
//输出所有叶子
void DispLeaf(BTNode *b)
{
		if(b!=NULL)
		{
				if(b->lchild==NULL&&b->rchild==NULL)
						printf("%c ",b->data);
				DispLeaf(b->lchild);
				DispLeaf(b->rchild);
		}

}

//找到二叉树中节点值为x的节点的层数
int Level(BTNode *b,ElemType x,int h)
{
		int l;
		if(b==NULL)
				return 0;
		else if(b->data==x)
				return h;
		else 
		{
				l=Level(b->lchild,x,h+1);
				if(l!=0)
						return l;
				else 
						return (Level(b->rchild,x,h+1));
		}
}
//看着两个二叉树是否结构相同
Status Like(BTNode *p1,BTNode *p2)
{
		Status like1,like2;
		if(p1==NULL&&p2==NULL)
				return Ok;
		else if(p1==NULL||p2==NULL)
				return No;
		else
		{
				like1=Like(p1->lchild,p2->lchild);
				like2=Like(p2->rchild,p2->rchild);
				return like1&&like2;
		}
}
//输出所有祖先
Status Ancestor(BTNode *b,ElemType e)
{
		if(b==NULL)
				return No;
		else if((b->lchild!=NULL&&b->lchild->data==e)
				||(b->rchild!=NULL&&b->rchild->data==e))
		{
				printf("%c ",b->data);
				return Ok;
		}
		else if(Ancestor(b->lchild,e)||Ancestor(b->rchild,e))
		{
				printf("%c ",b->data);
				return Ok;
		}
		else 
				return No;
}

/** 非递归三种方式遍历二叉树 **/
//先序遍历
void PreOrder1(BTNode *b)
{
		BTNode *St[MaxSize],*p;
		int top=-1;
		if(b!=NULL)
		{
				top++;
				St[top]=b;
				while(top>-1)
				{
						p=St[top];
						top--;
						printf("%c ",p->data);
						if(p->rchild!=NULL)
						{
								top++;
								St[top]=p->rchild;
						}
						if(p->lchild!=NULL)
						{
								top++;
								St[top]=p->lchild;
						}
				}
				printf("\n");
		}
}


//中序遍历
void InOrder1(BTNode *b)
{
		BTNode *St[MaxSize],*p;
		int top=-1;
		if(b!=NULL)
		{
				p=b;
				while(top>-1||p!=NULL)
				{
					while(p!=NULL)
					{
						top++;
						St[top]=p;
						p=p->lchild;
					}
				
				//执行到此，栈顶元素没有左孩子或左子树均已访问过
					if(top>-1)
					{
						p=St[top];
						top--;
						printf("%c ",p->data);
						p=p->rchild;
					}
				}
				printf("\n");
		}
}
//后序遍历
void PostOrder1(BTNode *b)
{
		BTNode *St[MaxSize];
		BTNode *p;
		int flag,top=-1;
		if(b!=NULL)
		{
				do
				{
						while(b!=NULL)
						{
								top++;
								St[top]=b;
								b=b->lchild;
						}
						//执行到此，左子树已经全部访问过
						p=NULL;
						flag=1;
						while(top!=-1&&flag)
						{
								b=St[top];
								if(b->rchild==p)
								{
										printf("%c ",b->data);
										top--;
										p=b;
								}
								else
								{
										b=b->rchild;
										flag=0;
								}
						}
				}
				while(top!=-1);
				printf("\n");
		}
}

//输出所有路径
void AllPath1(BTNode *b)
{
		BTNode *St[MaxSize];
		BTNode *p;
		int flag,i,top=-1;
		if(b!=NULL)
		{
				do
				{
						while(b!=NULL)
						{
								top++;
								St[top]=b;
								b=b->lchild;
						}
						p=NULL;
						flag=1;
						while(top!=-1&&flag)
						{
								b=St[top];
								if(b->rchild==p)
								{
										if(b->lchild==NULL&&b->rchild==NULL)//若为叶子节点
										{
												for(i=top;i>0;i--)
												{
														printf("%c -> ",St[i]->data);
												}
												printf("%c \n",St[0]->data);
										}
										top--;
										p=b;
								}
								else
								{
										b=b->rchild;
										flag=0;
								}
						}
				}
				while(top!=-1);
				printf("\n");
		}
}	  
//层次遍历
void LevelOrder(BTNode *b)
{
		BTNode *p;
		BTNode *qu[MaxSize];
		int front,rear;
		front=rear=-1;
		rear++;
		qu[rear]=b;
		while(front!=rear)
		{
				front=(front+1)%MaxSize;
				p=qu[front];
				printf("%c ",p->data);
				if(p->lchild!=NULL)
				{
						rear=(rear+1)%MaxSize;
						qu[rear]=p->lchild;
				}
				if(p->rchild!=NULL)
				{
						rear=(rear+1)%MaxSize;
						qu[rear]=p->rchild;
				}
		}
		printf("\n");
}

/** 二叉树的构造 **/
BTNode * CreateBT1(char *pre,char *in,int n)
{
		BTNode *b;
		char *p;
		int k;
		if(n<=0)return NULL;
		b=(BTNode *)malloc(sizeof(BTNode));
		b->data=*pre;
		for(p=in;p<in+n;p++)
				if(*p==*pre)
						break;
		k=p-in,
		b->lchild=CreateBT1(pre+1,in,k);
		b->rchild=CreateBT1(pre+k+1,p+1,n-k-1);
		return b;
}
BTNode * CreateBT2(char *post,char *in,int n)
{
		BTNode *b;
		char r,*p;
		int k;
		if(n<=0)return NULL;
		r=*(post+n-1);
		b=(BTNode *)malloc(sizeof(BTNode));
		b->data=r;
		
		for(p=in;p<in+n;p++)
				if(*p==r)break;
		k=p-in;
		b->lchild=CreateBT2(post,in,k);
		b->rchild=CreateBT2(post+k,p+1,n-k-1);
		return b;
		
}

int main(void)
{
		BTNode *b=CreateBTNode("A(B(D(,G)),C(E,F))");
		DispBTNode(b);
		printf("\n");
		printf("高度是%d\n",BTNodeHeight(b));
		BTNode *child=FindNode(b,'D');
		DispBTNode(child);
		printf("\n");
		BTNode *rb=LchildNode(b);
		DispBTNode(rb);
		printf("\n");

		PreOrder(b);
		printf("\n");
		InOrder(b);
		printf("\n");
		PostOrder(b);
		printf("\n");
		DispLeaf(b);
		printf("\n");
		Ancestor(b,'E');
		printf("\n");
		PreOrder1(b);
		InOrder1(b);
		PostOrder1(b);
		AllPath1(b);

		printf("层次遍历：\n");
		LevelOrder(b);
		BTNode *gb1=CreateBT1("ABDGCEF","DGBAECF",7);
		DispBTNode(gb1);
		BTNode *gb2=CreateBT2("GDBEFCA","DGBAECF",7);
		DispBTNode(gb2);
		return 0;
}
		
