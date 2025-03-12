package com.itheima.test;

public class Test14 {
    public static void main(String[] args){
        /*  需求：在实际开发中，如果要获取一个范围中的每一个数据时，也会用到循环。
            比如：求1-5之间的和
         */

        //分析
        //1：循环1-5得到里面的每一个数字
        //开始条件：1
        //结束条件：5

        //用来进行累加的
        int sum = 0;
        for (int i = 0; i <=5; i++) {
            //可以吧得到的每一个数字累加到变量sum当中
            sum = sum + i;// sum += i;

        }
        //当循环结束之后，表示已经把1-5累加到变量sum当中了
        System.out.println(sum);
    }
}
