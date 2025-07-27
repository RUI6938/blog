#include<stdio.h>
int main(){
	int n,m;
	long long sum = 0;
	long long fact = 1;
	
	//输入提醒
	printf("请输入两个整数n和m(n<m) :") ;
	scanf("%d %d",&n,&m);
	
	//验证输入有效性
	if(n > m){
		printf("错误：n必须小于m！\n");
		return 1;//非正常退出 
	} 
	if(n < 0 || m < 0){
		printf("错误：输入不能为负数！\n");
		return 1;
	}
	/*
	1:从1开始循环到m
	2：计算当前数i的阶乘
	3.当i >= n时，将阶乘值加入总和 
	*/ 
	
	for(int i = 1;i <= m;i++){
		fact *= i;//计算i的阶乘 = (i-1)! * i
		
		//当i达到起始值n时开始累加
		if(i >= n){
			sum += fact;
		} 
	}
	//输出结果
	printf("%d到%d的阶乘和为：%lld\n",n,m,sum);
	
	return 0;//正常退出 
	
}
