#ifndef SHOPCART_H
#define SHOPCART_H
#include "book.h"
#include "ShopMall.h"
#include<iostream>
using namespace std;

class ShopCart
{

    public :
        ShopCart();
        void getRecords(char [],int, int);
        void writeInCart(char [],int, int);
        void readCart();
        void putRecords();
        void modifyCart();
        void readNewCart();
        void displayGrandTotal();
    private:

        int sno;
        char itemName[20];
        int quantity;
        int unitPrice;
        int subtotal;
};

#endif // SHOPCART_H




