package com.itheima.arithmeticoperator;

public class ArithmeticoperatorDemo6 {
    public static void main(String[] args){
        int x = 10;
        //后++：先用后加
        //先把x变量中的值拿出来用，赋值给y，然后再进行自增
        //赋值给y的值是自增前的
        int y = x++;
        //先++，先加后用
        //先把x进行自增，然后把自增后的结果赋值给左边的变量
        //先把x自增，变成12，然后再把自增之后的12赋值给z
        int z = ++x;
        System.out.println("x:" + x);
        System.out.println("y:" + y);
        System.out.println("z:" + z);
    }
}
