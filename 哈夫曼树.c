#include <stdio.h>
#include <stdlib.h>

#define N 20

typedef struct 
{
		char data;
		double weight;
		int parent;
		int lchild;
		int rchild;
}HTNode;

typedef struct
{
		char cd[N];
		int start;
}HCode;

void CreateHt(HTNode ht[],int n)
{
		int i,j,k,lnode,rnode;
		double min1,min2;
		for(i=0;i<2*n-1;i++)
		{
			ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
		}

		for(i=n;i<2*n-1;i++)
		{
				min1=min2=32767;
				lnode=rnode=-1;
				for(k=0;k<=i-1;k++)
					if(ht[k].parent==-1)
					{
							if(ht[k].weight<min1)
							{
									min2=min1;rnode=lnode;
									min1=ht[k].weight;lnode=k;
							}
							else if(ht[k].weight<min2)
							{
									min2=ht[k].weight;rnode=k;
							}
					}
				ht[i].weight=ht[lnode].weight+ht[rnode].weight;
				ht[i].lchild=lnode;ht[i].rchild=rnode;
				ht[lnode].parent=i;ht[rnode].parent=i;
		}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n)
{
		int i,f,c;
		HCode hc;
		for(i=0;i<n;i++)
		{
				hc.start=n;c=i;
				f=ht[i].parent;
				while(f!=-1)
				{
						if(ht[f].lchild==c)
								hc.cd[hc.start--]='0';
						else
								hc.cd[hc.start--]='1';
						c=f;f=ht[f].parent;
				}
				hc.start++;
				hcd[i]=hc;
		}
}

int main(void)
{
		char a[]="abcdefgh";
		double b[]={0.07,0.19,0.02,0.06,0.32,0.03,0.21,0.10};
		int i;
		HTNode htnode[16];
		for(i=0;i<(2*8-1);i++)
		{
				if(i<8)
				{
					HTNode *h=(HTNode *)malloc(sizeof(HTNode));
					h->data=a[i];
					h->weight=b[i];	
					h->parent=h->lchild=h->rchild=-1;
					htnode[i]=*h;	
				}
				else
				{
						HTNode *h=(HTNode *)malloc(sizeof(HTNode));
						h->data='a';
						h->weight=0;
						h->parent=h->lchild=h->rchild=-1;
						htnode[i]=*h;
				}

		}
		
		CreateHt(htnode,8);
		HCode hcode[8];
		CreateHCode(htnode,hcode,8);
		for(i=0;i<8;i++)
			printf("%s ",hcode[i].cd+hcode[i].start);

		return 0;
}		
