#include<stdio.h>
int main()
{
	int i,m;
	printf("������һ������1��������\n");
	scanf("%d",&m);
	for(i=2;i<m;i++)
	{
		if(m%i==0)
		{
			printf("%d��������",m);
			break;
		}
		else
		printf("%d������\n",m);
		break;
	}
	return 0;
 } 
