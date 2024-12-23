//main.cpp
#include "main menu.hpp"
#include "BookData.hpp"
#include "Book1000.hpp"
#include<windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);//在Windows上正确输出中文

    loadfromfie();//从文件加载

    Mainmenu();

    savetofile();//写入文件保存

    return 0;
}
