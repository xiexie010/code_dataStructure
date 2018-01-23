#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define Errow -1
#define MaxSize 100
typedef int ElemType;
typedef int Status;

typedef struct 
{
		char data[MaxSize];
		int length;
}SqString;

//给s赋值
void StrAssign(SqString *s,char cstr[])
{
		int i;
		for(i=0;cstr[i]!='\0';i++)
				s->data[i]=cstr[i];
		s->length=i;
}

void StrCopy(SqString *s,SqString str)
{
		int i;
		for(i=0;i<str.length;i++)
			s->data[i]=str.data[i];
		s->length=i;
}
//判断会否相等
Status StrEqual(SqString *s,SqString str)
{
		int i;
		if(s->length!=str.length)
				return Errow;
		else
				for(i=0;i<s->length;i++)
						if(s->data[i]!=str.data[i])
								return Errow;
		return Ok;
}
//串长度
int StrLength(SqString *s)
{
		return s->length;
}
//连接两个字符串
SqString* ConCat(SqString *s1,SqString *s2)
{
		SqString *r=(SqString *)malloc(sizeof(SqString));
		int i;
		int length=s1->length+s2->length;
		for(i=0;i<s1->length;i++)
				r->data[i]=s1->data[i];
		for(i=0;i<s2->length;i++)
				r->data[s1->length+i]=s2->data[i];
		r->length=length;
		return r;
}
//求子串
SqString* SubStr(SqString *s,int i,int n)
{
		SqString *r=(SqString *)malloc(sizeof(SqString));
		int k;
		if(i<=0||i > s->length||n<0||i+n-1>s->length)
		{
				return r;
		}
		for(k=i-1;k<i+n-1;k++)
		{
				r->data[k-i+1]=s->data[k];
		}
		r->length=n;
		return r;
}
//插入子串
SqString* InsStr(SqString *s1,int i,SqString *istr)
{
		SqString *r=(SqString *)malloc(sizeof(SqString));
		int j;
		if(i<=0||i>s1->length+1)
				return r;
		for(j=0;j<i-1;j++)
				r->data[j]=s1->data[j];
		for(j=0;j<istr->length;j++)
				r->data[i-1+j]=istr->data[j];
		for(j=i-1;j<s1->length;j++)
		{
				r->data[j+istr->length]=s1->data[j];
		}
		r->length=s1->length+istr->length;
		return r;
}
//删除第i个字符开始长度为j的字串
SqString *DelStr(SqString *s,int i,int j)
{
		int k;
		SqString *r=(SqString *)malloc(sizeof(SqString));
		if(i<=0||i>s->length||i+j>s->length+1)
				return r;
		for(k=0;k<i-1;k++)
				r->data[k]=s->data[k];
		for(k=i+j-1;k<s->length;k++)
				r->data[k-j]=s->data[k];
		r->length=s->length-j;
		return r;
}



int main(void)
{
		SqString str1;
		char cstr[]="xiexie";
		StrAssign(&str1,cstr);
		printf("字符串是%s\n",str1.data);
		SqString *str2=(SqString *)malloc(sizeof(SqString));
		char cstr2[]="women";
		StrAssign(str2,cstr2);
		SqString *str3=ConCat(&str1,str2);
		printf("合并后的串是%s\n",str3->data);
		SqString *sstr=SubStr(str3,3,4);
		printf("子串是%s\n",sstr->data);
		SqString *astr=InsStr(str3,7,sstr);
		printf("插入后的%s\n",astr->data);
		SqString *dastr=DelStr(astr,4,7);
		printf("删除后的字符串是%s\n",dastr->data);
		return 0;
}


