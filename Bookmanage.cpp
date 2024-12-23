#include<iostream>
#include "BookData.hpp"
#include "Book1000.hpp"
#include "main menu.hpp"

using namespace std;

void lookupBook();

void deleteBook();

void addBook();

void editBook();

int searchBook();

void setBook(int count);

void BookManage() {
    cout << endl;

    //打印管理模块
    cout << "XXX图书管理系统" << endl;
    cout << "书库管理模块" << endl;
    cout << "" << endl;
    cout << "1.查找某本书的信息" << endl;
    cout << "2.增加书" << endl;
    cout << "3.修改书的信息" << endl;
    cout << "4.删除书" << endl;
    cout << "5.返回到主菜单" << endl;
    cout << "" << endl;
    cout << "输入选择：" << endl;

    int isprime = 1;//循环判断变量
    do {
        int swtich_case;
        cin >> swtich_case;
        switch (swtich_case) {//根据输入进入模块
            case 1:
                lookupBook();
                isprime = 0;
                break;
            case 2:
                addBook();
                isprime = 0;
                break;
            case 3:
                editBook();
                isprime = 0;
                break;
            case 4:
                deleteBook();
                isprime = 0;
            case 5:
                Mainmenu();
                isprime = 0;
                break;
            default:
                cout << "错误！请重新输入" << endl;
        }
    } while (isprime);//若错误则再次输入
}


void lookupBook() {//查找书籍并显示
    cout << endl;
    cout << endl;

    int count = searchBook();
    Book[count].BookInfo();
    BookManage();
}

void deleteBook() {//查找书籍并删除
    cout << endl;
    cout << endl;

    int count = searchBook();
    Book[count].Bookdelete();
    cout << " 已被删除" << endl;
    BookManage();
}

void addBook() {//添加书籍
    int count = 0;
    for (count = 0; count < 1000; ++count) {
        if (Book[count].getvalid() == 0) {
            break;
        }
    }

    cout << "请输入新的书籍的信息" << endl;
    setBook(count);

    cout << "添加成功" << endl;
    BookManage();
}

void editBook() {//编辑书籍信息
    cout << endl;
    cout << endl;

    int count = searchBook();
    Book[count].BookInfo();

    cout << "请输入新的书籍信息" << endl;
    setBook(count);
    cout << "修改成功" << endl;
    BookManage();
}

int searchBook() {//通过字符串匹配查找书籍
    cout << endl;
    cout << endl;

    int isprime = 1;
    while (isprime) {
        cout << "请输入书名：" << std::endl;
        string name;
        cin >> name;

        int count = 0;
        for (count = 0; count < 1000; ++count) {
            if (Book[count].getbookTitle() == name && Book[count].getvalid()) {//查找书籍是否存在
                return count;
            }
        }
        if (count == 1000) {
            cout << "未找到" << endl;
            cout << "是否再次输入一个ISBN号（1是/0否）" << endl;
            int go_on;
            cin >> go_on;
            if (go_on == 0) {
                isprime = 0;
            }
        }
    }
    BookManage();
}

void setBook(int count) {//设置书籍信息
    cout << endl;
    cout << endl;

    cout << "ISBN号:   ";
    string ISBN;
    cin >> ISBN;
    cout << "书名:   ";
    string Booktitle;
    cin >> Booktitle;
    cout << "库存量:   ";
    int QtyOnHand;
    cin >> QtyOnHand;
    cout << "零售价:   ";
    double Retail;
    cin >> Retail;

    Book[count].setisbn(ISBN);
    Book[count].setbookTitle(Booktitle);
    Book[count].setqtyOnHand(QtyOnHand);
    Book[count].setretail(Retail);
    Book[count].setvalid(1);
}

