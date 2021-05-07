#include "stationery.h"
#include "shopcart.h"
#include<iostream>
using namespace std;
#include<fstream>
Stationery::Stationery()
{
    stationeryId = 0;
    itemName[15]='\0';
    brand[15]='\0';
    number = 0;
    price  = 0;
}
void Stationery::putStationery()
{
    cout<<"Enter the stationary id: ";
    cin>>stationeryId;
    cout<<"\nEnter the item name: ";
    cin>>itemName;
    cout<<"\nEnter the item brand: ";
    cin>>brand;
    cout<<"\nEnter the stock ";
    cin>>number;
    cout<<"\nEnter the price ";
    cin>>price;

}

void Stationery::getStationery()
{
        cout<<"STATIONERY ID : "<<stationeryId<<"\nITEM NAME :"<<itemName<<"\nBRAND :"<<brand<<"\nSTOCK "<<number<<"\nPRICE :"<<price<<endl;
}
void Stationery::writeStationery(int n)
{
    fstream fout;
    Stationery st;
    fout.open("C:\\codeblocksprograms\\STATIONERY.txt",ios::out|ios::app);
    for (int i =0;i<n;i++)
    {
        st.putStationery();
        fout.write((char *)&st,sizeof(st));
    }
    fout.close();

}
void Stationery::readStationery()
{
    Stationery s;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\STATIONERY.txt",ios::in);
    while(true)
    {
        fin.read((char *)&s,sizeof(s));
        if(fin.eof())
            break;
        else
            s.getStationery();

    }
    fin.close();
}
void Stationery::modifyStationery(int statId,int stationeryQty)
{
   /* Stationery s1;
    int bytesread=0;
    int x;
    ShopCart c;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\STATIONERY.txt",ios::in|ios::out);
    while(!fin.eof())
    {

        fin.read((char *)&s1,sizeof(s1));
        x=sizeof(s1);
        cout<<"\n x value "<<x<<endl;
        if(s1.stationeryId==statId)
        {
            c.writeInCart(s1.itemName,s1.price,stationeryQty);

            cout<<"\n inside if "<<endl;
            s1.number -= stationeryQty;
            cout<<"\n stock changed ";

            fin.seekg(bytesread,ios::beg);
            cout<<"\nafter seekg"<<endl;
            fin.write((char *)&s1,sizeof(s1));
            break;
        }
        bytesread+=x;

    }
     //c.readCart();
    fin.close();
    cout<<" AFTER MODIFYING \n";
    s1.readStationery();*/

    Stationery s1; int bytesread=0; int x;
    fstream fin;
    ShopCart s;
    fin.open("C:\\codeblocksprograms\\STATIONERY.txt",ios::in|ios::out);
    while(!fin.eof())
    {

        fin.read((char *)&s1,sizeof(s1));
        x=sizeof(s1);
        //cout<<"\n x value "<<x<<endl;
        if(s1.stationeryId==statId)
        {
            s.writeInCart(s1.itemName,s1.price,stationeryQty);
          //  cout<<"\n inside if "<<endl;
            s1.number -= stationeryQty;
            //cout<<"\n stock changed ";

            fin.seekg(bytesread,ios::beg);
            //cout<<"\nafter seekg"<<endl;
            fin.write((char *)&s1,sizeof(s1));
            break;
        }
        bytesread+=x;

    }
    fin.close();
   // cout<<" AFTER MODIFYING \n";
    readStationery();
}

void Stationery::purchaseStationery()
{
    readStationery();
    int buyNo,buyQty;
    Stationery s;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\STATIONERY.txt",ios::in);
    int flag=0;
    while(flag==0)
    {
        cout<<"\nEnter the Stationery id to purchase ";
        cin>>buyNo;
        while(true)
        {
            fin.read((char *)&s,sizeof(s));
            if(fin.eof())
                break;
            else
            {
                if(s.stationeryId==buyNo)
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
            fin.read((char *)&s,sizeof(s));
            if(s.stationeryId==buyNo)
            {
                if(buyQty>s.number)
                {
                    goto A;
                }
            }

        }

        fin.close();
        modifyStationery(buyNo,buyQty);
}
