#include<stdio.h>

int main()
{
	//  ���100���ڵ�������Ҫ��ÿ10����һ����ʾ��֮��ո����
	//   ��1~100֮���������д���
	int i,j;
	int flag;
	int cnt = 0;
	for(i=2;i<=100;i++)
	{
		// �ж�i�ǲ�������
		 
		flag = true;
		for(j=2;j<=i/2;j++)
		{
			if(i%j == 0)
			{
				flag = false;
				break;
				
			}
			//����flag��ֵ���ж��ǲ������� 
		}
		if(flag == true) 
		 {
		 	printf("%d ",i);
		 	cnt++;
		 	if(cnt%10 == 0)
		 	printf("\n");
		  } 
	}

	return 0;
}
