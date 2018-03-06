#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 6
#define INF 100
#define MAXSIZE 20

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
typedef struct
{
		int u;
		int v;
		int w;
}Edge;
void InsertSort(Edge e[],int n)
{
		int i,j;
		for(i=n-1;i>=0;i--)
				for(j=1;j<i;j++)
				{
						if(e[j-1].w>e[j].w)
						{
								Edge e1=e[j-1];
								e[j-1]=e[j];
								e[j]=e1;
						}
				}
}
void Kruskal(MGraph g)
{
		int i,j,u1,v1,sn1,sn2,k;
		int vset[MAXVEX];
		Edge E[MAXSIZE];
		k=0;
		for(i=0;i<g.n;i++)
				for(j=0;j<g.n;j++)
						if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
						{
								E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
								k++;
						}
		InsertSort(E,g.e*2);
		for(i=0;i<g.e*2;i++)
			printf("E[%d]的值是%d %d %d\n",i,E[i].u,E[i].v,E[i].w);
		for(i=0;i<g.n;i++)
			vset[i]=i;
		k=1;
		j=0;
		while(k<g.n)
		{
				u1=E[j].u;v1=E[j].v;
				sn1=vset[u1];
				sn2=vset[v1];
				if(sn1!=sn2)
				{
						printf("(%d,%d):%d\n",u1,v1,E[j].w);
						k++;
						for(i=0;i<g.n;i++)
								if(vset[i]==sn2)
										vset[i]=sn1;
						
				}
				j++;
		}
}



void Prim(MGraph g,int v)
{
		int lowcost[MAXVEX];
		int min;
		int closest[MAXVEX],i,j,k;
		for(i=0;i<g.n;i++)
		{
				lowcost[i]=g.edges[v][i];
				closest[i]=v;
		}
		for(i=1;i<g.n;i++)
		{
				min=INF;
				for(j=0;j<g.n;j++)
					if(lowcost[j]!=0&&lowcost[j]<min)
					{
							min=lowcost[j];
							k=j;
					}
				printf("边(%d,%d)权为：%d\n",closest[k],k,min);
				lowcost[k]=0;
				for(j=0;j<g.n;j++)
					if(g.edges[k][j]!=0&&g.edges[k][j]<lowcost[j])
					{
							lowcost[j]=g.edges[k][j];
							closest[j]=k;
					}
		}
}

int main(void)
{
		int i,j;
		MGraph g;
		g.n=6;g.e=10;
		int A[MAXVEX][MAXVEX]={
				{0,6,1,5,INF,INF},
				{6,0,5,INF,3,INF},
				{1,5,0,5,6,4},
				{5,INF,5,0,INF,2},
				{INF,3,6,INF,0,6},
				{INF,INF,4,2,6,0}
		};
		for(i=0;i<g.n;i++)
			for(j=0;j<g.n;j++)
					g.edges[i][j]=A[i][j];
		//Prim(g,0);
		Kruskal(g);
		return 0;
}
