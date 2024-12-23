#ifndef STORAGE_BOOKDATA_HPP
#define STORAGE_BOOKDATA_HPP

#include<string>

class BookData {
public:
    BookData() { valid = 0; };

    std::string getisbn() { return isbn; };

    std::string getbookTitle() { return bookTitle; };

    int getvalid() { return valid; };

    double getretail() { return retail; }

    int getqtyOnHand() { return qtyOnHand; };

    void setisbn(std::string &ISBN) { isbn = ISBN; };

    void setbookTitle(std::string &Booktitle) { bookTitle = Booktitle; };

    void setqtyOnHand(int QtyOnHand) { qtyOnHand = QtyOnHand; };

    void setretail(double Retail) { retail = Retail; };

    void setvalid(int Valid) { valid = Valid; };

    void Bookdecrease(int number);

    std::string toString() const;

    void fromString(std::string &line);

    void BookInfo();

    void Bookdelete();

private:
    std::string isbn;
    std::string bookTitle;
    int qtyOnHand;
    double retail;
    int valid;
};

#endif //STORAGE_BOOKDATA_HPP
