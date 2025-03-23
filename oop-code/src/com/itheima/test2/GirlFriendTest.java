package com.itheima.test2;

public class GirlFriendTest {
    public static void main(String[] args) {
        //创建女朋友的对象
        GirlFriend Gf1 = new GirlFriend();
        Gf1.name = "小诗诗";
        Gf1.age = 18;
        Gf1.height = 158.8;
        Gf1.gender = "小可爱";

        System.out.println(Gf1.name);
        System.out.println(Gf1.age);
        System.out.println(Gf1.height);
        System.out.println(Gf1.gender);

        Gf1.coquetry();
        Gf1.sing();

        System.out.println("=======================");
        GirlFriend Gf2 = new GirlFriend();
        Gf2.name = "小涵涵";
        Gf2.age = 19;
        Gf2.height = 170.0;
        Gf2.gender = "小萌宝";

        System.out.println(Gf2.name);
        System.out.println(Gf2.age);
        System.out.println(Gf2.height);
        System.out.println(Gf2.gender);

        Gf2.coquetry();
        Gf2.sing();
    }
}
