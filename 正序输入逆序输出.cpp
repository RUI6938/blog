#include<stdio.h>
int main()
{
	int a[110];//a[0] a[]1 a[2]����a{119} 
	int i,n;
	scanf("%d",&n);//nΪ���뼸���� 
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//a[1] a[2] ����a[n]
	 
	for(i=n;i>=1;i--)//n n-1 n-2����1 
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
