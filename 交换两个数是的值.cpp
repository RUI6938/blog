#include<stdio.h>
void Swap2(int* p1,int* p2)
{
	int tmp = 0;
	tmp = *p1;//tmp = a
	*p1 = *p2;//a = b
	*p2 = tmp;//b = tmp
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d",&a,&b); 
	printf("交换前： a = %d b = %d\n",a,b);
	Swap2(&a,&b);
	printf("交换后： a = %d b = %d\n",a,b);
	return 0;
}
