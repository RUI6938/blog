#include<stdio.h>

int prime(int n) //1表示真，0表示假，int  n就是形式参数，他的作用范围只在该函数内
{
	int i;
	int flag = 1;
	for(i=2;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
 } 
 
 int main()
 {
 	// 验证哥德巴赫猜想（验证100以内大于等于6的偶数）
	 
	 int n;
	 int x,y;
	 for(n=6;n<=100;n+=2){
	 	//  n = x+y ,其中y=(n-x),设x<=y
	 	// x的取值3,5,7……n/2
	 	for(x=3;x<=n/2;x+=2){
	 		// 判断x是素数
			// 判断y也是素数
			y = n - x;
			
			if(prime(x) == 1 && prime(y) == 1){
				printf("%d = %d +%d\n",n,x,y);
				break;
			} 
		 } 
	 }
 	return 0;
 }
