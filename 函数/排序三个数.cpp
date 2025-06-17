#include<stdio.h>

//函数声明
void sortThreeNumbers(int* a, int* b, int* c);

int main(){
	int num1,num2,num3;
	//提示用户输入三个整数
	printf("请输入三个整数：\n");
	
	//从用户输入读取三个整数
	scanf("%d %d %d",&num1,&num2,&num3) ;
	
	//调用排序函数对三个数进行排序
	sortThreeNumbers(&num1,&num2,&num3);
	
	//输入排序后的三个数
	printf("排序后的三个数为：%d %d %d\n",num1,num2,num3);
	
	return 0; 
}
void sortThreeNumbers(int* a,int* b,int* c){
	int temp;
	//如果第一个数大于第二个数，交换他们的值
	if(*a > *b){
		temp = *a;
		*a = *b;
		*b = temp; 
}
//如果第一个数大于第三个数，交换他们的值
 if(*a > *c){
		temp = *a;
		*a = *c;
		*c = temp; 
	}
	//如果第二个数大于第三个数，交换他们的值
 if(*b > *c){
		temp = *b;
		*b = *c;
		*c = temp; 
	}
}
