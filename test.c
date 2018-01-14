#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
		int i;
}One;

One* Two(void)
{		
		One *o=(One *)malloc(sizeof(One));
		o->i=10;
		return o;
}

void testtest(One* on)
{
	on=(One *)malloc(sizeof(One));
	on->i=11;	
	printf("xiexie");
}
void testtwo(One** ppone)
{
	One* po=*ppone;
	
}
void swap(One **o1,One **o2)
{
		*o1=*o2;
}
int main(void)
{
	/*	One **one;
		printf("%ld\n",one);
		one
		one=(One *)malloc(sizeof(One));
		printf("%ld\n",one);
		
		Two(one);
		printf("%d\n",(*one)->i);
		*/
		One *one=Two();
		//One *two;
	//	testtest(two);
		printf("%d\n",one->i);
		//printf("%d\n",two->i);
		
	//	One **pp;
	//	testtwo(pp);
		One p1,p2;
		One *pp1=&p1;
		One *pp2=&p2;
		swap(&pp1,&pp2);
		printf("%ld,%ld\n",&p1,&p2);
		return 0;
}

