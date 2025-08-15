#include<stdio.h>
int main()
{
	int x;
	int n=0;
	scanf("%d",&x);
	
	while(x>0){
		x/=10;
		n++;
	}
	printf("%dÎ»Êı\n",n);
	
	return 0;
}
