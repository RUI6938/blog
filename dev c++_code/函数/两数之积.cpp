#include<stdio.h>

//定义一个函数，用于计算两个数的和
int multiplyNumbers(int a,int b){
	return a * b;
} 

int main(){
	int num1,num2,result;
	//提示用户输入第一个数
	printf("请输入第一个数：");
	//从用户输入中读取第一个数并存入num1
	scanf("%d",&num1);
	
	//提示用户输入第二个数
	printf("请输入第二个数：");
	//从用户输入中读取第二个数并存入num2
	scanf("%d",&num2);
	
	//调用multiplyNumbers函数，将num1和num2作为参数传入，计算两数之和并存入result
	result = multiplyNumbers(num1,num2);
	printf("两数之积为：%d\n",result);
	
	return 0; 
}
