#ifndef STORAGE_BOOK1000_HPP
#define STORAGE_BOOK1000_HPP

#include "BookData.hpp"

extern BookData Book[1000];//定义全局变量对象
extern double sales;

void savetofile();

int loadfromfie();
#endif //STORAGE_BOOK1000_HPP
