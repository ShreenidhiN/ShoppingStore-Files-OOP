#ifndef STATIONERY_H
#define STATIONERY_H
#include<iostream>
using namespace std;
#include "shopmall.h"
class Stationery
{
    public:
        Stationery();
        void putStationery();
        void getStationery();
        void readStationery();
        void writeStationery(int);
        void modifyStationery(int statId,int stationeryQty);
        void purchaseStationery();
    protected:

    private:
        int stationeryId;
        char itemName[15];
        char brand[15];
        int number;
        float price;

};

#endif // STATIONERY_H
