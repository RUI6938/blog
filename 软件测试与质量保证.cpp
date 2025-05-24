#include<stdio.h>
#include<math.h>
void DoWork(int x, int y, int z){
    int k = 0, j = 0;
    if ((x>0) && (z<10)){
        k = x*y - 1;
        j = sqrt(k);
    }
    if ((x == 4) || (y>5))
        j = x*y + 10;
    j = j % 3;
    printf("j=%d\n",j);
    printf("k=%d\n",k);
}
void main(){
    int a,b,c;
    printf("input the first number:");
    scanf("%d",&a);
    printf("input the second number:");
    scanf("%d",&b);
    printf("input the third number:");
    scanf("%d",&c);
    DoWork(a,b,c);
    printf("¼ÆËã»ú39 ÕÅºÆ");
}
