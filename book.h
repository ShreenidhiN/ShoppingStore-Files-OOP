#ifndef BOOK_H
#define BOOK_H
#include<iostream>
using namespace std;
#include<fstream>


class Book
{
    public:
        Book();
        void putBooks();
        void getBooks();
        void modifyBook(int,int);
        void purchaseBook();
        void order(int);
        void readBook();
        void writeBook(int);

    protected:
                char name[10];
                char genre[10];
                char author[10];
                int id;
                int stock;
                float price;
};
#endif // BOOK_H
