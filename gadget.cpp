#include "gadget.h"
#include<iostream>
using namespace std;
#include<fstream>
#include "shopcart.h"
Gadget::Gadget()
{
   pid = 0;
   cat[10]='\0';
   item[10]='\0';
   qty = 0;
   cost = 0;
}
void Gadget::putGadgets()
{
    cout<<"Enter the gadget id ";
    cin>>pid;
    cout<<"\nEnter the gadget category ";
    cin>>cat;
    cout<<"\nEnter the item name with model ";
    cin>>item;
    cout<<"\nEnter the stock ";
    cin>>qty;
    cout<<"\nEnter the price ";
    cin>>cost;

}
void Gadget::getGadgets()
{
        cout<<"GADGET ID : "<<pid<<"\nGADGET CATEGORY :"<<cat<<"\nNAME :"<<item<<"\nSTOCK "<<qty<<"\nPRICE :"<<cost<<endl;
}
void Gadget::writeGadget(int n)
{
    fstream fout;
    Gadget g;
    fout.open("C:\\codeblocksprograms\\GADGET.txt",ios::out|ios::app);

    for(int i=0;i<n;i++)
    {
        g.putGadgets();
        fout.write((char *)&g,sizeof(g));
    }
    fout.close();
}
void Gadget::readGadget()
{
    Gadget g;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\GADGET.txt",ios::in);
    while(true)
    {
        fin.read((char *)&g,sizeof(g));
        if(fin.eof())
            break;
        else
            g.getGadgets();

    }
    fin.close();

}
void Gadget::modifyGadget(int gadgetId,int gadgetQty)
{
    Gadget g1; int bytesread=0; int x;
    ShopCart c;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\GADGET.txt",ios::in|ios::out);
    while(!fin.eof())
    {

        fin.read((char *)&g1,sizeof(g1));
        x=sizeof(g1);

        if(g1.pid==gadgetId)
        {
            c.writeInCart(g1.item,g1.cost,gadgetQty);
            g1.qty -= gadgetQty;
            fin.seekg(bytesread,ios::beg);
            fin.write((char *)&g1,sizeof(g1));
            break;
        }
        bytesread+=x;

    }
    fin.close();

}

void Gadget::purchaseGadget()
{
    readGadget();
    int buyNo,buyQty;
    Gadget g;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\GADGET.txt",ios::in);
    int flag=0;
    while(flag==0)
    {
        cout<<"\nEnter the Gadget id to purchase ";
        cin>>buyNo;
        // id check
        while(true)
        {
            fin.read((char *)&g,sizeof(g));
            if(fin.eof())
                break;
            else
            {
                if(g.pid==buyNo)
                {
                    flag = 1;
                    break;
                }
            }
        }
        fin.seekg(0);
    }

    // qty check

    fin.seekg(0);
        A:
        cout<<"\nEnter the quantity required ";
        cin>>buyQty;
        while(!fin.eof())
        {
            fin.read((char *)&g,sizeof(g));
            if(g.pid==buyNo)
            {
                if(buyQty>g.qty)
                {
                    goto A;
                }
            }

        }

        fin.close();
        modifyGadget(buyNo,buyQty);
}
