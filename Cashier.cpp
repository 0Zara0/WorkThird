//Cashier.cpp
#include "Book1000.hpp"
#include "main menu.hpp"
#include<iostream>
#include<string>

using namespace std;

void cashier() {//收银台
    cout << "      前台销售模块" << endl;
    cout << "日期：2021年12月26日" << endl;

    cout << "数量";
    int munber;
    cin >> munber;
    cout << endl;

    cout << "ISBN号\t";
    std::string isbn;
    cin >> isbn;
    cout << endl;

    int isprime = 1;
    while (isprime) {
        int count = 0;
        for (count = 0; count < 1000; ++count) {
            if (Book[count].getbookTitle() == isbn && Book[count].getvalid()) {//查找书籍是否存在
                if (Book[count].getqtyOnHand() > 0 && Book[count].getqtyOnHand() - munber >= 0) {//确实书籍数量足够
                    cout << "书名\t" << Book[count].getbookTitle() << endl;
                    cout << "单价\t" << Book[count].getretail() << endl;;
                    cout << "金额\t" << munber * Book[count].getretail() << endl;;

                    sales += munber * Book[count].getretail();
                    Book[count].Bookdecrease(munber);

                    cout << "--------------------------------" << endl;
                    cout << "累计销售总额：" << sales << endl;
                    cout << "累计零售税：" << sales * 0.06 << endl;
                    cout << endl;
                    cout << "谢谢光临！" << endl;
                    cout << endl;
                    isprime = 0;
                    break;
                } else if (Book[count].getqtyOnHand() == 0) {
                    cout << "该书已售罄" << endl;
                    cout << "是否再次输入一个ISBN号（1是/0否）" << endl;
                    int go_on;
                    cin >> go_on;
                    if (go_on == 0) {
                        isprime = 0;
                    }
                    break;
                } else {
                    cout << "该书库存不足" << endl;
                    cout << "是否再次输入一个ISBN号（1是/0否）" << endl;
                    int go_on;
                    cin >> go_on;
                    if (go_on == 0) {
                        isprime = 0;
                    }
                    break;
                }
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


    Mainmenu();


}

