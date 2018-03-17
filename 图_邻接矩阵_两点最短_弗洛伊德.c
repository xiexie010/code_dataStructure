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
void Dispath(int A[][MAXVEX],int path[][MAXVEX],int n);

//弗洛伊德
void Floyd(MGraph g)
{

		int A[MAXVEX][MAXVEX],path[MAXVEX][MAXVEX];
		int i,j,k;
		for(i=0;i<g.n;i++)
		{
				for(j=0;j<g.n;j++)
				{
						A[i][j]=g.edges[i][j];
						path[i][j]=-1;
				}
		}
		for(k=0;k<g.n;k++)
		{
				for(i=0;i<g.n;i++)
				{
						for(j=0;j<g.n;j++)

								if(A[i][j]>A[i][k]+A[k][j])
								{
										A[i][j]=A[i][k]+A[k][j];
										path[i][j]=k;
								}
				}
		}
		Dispath(A,path,g.n);
}
void Ppath(int path[][MAXVEX],int i,int j)
{
		
		int k;
		k=path[i][j];
		
		if(k==-1)return;
		Ppath(path,i,k);
		printf(" %d, ",k);
		Ppath(path,k,j);
		
}

void Dispath(int A[][MAXVEX],int path[][MAXVEX],int n)
{
		int i,j;
		for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
						if(A[i][j]!=INF&&i!=j)
						{
								printf("从%d到%d=>路径长度：%d路径:",i,j,A[i][j]);
								printf(" %d, ",i);//输出路径上的起点
								Ppath(path,i,j);//输入路径上的中间点
								printf(" %d\n",j);//输出路径上的终点
						}
				}
}

										
						

int main(void)
{
		int i,j;
		MGraph g;
		g.n=4;g.e=9;
		int A[4][4]={
				{0,5,INF,7},
				{INF,0,4,2},
				{3,3,0,2},
				{INF,INF,1,0}
		};
		for(i=0;i<g.n;i++)
			for(j=0;j<g.n;j++)
					g.edges[i][j]=A[i][j];
		Floyd(g);
		return 0;
}
