#include <stdio.h>
int main()
{
    int n, max;
    int len;
    int flag;
    char a[110];
    scanf("%d %d",&n,&max);
    getchar();
    for(int i=0;i<n;i++)
    {
        len=0;
        flag=0;//flag=0表示操作合法
        scanf("%s",a);
        for(int j=0;a[j]!='\0';j++)
        {
            if(a[j]=='S')//入栈操作
            {
                len++;
                if(len>max)//栈满
                flag=1;
            }
            else if(a[j]=='X')//出栈操作
            {
                len--;
                if(len<0)
                flag=1;
            }
        }
        if(len==0&&flag==0)//合法条件
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

