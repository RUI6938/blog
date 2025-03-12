package com.itheima.test1;

public class Test2 {
    public static void main(String[] args){
        //需求：定义一个方法，求圆的面积，将结果在方法中进行打印

        //目标：根据不同的需求，选择定义无参的方法，还是带参数的方法



        getArea(2.1);

    }
    //1：明确我要干嘛？   请圆的面积
    //2：明确我要干这件事情，需要什么才能够完成？    半径
    public static void getArea(double radius){
         double result = radius * radius * 3.14;
        System.out.println(result);

    }

}
