#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define Errow -1
typedef int ElemType;
typedef int Status;

typedef struct snode
{
		char data;
		struct snode *next;
}LiString;


//赋值
void StrAssign(LiString *s,char cstr[])
{
		int i;
		LiString *r=s,*p;

		for(i=0;cstr[i]!='\0';i++)
		{
				p=(LiString *)malloc(sizeof(LiString));
				p->data=cstr[i];
				r->next=p;
				r=p;
		}
		r->next=NULL;
}

LiString* String(char cstr[])
{
		LiString *s=(LiString *)malloc(sizeof(LiString));
		StrAssign(s,cstr);
		return s;
}

void StrCopy(LiString *s,LiString *t)
{
		LiString *r,*p,*q;
		r=s;
		p=t->next;
		while(p!=NULL)
		{
			q=(LiString *)malloc(sizeof(LiString));
			q->data=p->data;
			r->next=q;
			r=q;
			p=p->next;
		}
		r->next=NULL;
}
void DisStr(LiString *s)
{
		LiString *p=s->next;
		printf("s的值是:");
		while(p!=NULL)
		{
				printf("%c",p->data);
				p=p->next;
		}
		printf("\n");
}
Status StrEqual(LiString *s1,LiString *s2)
{
		LiString *p=s1->next,*q=s2->next;
		while(p!=NULL&&q!=NULL&&p->data!=q->data)
		{
				p=p->next;
				q=q->next;
		}
		if(p!=NULL&&q!=NULL)
				return Errow;
		else 
				return Ok;
}


int main(void)
{
		LiString *s1=(LiString *)malloc(sizeof(LiString));
		char str1[]="xiexie010";
		StrAssign(s1,str1);
		LiString *s2=(LiString *)malloc(sizeof(LiString));
		StrCopy(s2,s1);
		DisStr(s1);
		DisStr(s2);
	
		LiString *s3=String("longxiexie");
		DisStr(s3);

		return 0;
}



