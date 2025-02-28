package com.itheima.arithmeticoperator;

public class ArithmeticoperatorDemo2 {
    public static void main(String[] args){
        //除法
        System.out.println(10 / 2);//5
        System.out.println(10 / 3);//3
        System.out.println(10.0 / 3);//3.3333333333333335

        //取模，取余。实际上也是做除法运算，只不过得到是余数而已
        System.out.println(10 % 2);//0
        System.out.println(10 % 3);//1

        //应用场景：
        //1.可以用取模来判断，A是否可以被B整除
        //A % B       10 % 3
        //2.可以判断A是否为偶数
        //A % 2 如果结果为0，那么证明A是一个偶数；如果结果为1，那么证明A是一个奇数
        //3.在以后，斗地主发牌
        //三个玩家
        //把每一张牌都定义一个序号
        //拿着序号 % 3 如果结果为1，就发给第一个玩家
        //如果结果为2，那么就发给第二个玩家
        //如果结构为0，那么就发给第三个玩家
    }
}
