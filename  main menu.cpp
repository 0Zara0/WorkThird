#include<iostream>
#include "Cashier.hpp"
#include "Bookmanage.hpp"
#include "Bookstate.hpp"
#include "Book1000.hpp"

using namespace std;

void Mainmenu() {
    //打印主菜单
    cout << "XXX图书管理系统" << endl;
    cout << "主菜单" << endl;
    cout << "" << endl;
    cout << "1.收银模块" << endl;
    cout << "2.书库管理模块" << endl;
    cout << "3.报表模块" << endl;
    cout << "4.退出系统" << endl;
    cout << "" << endl;
    cout << "输入选择：" << endl;
    cout << "请输入1-4之间的数。" << endl;

    int isprime = 1;//循环判断变量
    do {
        int swtich_case;
        cin >> swtich_case;
        switch (swtich_case) {//根据输入进入模块
            case 1:
                cashier();
                isprime = 0;
                break;
            case 2:
                BookManage();
                isprime = 0;
                break;
            case 3:
                bookState();
                isprime = 0;
                break;
            case 4:
                isprime = 0;
                break;
            default:
                cout << "错误！请重新输入" << endl;
        }
    } while (isprime);//若错误则再次输入
}