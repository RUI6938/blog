#include <stdio.h>
int main(){
	int i,j;//定义循环变量，i控制行，j控制列
	
	//外层循环：控制行数（1到9）
	for(i = 1;i <= 9;i++){
		//内层循环：控制当前行的列数（1到当前行数i）
		for(j = 1;j <=i;j++){
			//打印乘法算式：j * i = 结果 
			//使用%-2d确保每个结果占2位并左对齐，使表格整齐
			printf("%d×%d=%-2d ",j,i,j * i);
		} 
		printf("\n");//每行结束后换行 
	} 
	return 0;
}
