#include<stdio.h>
//get_max函数的设计
int get_max(int x, int y)
{
	return (x > y) ? (x) : (y);//三目运算法：x大于y返回x，x小于y返回y 
 } 
 int main()
 {
 	int a = 0;
 	int b = 0;
 	scanf("%d %d",&a,&b);
 	int max = get_max(a, b);
 	printf("max = %d\n",max);
 	
 	return 0;
 }
