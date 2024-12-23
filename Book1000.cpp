#include "Book1000.hpp"
#include<istream>
#include<iostream>
#include <fstream>

BookData Book[1000];//定义全局变量对象数组
double sales = 0;//销售总额

std::string filename = "Data.txt";

void savetofile() {//保存到文件
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);//输出重定向

    if (!outfile.is_open()) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < 1000; ++i) {//将各组成员变量以字符串形式写入文件
        outfile << Book[i].toString() << std::endl;
    }

    outfile.close();
}

int loadfromfie() {//从文件读入
    std::ifstream inFile(filename);//输入重定向

    int count = 0;//书籍种类数
    std::string line;

    while (std::getline(inFile, line)) {//将各行字符串解析
        Book[count].fromString(line);
        ++count;
    }

    inFile.close();
    return count;
}



