#include<stdio.h>

//����һ�����������ڼ����������ĺ�
int multiplyNumbers(int a,int b){
	return a * b;
} 

int main(){
	int num1,num2,result;
	//��ʾ�û������һ����
	printf("�������һ������");
	//���û������ж�ȡ��һ����������num1
	scanf("%d",&num1);
	
	//��ʾ�û�����ڶ�����
	printf("������ڶ�������");
	//���û������ж�ȡ�ڶ�����������num2
	scanf("%d",&num2);
	
	//����multiplyNumbers��������num1��num2��Ϊ�������룬��������֮�Ͳ�����result
	result = multiplyNumbers(num1,num2);
	printf("����֮��Ϊ��%d\n",result);
	
	return 0; 
}
