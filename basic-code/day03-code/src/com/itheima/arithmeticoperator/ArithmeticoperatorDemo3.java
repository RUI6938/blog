package com.itheima.arithmeticoperator;

public class ArithmeticoperatorDemo3 {
    public static void main(String[] args){
        byte b1 = 100;
        byte b2 = 100;
        //现在我们要强制转的是谁？
        //b1 + b2计算之后的结果
        //(byte)b1 + b2 强制转化的是b1，并不是最终的结果
        byte result = (byte)(b1 + b2);
        System.out.println(result);//结果就发生了错误，因为要转化的数据过大
    }
}
