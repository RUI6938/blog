#include<stdio.h>

int prime(int n) //1��ʾ�棬0��ʾ�٣�int  n������ʽ�������������÷�Χֻ�ڸú�����
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
 	// ��֤��°ͺղ��루��֤100���ڴ��ڵ���6��ż����
	 
	 int n;
	 int x,y;
	 for(n=6;n<=100;n+=2){
	 	//  n = x+y ,����y=(n-x),��x<=y
	 	// x��ȡֵ3,5,7����n/2
	 	for(x=3;x<=n/2;x+=2){
	 		// �ж�x������
			// �ж�yҲ������
			y = n - x;
			
			if(prime(x) == 1 && prime(y) == 1){
				printf("%d = %d +%d\n",n,x,y);
				break;
			} 
		 } 
	 }
 	return 0;
 }
