#include<stdio.h>
int main(){
	int n,m;
	long long sum = 0;
	long long fact = 1;
	
	//��������
	printf("��������������n��m(n<m) :") ;
	scanf("%d %d",&n,&m);
	
	//��֤������Ч��
	if(n > m){
		printf("����n����С��m��\n");
		return 1;//�������˳� 
	} 
	if(n < 0 || m < 0){
		printf("�������벻��Ϊ������\n");
		return 1;
	}
	/*
	1:��1��ʼѭ����m
	2�����㵱ǰ��i�Ľ׳�
	3.��i >= nʱ�����׳�ֵ�����ܺ� 
	*/ 
	
	for(int i = 1;i <= m;i++){
		fact *= i;//����i�Ľ׳� = (i-1)! * i
		
		//��i�ﵽ��ʼֵnʱ��ʼ�ۼ�
		if(i >= n){
			sum += fact;
		} 
	}
	//������
	printf("%d��%d�Ľ׳˺�Ϊ��%lld\n",n,m,sum);
	
	return 0;//�����˳� 
	
}
