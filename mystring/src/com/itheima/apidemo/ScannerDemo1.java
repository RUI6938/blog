package com.itheima.apidemo;

import java.util.Scanner;

public class ScannerDemo1 {
    //需求：按照帮助文档的使用步骤学习Scanner类的使用，并实现接受键盘录入的一个小数，最后输出在控制台
    public static void main(String[] args) {
        //1.创建对象
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个小数:");
        //2.接受一个小数
        double result = sc.nextDouble();
        //3.输出打印
        System.out.println(result);
    }
}
