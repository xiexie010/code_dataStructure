#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 7
#define INF 32767
#define MAXSIZE 100
typedef int InfoType;
typedef struct
{
		int no;
		InfoType info;
}VertexType;

typedef struct 
{
		int edges[MAXVEX][MAXVEX];
		int n,e;
		VertexType vexs[MAXVEX];
}MGraph;

void Dispath(int dist[],int path[],int s[],int n,int v);
//狄克斯特拉算法
void Dijkstra(MGraph g,int v)
{
		int dist[MAXVEX],path[MAXVEX];
		int s[MAXVEX];
		int mindis,i,j,u;

		for(i=0;i<g.n;i++)
		{
				dist[i]=g.edges[v][i];//距离初始化
				s[i]=0;
				if(g.edges[v][i]<INF)
						path[i]=v;
				else
						path[i]=-1;
		}
		s[v]=1;
		path[v]=0;
		for(i=0;i<g.n;i++)
		{
				mindis=INF;
				for(j=0;j<g.n;j++)//选取不在s中且距离最小的顶点u
						if(s[j]==0&&dist[j]<mindis)
						{
								u=j;
								mindis=dist[j];
						}
				s[u]=1;
				for(j=0;j<g.n;j++)
						if(s[j]==0)
								if(g.edges[u][j]<INF&&dist[u]+g.edges[u][j]<dist[j])
								{
										dist[j]=dist[u]+g.edges[u][j];
										path[j]=u;
								}
		}
		Dispath(dist,path,s,g.n,v);
}
int ppath[MAXVEX];
void Dispath(int dist[],int path[],int s[],int n,int v)
{
		printf("dist:\n");
		int i;
		for(i=0;i<MAXVEX;i++)
		{
				printf("%d ",dist[i]);
		}
		printf("\npath:\n");
		for(i=0;i<MAXVEX;i++)
		{
				printf("%d ",path[i]);
				ppath[i]=path[i];
		}
		printf("\ns:\n");
		for(i=0;i<MAXVEX;i++)
		{
				printf("%d ",s[i]);
		}
		printf("\n");	
}
//查找两点距离
void Ppath(int path[],int i,int v)
{
		int k;
		k=path[i];
		if(k==v)return;
		Ppath(path,k,v);
		printf(" %d,",k);
}

int main(void)
{
		int i,j;
		MGraph g;
		g.n=7;g.e=12;
		int A[MAXVEX][MAXVEX]={
				{0,4,6,6,INF,INF,INF},
				{INF,0,1,INF,7,INF,INF},
				{INF,INF,0,INF,6,4,INF},
				{INF,INF,2,0,INF,5,INF},
				{INF,INF,INF,INF,0,INF,6},
				{INF,INF,INF,INF,1,0,8},
				{INF,INF,INF,INF,INF,INF,0}
		};
		for(i=0;i<g.n;i++)
			for(j=0;j<g.n;j++)
					g.edges[i][j]=A[i][j];

		Dijkstra(g,0);
		Ppath(ppath,4,0);
		return 0;
}
