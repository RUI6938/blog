#include<stdio.h>
//get_max���������
int get_max(int x, int y)
{
	return (x > y) ? (x) : (y);//��Ŀ���㷨��x����y����x��xС��y����y 
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
