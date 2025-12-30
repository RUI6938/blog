/*
 程序名称：SimpleBankSystem
 功能：模拟银行存款与取款的基本操作
*/

#include <stdio.h>

int main()
{
	int choice;
	double balance = 1000.0;  //初始余额
	double money;
	
	while(1)
	{
		printf("\n====== 银行存取款系统 ======\n");
        printf("1. 查询余额\n");
        printf("2. 存款\n");
        printf("3. 取款\n");
        printf("4. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
        	printf("当前余额为: %.2f 元\n",balance);
		}
		else if (choice == 2)
		{
			printf("请输入存款金额: ");
			scanf("%lf",&money);
			
			if(money <= 0)
			{
				printf("存款金额不合法！\n");
			}
			else
			{
				balance += money;
				printf("存款成功！当前余额：%.2f 元\n",balance);
			}
		}
		else if (choice == 3)
		{
			printf("请输入取款金额：");
			scanf("%lf",&money);
			
			if(money <= 0)
			{
				printf("取款金额不合法！\n");
			}
			else if (money > balance)
			{
				printf("余额不足，取款失败！\n");
			}
			else
			{
				balance -= money;
				printf("取款成功！当前余额：%.2f 元\n",balance);
			}
		 } 
		 else if (choice == 4)
		 {
		 	printf("谢谢使用，再见！\n");
		 	break;
		 }
		 else
		 {
		 	printf("选择错误，请重新输入！\n");
		 }
	 } 
	 return 0;
}



