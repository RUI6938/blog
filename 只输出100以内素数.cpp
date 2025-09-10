#include<stdio.h>

int main()
{
	//  输出100以内的素数，要求每10个在一行显示，之间空格隔开
	//   对1~100之间是数进行处理
	int i,j;
	int flag;
	int cnt = 0;
	for(i=2;i<=100;i++)
	{
		// 判断i是不是素数
		 
		flag = true;
		for(j=2;j<=i/2;j++)
		{
			if(i%j == 0)
			{
				flag = false;
				break;
				
			}
			//根据flag的值来判断是不是素数 
		}
		if(flag == true) 
		 {
		 	printf("%d ",i);
		 	cnt++;
		 	if(cnt%10 == 0)
		 	printf("\n");
		  } 
	}

	return 0;
}
