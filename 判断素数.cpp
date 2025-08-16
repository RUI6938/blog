#include<stdio.h>
int main()
{
	int i,m;
	printf("请输入一个大于1的整数：\n");
	scanf("%d",&m);
	for(i=2;i<m;i++)
	{
		if(m%i==0)
		{
			printf("%d不是素数",m);
			break;
		}
		else
		printf("%d是素数\n",m);
		break;
	}
	return 0;
 } 
