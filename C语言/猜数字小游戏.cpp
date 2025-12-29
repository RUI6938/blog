/*
  程序名称：GuessNumber —— 猜数字小游戏
  玩法：电脑随机生成 1~100 的整数，玩家不断猜，程序提示大了/小了，猜中结束。
  额外：输入 0 可随时退出；对非数字输入做了处理。
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int target,guess,cnt = 0;
	
	srand((unsigned)time(NULL));
	target = rand() % 100 + 1;
	
    printf("==== GuessNumber：猜数字小游戏 ====\n");
    printf("我已经想好了一个 1~100 的整数。\n");
    printf("你来猜！(输入 0 退出)\n\n");
    
    while(1)
    {
    	printf("请输入您的预测：");
    	
    	//输入校验，如果不是整数，就清空输入缓冲区并让用户重输
		if(scanf("%d",&guess) != 1)
		{
			int ch;
			while((ch = getchar()) != '\n' && ch != EOF){} //清掉错误输入
			printf("输入无效，请输入一个整数！\n");
			continue;
		 } 
		 
		 if(guess == 0)
		 {
		 	printf("你选择退出。正确答案是 %d。\n", target);
		 	break;
		 }
		 
		 if(guess < 1 || guess > 100)
		 {
		 	printf("范围不对！请输入 1~100。\n");
		 	continue;
		 }
		 
		 cnt++;
		 
		 
		 if(guess < target)
		 	printf("小啦！\n");
		 	else if(guess > target)
		 	printf("大啦！\n");
		 	else
		 	{
		 		printf("恭喜你猜对了！答案就是 %d。\n", target);
		 		printf("你一共猜了 %d 次。\n", cnt);
		 		break;
			 }
	}
	return 0;
 } 
 
