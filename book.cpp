#include "book.h"
#include<iostream>
using namespace std;
#include<fstream>
#include "shopcart.h"
void readOrder();
void addToCart(int,char);
Book::Book()
{
    name[10]='\0';
    genre[10]='\0';
    author[10]='\0';
    id = 0;
    stock = 0;
    price = 0;

}
void Book::putBooks()
{
    cout<<"Enter the book id ";
    cin>>id;
    cout<<"\nEnter the book name ";
    cin>>name;
    cout<<"\nEnter the author ";
    cin>>author;
    cout<<"\nEnter the genre ";
    cin>>genre;
    cout<<"\nEnter the stock ";
    cin>>stock;
    cout<<"\nEnter the price ";
    cin>>price;


}

void Book::getBooks()
{
    cout<<"BOOK ID : "<<id<<"\nBOOK NAME :"<<name<<"\nAUTHOR :"<<author<<"\nGENRE "<<genre<<"\nSTOCK :"<<stock<<"\nPRICE :"<<price<<endl;
}

void Book::writeBook(int n)
{
    fstream fout;
    Book b;
    fout.open("C:\\codeblocksprograms\\BOOK.txt",ios::out|ios::app);
    for(int i=0;i<n;i++)
    {
        b.putBooks();
        fout.write((char *)&b,sizeof(b));

    }
    fout.close();
}
void Book::readBook()
{
    Book b1;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\BOOK.txt",ios::in);
    while(true)
    {
      fin.read((char *)&b1,sizeof(b1));
      if(fin.eof())
        break;
      else
        b1.getBooks();
    }
    fin.close();

}
void Book::modifyBook(int bookId,int bookQty)
{
    Book b1; int bytesread=0; int x;
    fstream fin;
    ShopCart s;
    fin.open("C:\\codeblocksprograms\\BOOK.txt",ios::in|ios::out);
    while(!fin.eof())
    {

        fin.read((char *)&b1,sizeof(b1));
        //x store the size of an object so that it can be used for re writing on file
        x=sizeof(b1);

        if(b1.id==bookId)
        {
            //writing on cart
            s.writeInCart(b1.name,b1.price,bookQty);
            //reduce qnty in stock of the shop
            b1.stock -= bookQty;
            fin.seekg(bytesread,ios::beg);
            //re writing the modified qty
            fin.write((char *)&b1,sizeof(b1));
            break;
        }
        bytesread+=x;

    }
    fin.close();

   // readBook();
}
void Book::purchaseBook()
{
    readBook();
    int buyNo,buyQty;
    Book b1;
    fstream fin;
    fin.open("C:\\codeblocksprograms\\BOOK.txt",ios::in);
    int flag = 0;
    while(flag==0)
    {
        cout<<"\nEnter the book id to purchase ";
        cin>>buyNo;
        //check if the entered id is correct
        while(true)
        {
            fin.read((char *)&b1,sizeof(b1));
            if(fin.eof())
                break;
            else
            {
                if(b1.id==buyNo)
                {
                    flag = 1;
                    break;
                }
            }
        }
        fin.seekg(0);
    }

    // check if the required qty is > or<= the available stock

    fin.seekg(0);
        A:
        cout<<"\nEnter the quantity required ";
        cin>>buyQty;
        while(!fin.eof())
        {
            fin.read((char *)&b1,sizeof(b1));
            if(b1.id==buyNo)
            {
                if(buyQty>b1.stock)
                {
                    goto A;
                }
            }

        }
    fin.close();
    modifyBook(buyNo,buyQty);

}

