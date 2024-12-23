#include<sstream>
#include<iostream>
#include "BookData.hpp"

using namespace std;

std::string BookData::toString() const {//将成员变量转换为字符串
    return isbn + "," + bookTitle + "," + std::to_string(qtyOnHand) + "," + std::to_string(retail) + "," +
           std::to_string(valid);
}

void BookData::fromString(std::string &line) {//将字符串解析
    std::stringstream ss(line);
    string token;

    getline(ss, isbn, ',');
    getline(ss, bookTitle, ',');
    getline(ss, token, ',');
    qtyOnHand = stoi(token);
    std::getline(ss, token, ',');
    retail = stod(token);
    std::getline(ss, token, ',');
    valid = stoi(token);

}

void BookData::BookInfo() {//显示书籍信息
    cout << "ISBN号:" << isbn << endl;
    cout << "书名：" << bookTitle << endl;
    cout << "库存量" << qtyOnHand << endl;
    cout << "零售价" << retail << endl;
}

void BookData::Bookdelete() {//删除书籍
    valid = 0;
}

void BookData::Bookdecrease(int number) {//根据购买减少书籍数量
    qtyOnHand -= number;
}

