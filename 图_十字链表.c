#include <stdio.h>
#include <stdlib.h>
#define MaxVex 100
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
		int adjvex;
		EdgeType weight;
		struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
		VertexType data;
		EdgeNode *firstedge;
}VertexNode;

typedef struct{
		VertexNode adjList[MaxVex];
		int vnum,enumber;
}GraphyAdjList;

int Locate(GraphyAdjList *g,char ch)
{
		int i;
		for(i=0;i<g->vnum;i++)
		{
				if(ch==g->adjList[i].data)
					break;
		}
		if(i>=MaxVex)
				i=-1;
		return i;
}
void freeBuf()
{
		char c;
		while((c=getchar())!='\n');
}

void CreateGraphy(GraphyAdjList *g)
{
		EdgeNode *e;
		EdgeNode *f;
		printf("input vertexNum and edgeNum:\n");
		scanf("%d,%d",&g->vnum,&g->enumber);
		freeBuf();
		int i;
		//建立顶点信息
		for(i=0;i<g->vnum;i++)
		{
				
				printf("int %d vertex: ",(i+1));
				scanf("%c",&g->adjList[i].data);
				freeBuf();
				g->adjList[i].firstedge=NULL;
		}
		int k;
		//建立边表
		for(k=0;k<g->enumber;k++)
		{
				printf("input edge serialize num (i,j):\n");
				char j,l;
				scanf("%c,%c",&j,&l);
				freeBuf();
				int m,n;
				m=Locate(g,j);
				n=Locate(g,l);
				if(m==-1||n==-1)
					return ;
				e=(EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex=n;
				e->next=g->adjList[m].firstedge;
				g->adjList[m].firstedge=e;
				f=(EdgeNode *)malloc(sizeof(EdgeNode));
				f->adjvex=m;
				f->next=g->adjList[n].firstedge;
				g->adjList[n].firstedge=f;
		}
}
void DispGraph(GraphyAdjList *g)
{
		int i=0;
		printf("DispGraph start . \n");
		while(g->adjList[i].firstedge!=NULL&&i<MaxVex)
		{
				printf("顶点：%c ->",g->adjList[i].data);
				EdgeNode *e=NULL;
				e=g->adjList[i].firstedge;
				while(e!=NULL)
				{
						printf("%d ",e->adjvex);
						e=e->next;
				}
				i++;
				printf("\n");
		}
}
int visitied[MaxVex];
//深度优先遍历
void DFS(GraphyAdjList *g,int v)
{
		EdgeNode *p;
		visitied[v]=1;
		printf("%d ",v);
		p=g->adjList[v].firstedge;
		while(p!=NULL)
		{
				if(visitied[p->adjvex]==0)
						DFS(g,p->adjvex);
				p=p->next;
		}
}
//广度优先遍历
void BFS(GraphyAdjList *g,int v)
{
		EdgeNode *p;
		int queue[MaxVex],front=0,rear=0;
		int visitedb[MaxVex];
		int w,i;
		for(i=0;i<g->vnum;i++)
				visitedb[i]=0;
		printf(" %2d",v);
		visitedb[v]=1;
		rear=(rear+1)%MaxVex;
		queue[rear]=v;
		while(front!=rear)
		{
				front=(front+1)%MaxVex;
				w=queue[front];
				p=g->adjList[w].firstedge;
				while(p!=NULL)
				{
						if(visitedb[p->adjvex]==0)
						{
								printf(" %2d",p->adjvex);
								visitedb[p->adjvex]=1;
								rear=(rear+1)%MaxVex;
								queue[rear]=p->adjvex;
						}
						p=p->next;
				}
		}
		printf("\n");
}


int main(void)
{
		GraphyAdjList g;
		CreateGraphy(&g);
		DispGraph(&g);
		DFS(&g,0);
		BFS(&g,0);
		return 0;
}


