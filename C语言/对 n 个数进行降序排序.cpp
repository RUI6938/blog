/*
 程序名称：对n个数进行降序排列 
 功能：用户输入0~10之间的n，再输入n个数，按从大到小排序
*/

#include <stdio.h>

int main()
{
	int n;
	int a[10];
	int i,j,temp;
	
	//输入n
	printf("请输入一个0~10之间的整数n：");
	scanf("%d",&n);
	
	//判断n是否合法
	if(n < 0 || n > 10)
	{
		printf("输入的n不合法！ \n");
		return 0;
	 } 
	 
	 //输入n个数
	 printf("请输入%d个整数: \n",n);
	 for(i = 0;i < n;i++)
	 {
	 	scanf("%d",&a[i]);
	 }
	 
	 //冒泡排序（从大到小）
	 for(i = 0;i < n-1; i++)
	 {
	 	for(j = 0;j < n - 1 - i;j++)
	 	{
	 		if(a[j] < a[j + 1])
	 		{
	 			temp = a[j];
	 			a[j] = a[j + 1];
	 			a[j + 1] = temp;
			 }
		 }
	  } 
	  //输出排序结果
	  printf("排序结果（从大到小）:\n");
	  for(i = 0; i < n; i++)
	  {
	  	printf("%d ",a[i]);
	  }
	  
	  return 0;
}




