#ifndef GADGET_H
#define GADGET_H
#include<iostream>
using namespace std;
#include "shopmall.h"
class Gadget
{
    public:
        Gadget();
        void putGadgets();
        void getGadgets();
        void modifyGadget(int gadgetId,int gadgetQty);
        void purchaseGadget();
        void writeGadget(int);
        void readGadget();
    private:
        int pid;
        char cat[10];
        char item[10];
        int qty;
        float cost;

};


#endif // GADGET_H
