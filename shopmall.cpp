#include "shopmall.h"
#include "book.h"
#include "shopcart.h"
#include "gadget.h"
#include "stationery.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
Book b;
Gadget g;
Stationery s;

ShopMall::ShopMall()
{
    n = 1;
}
void ShopMall::chooseUser()
{

    cout<<"Enter 1 for ADMIN 2 for CUSTOMER ";
    cin>>n;
    if(n==1)
        admin();
    else if(n==2)
        customer();

}

void ShopMall::Welcome()
{
    cout<<"                         WELCOME TO PVR MALL : SHOP AND ADD TO YOUR CART                                \n";
}
void ShopMall::customer()
{
    int k;
    c:
        ShopCart cart;
        int flag2=1;
        cout<<"\nTo enter products of Books enter B,Gadgets enter G,Stationery enter S "<<endl;
        cin>>ch2;
        while(flag2==1)
        {
            switch(ch2)
            {
                case 'B': b.purchaseBook();
                          flag2=0;
                        cout<<"\n1.CONTINUE AS CUSTOMER\n2.OTHER USER\n3.DISPLAY CART\n4.EXIT  ";
                        cin>>k;
                        if(k==1)
                        {
                            goto c;
                        }
                        else if(k==2)
                        {
                            chooseUser();
                        }
                        else if(k==3)
                        {
                            int s;
                            cart.readCart();
                            cout<<"\n1.CONTINUE SHOPPING\n2.MODIFY CART\n3.END SHOPPING\n";
                            cin>>s;
                            if(s==1)
                                goto c;
                            else if(s==2)
                                cart.modifyCart();
                            else if(s==3)
                                exit(0);
                        }
                        else if(k==4)
                        {
                            exit(0);
                        }
                            break;
                case 'S':s.purchaseStationery();
                        flag2=0;
                        cout<<"\n1.CONTINUE AS CUSTOMER\n2.OTHER USER\n3.DISPLAY CART\n4.EXIT  ";
                        cin>>k;
                        if(k==1)
                        {
                            goto c;
                        }
                        else if(k==2)
                        {
                            chooseUser();
                        }
                         else if(k==3)
                        {
                            int s;
                            cart.readCart();
                            cout<<"\n1.CONTINUE SHOPPING\n2.MODIFY CART\n3.END SHOPPING\n";
                            cin>>s;
                            if(s==1)
                                goto c;
                            else if(s==2)
                                cart.modifyCart();
                            else if(s==3)
                                exit(0);
                        }
                        else if(k==4)
                        {
                            exit(0);
                        }
                        break;
                case 'G':g.purchaseGadget();
                         flag2=0;
                          cout<<"\n1.CONTINUE AS CUSTOMER\n2.OTHER USER\n3.DISPLAY CART\n4.EXIT  ";
                        cin>>k;
                        if(k==1)
                        {
                            goto c;
                        }
                        else if(k==2)
                        {
                            chooseUser();
                        }
                         else if(k==3)
                        {
                            int s;
                            cart.readCart();
                            cout<<"\n1.CONTINUE SHOPPING\n2.MODIFY CART\n3.END SHOPPING\n";
                            cin>>s;
                            if(s==1)
                                goto c;
                            else if(s==2)
                                cart.modifyCart();
                            else if(s==3)
                                exit(0);
                        }
                        else if(k==4)
                        {
                            exit(0);
                        }
                        break;
                default:
                    cout<<"\nWrong choice "<<endl;
                    goto c;
            }
        }
}
void ShopMall::admin()
{
    int n1,n2,n3,k;
    char ch;
    b:
    int flag=1;
    cout<<"\nTo enter products of Books enter B,Gadgets enter G,Stationery enter S "<<endl;
    cin>>ch;
    while(flag==1)
    {
    switch(ch)
    {
        case 'B':
                cout<<"Enter the number of books to be inserted ";
                cin>>n1;
                b.writeBook(n1);
                flag=0;
                cout<<"\n\n ENTERED DETAILS : \n";
                b.readBook();
                cout<<"\n1.CONTINUE AS ADMIN\n2.OTHER USER\n3.EXIT ";
                cin>>k;
                if(k==1)
                {
                    goto b;
                }
                else if(k==2)
                {
                    chooseUser();
                }
                else if(k==3)
                {
                   exit(0);
                }

                break;
        case 'G':
                cout<<"\nEnter the number of gadgets to be inserted ";
                cin>>n2;
                g.writeGadget(n2);
                flag=0;
                cout<<"\n\n ENTERED DETAILS : \n";
                g.readGadget();
                cout<<"\n1.CONTINUE AS ADMIN\n2.OTHER USER\n3.EXIT";
                cin>>k;
                if(k==1)
                {
                    goto b;
                }
                else if(k==2)
                {
                    chooseUser();
                }
                else if(k==3)
                {
                    exit(0);
                }

                break;

        case 'S':
                cout<<"\nEnter the number of stationery items to be inserted ";
                cin>>n3;
                s.writeStationery(n3);
                flag=0;
                cout<<"\n\n ENTERED DETAILS : \n";
                s.readStationery();
                cout<<"\n1.CONTINUE AS ADMIN\n2.OTHER USER\n3.EXIT";
                cin>>k;
                if(k==1)
                {
                    goto b;
                }
                else if(k==2)
                {
                    chooseUser();
                }
                else if(k==3)
                {
                    exit(0);
                }

                break;

            default: cout<<"\nWrong Choice... ";
                    goto b;
                    break;
            }

        }
}
