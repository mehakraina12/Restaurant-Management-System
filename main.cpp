#include <iostream>
#include "Restaurant.h"
#include <stdlib.h>

using namespace std;

int main()
{
    Restaurant obj;

     obj.adminList(1,"  Cheesy Margherita Pizza : ",199);
     obj.adminList(2,"  Lemon Ice Tea           : ",150);
     obj.adminList(3,"  Choco Fudge             : ",189);
     obj.adminList(4,"  Super Veggie Burger     : ",250);
     obj.adminList(5,"  Peri Peri Cheesy Fries  : ",350);
     obj.adminList(6,"  Kitkat Shake            : ",189);
     obj.adminList(7,"  Sizzling Brownie        : ",311);
     obj.adminList(8,"  Chocolate Cappuccino    : ",335);
     obj.adminList(9,"  Nutella Shake           : ",159);
     obj.adminList(10," Waffles                 : ",179);

    while(1)
    {
       obj.MainMenu();
       int choice;
       cin>>choice;

       if(choice == 3)
       {
           cout<<endl<<"     Thank You for your order"<<endl;
           break;
       }

       switch(choice)
       {
       case 1:
        obj.admin();
        break;

       case 2:
        obj.customer();
        break;

       case 3:
        break;

       default:
        cout<<endl<<"     Wrong input"<<endl;
       }
    }
    return 0;
}