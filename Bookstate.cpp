#include "main menu.hpp"
#include "Book1000.hpp"
#include<iostream>

void bookList();

void retailList();

using namespace std;

void bookState() {//报表模块
    cout << "XXX图书管理系统" << endl;
    cout << "报表模块" << endl;
    cout << "1.书库列表" << endl;
    cout << "2.零售价列表" << endl;
    cout << "3.返回到主菜单" << endl;

    int isprime = 1;//循环判断变量
    do {
        cout << "输入选择：" << endl;
        int swtich_case;
        cin >> swtich_case;
        switch (swtich_case) {
            case 1:
                bookList();
                isprime = 0;
                break;
            case 2:;
                retailList();
                isprime = 0;
                break;
            case 3:
                Mainmenu();
                isprime = 0;
                break;
            default:
                cout << "错误！请重新输入" << endl;
        }
    } while (isprime);
}

void bookList() {//书籍列表
    int count = 0;
    while (Book[count].getvalid()) {
        Book[count].BookInfo();
        cout << endl;
        count++;
    }
    bookState();
}

void retailList() {//零售额列表
    cout << "销售额：" << sales << endl;
    cout << "销售税：" << sales * 0.06 << endl;

    int count = 0;
    while (Book[count].getvalid()) {
        Book[count].BookInfo();
        cout << Book[count].getqtyOnHand() * Book[count].getretail() << endl;
        cout << endl;
        count++;
    }
    bookState();
}