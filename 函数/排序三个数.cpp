#include<stdio.h>

//��������
void sortThreeNumbers(int* a, int* b, int* c);

int main(){
	int num1,num2,num3;
	//��ʾ�û�������������
	printf("����������������\n");
	
	//���û������ȡ��������
	scanf("%d %d %d",&num1,&num2,&num3) ;
	
	//��������������������������
	sortThreeNumbers(&num1,&num2,&num3);
	
	//����������������
	printf("������������Ϊ��%d %d %d\n",num1,num2,num3);
	
	return 0; 
}
void sortThreeNumbers(int* a,int* b,int* c){
	int temp;
	//�����һ�������ڵڶ��������������ǵ�ֵ
	if(*a > *b){
		temp = *a;
		*a = *b;
		*b = temp; 
}
//�����һ�������ڵ����������������ǵ�ֵ
 if(*a > *c){
		temp = *a;
		*a = *c;
		*c = temp; 
	}
	//����ڶ��������ڵ����������������ǵ�ֵ
 if(*b > *c){
		temp = *b;
		*b = *c;
		*c = temp; 
	}
}
