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
        flag=0;//flag=0��ʾ�����Ϸ�
        scanf("%s",a);
        for(int j=0;a[j]!='\0';j++)
        {
            if(a[j]=='S')//��ջ����
            {
                len++;
                if(len>max)//ջ��
                flag=1;
            }
            else if(a[j]=='X')//��ջ����
            {
                len--;
                if(len<0)
                flag=1;
            }
        }
        if(len==0&&flag==0)//�Ϸ�����
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

