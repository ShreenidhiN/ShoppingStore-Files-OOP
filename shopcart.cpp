#include "shopcart.h"
#include "book.h"
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
static int no = 0;
float GrandTotal = 0.0;
ShopCart::ShopCart()
{
    sno=0;
    itemName[20]='\0';
    quantity=0;
    unitPrice=0;
    subtotal=0;
}

void ShopCart::getRecords(char n[],int u, int q)
{
    no = no+1;
    sno = no;
    strcpy(itemName,n);
    quantity=q;
    unitPrice=u;
    subtotal=unitPrice*quantity;
    GrandTotal+=subtotal;
}

void ShopCart::displayGrandTotal()
{
    cout<<"\nGRAND TOTAL OF YOUR CART "<<GrandTotal<<endl;

}
void ShopCart::writeInCart(char n[], int u, int q)
{
    ShopCart c;
    fstream cart;
    cart.open("C:\\codeblocksprograms\\CART.txt",ios::out|ios::app);
    c.getRecords(n,u,q);
    cart.write((char*)&c,sizeof(c));
    cart.close();
}

void ShopCart::putRecords()
{
    cout<<"\nS.NO: "<<sno<<"\nITEM NAME: "<<itemName<<"\nUNITPRICE: "<<unitPrice<<"\nQUANTITY: "<<quantity<<"\nSUBTOTAL: "<<subtotal;
}

void ShopCart::readCart()
{
    //reading line by line using object in the file
    ShopCart c1;
    fstream fin;

    cout<<"\n YOUR CART HAS :\n\n  ";

    fin.open("C:\\codeblocksprograms\\CART.txt",ios::in);
    while(true)
    {
         fin.read((char *)&c1,sizeof(c1));
        if(fin.eof())
        {
            break;
        }
        else
        {
            c1.putRecords();
        }

    }
    displayGrandTotal();
    fin.close();
}
void ShopCart::modifyCart()
{
    ShopCart sc;
    int p;
    cout<<"\nEnter the product number to delete a product from cart ";
    cin>>p;
    fstream f1,f2;
    f1.open("C:\\codeblocksprograms\\CART.txt",ios::in);
    f2.open("C:\\codeblocksprograms\\temp.txt",ios::out);
    //to modify cart , delete a product
    while(true)
    {
        f1.read((char *)&sc,sizeof(sc));
        if(f1.eof())
            break;
        else
        {

            if(sc.sno!=p)
            {
                f2.write((char *)&sc,sizeof(sc));

            }
        }
    }
    f1.close();
    remove("C:\\codeblocksprograms\\CART.txt");
    //rename("C:\\codeblocksprograms\\temp.txt","C:\\codeblocksprograms\\CART.txt");
    f2.close();

    cout<<"\nNOW NEW CART... "<<endl;
    readNewCart();
}
void ShopCart::readNewCart()
{
    ShopCart c1;
    fstream fin;

    cout<<"\n YOUR CART HAS :\n\n  ";
    // read new cart after modifying
    fin.open("C:\\codeblocksprograms\\temp.txt",ios::in);
    while(true)
    {
         fin.read((char *)&c1,sizeof(c1));
        if(fin.eof())
        {
            break;
        }
        else
        {
            c1.putRecords();
        }

    }

    fin.close();
}

