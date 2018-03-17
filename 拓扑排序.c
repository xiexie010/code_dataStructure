#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef int InfoType;
typedef char Vertex;
typedef struct ANode
{

		int adjvex;
		struct ANode *nextarc;
		InfoType info;
}ArcNode;

typedef struct 
{
		Vertex data;
		int count;
		ArcNode *firstarc;
}VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
		AdjList adjlist;
		int n,e;
}AlGraph;

void TopSort(AlGraph *g)
{
		int i,j;
		int St[MAXV],top=-1;
		ArcNode *p;
		for(i=0;i<g->n;i++) //入入度初值为0
				g->adjlist[i].count=0;
		for(i=0;i<g->n;i++)
		{
				p=g->adjlist[i].firstarc;
				while(p!=NULL)
				{
						g->adjlist[p->adjvex].count++;
						p=p->nextarc;
				}
		}
		for(i=0;i<g->n;i++)
				if(g->adjlist[i].count==0)//入度为0的顶点进栈
				{
						top++;
						St[top]=i;
				}
		while(top>-1)//栈不为空时循环
		{
				i=St[top];top--;
				printf(" %d ",i);
				p=g->adjlist[i].firstarc;//找到第一个相邻点
				while(p!=NULL)
				{
						j=p->adjvex;
						g->adjlist[j].count--;
						if(g->adjlist[j].count==0)
						{
								top++;
								St[top]=j;
						}
						p=p->nextarc;
				}
		}
}

int Locate(AlGraph *g,char ch)
{
		int i;
		for(i=0;i<g->n;i++)
		{
				if(ch==g->adjlist[i].data)
						break;
		}
		if(i>=MAXV)
				i=-1;
		return i;
}

void  freeBuf()
{
		char c;
		while((c=getchar())!='\n');
}

void CreateAlGraph(AlGraph *g)
{
	ArcNode *e;
	ArcNode *f;
	printf("input vertexNux and edgeNum:\n");
	scanf("%d,%d",&g->n,&g->e);
	freeBuf();
	int i;
	//建立顶点信息
	for(i=0;i<g->n;i++)
	{
			printf("int %d vertex: ",(i+1));
			scanf("%c",&g->adjlist[i].data);
			freeBuf();
			g->adjlist[i].firstarc=NULL;
	}
	int k;
	//建立边表
	for(k=0;k<g->e;k++)
	{
			printf("input edge serialize num(i,j):\n");
			char j,l;
			scanf("%c,%c",&j,&l);
			freeBuf();
			int m,n;
			m=Locate(g,j);
			n=Locate(g,l);
			if(m==-1||n==-1)
					return ;
			e=(ArcNode *)malloc(sizeof(ArcNode));
			e->adjvex=n;
			e->nextarc=g->adjlist[m].firstarc;
			g->adjlist[m].firstarc=e;
	}
}
void DispGraph(AlGraph *g)
{
		int i=0;
		printf("DispGraph start. \n");
		while(g->adjlist[i].firstarc!=NULL||i<g->e)
		{
				printf("顶点： %c->",g->adjlist[i].data);
				ArcNode *e=NULL;
				e=g->adjlist[i].firstarc;
				while(e!=NULL)
				{
						printf("%d ",e->adjvex);
						e=e->nextarc;
				}
				i++;
				printf("\n");
		}
}


			


int main(void)
{
		AlGraph g;
		CreateAlGraph(&g);
		DispGraph(&g);
		TopSort(&g);
		return 0;
}

