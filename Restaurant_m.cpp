#include "Restaurant.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include<cstdio>

using namespace std;

Restaurant::Restaurant()
{
    headc= NULL;
    tailc = NULL;
    heada = NULL;
    taila= NULL;
    head_s = NULL;
}

void Restaurant::adminmenu()
{
    cout<<endl;
    cout<<"     1. View Total Deals of the Restaurant"<<endl;
    cout<<"     2. Add new items in the order menu"<<endl;
    cout<<"     3. Delete items from the order menu"<<endl;
    cout<<"     4. Display the order menu"<<endl;
    cout<<"     5. Back to main menu"<<endl<<endl;
    cout<<"        Enter your choice : ";
}

void Restaurant::customermenu()
{
    cout<<endl;
    cout<<"     1. Place your order"<<endl;
    cout<<"     2. View your ordered items"<<endl;
    cout<<"     3. Delete an item from the order"<<endl;
    cout<<"     4. Display final bill"<<endl;
    cout<<"     5. Back to main menu"<<endl<<endl;
    cout<<"        Enter your choice : ";
}

void Restaurant::adminList( int index, char foodName[50], float price)
{
    newnode = new node;

    newnode->index = index;
    newnode->price = price;
    newnode->quantity = 0;
    strcpy(newnode->foodName,foodName);
    newnode->next = NULL;

    struct node * temp = heada;

    if(temp==NULL)
    {
        heada = taila = newnode;
    }
    else
    {
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        taila = newnode;
    }

};

struct node* Restaurant::customerList(struct node *headc, int index, int quantity)
{
    newnode = new node;

    struct node * temp1 = heada;
    int flag = 0;
    while(temp1 != NULL)
    {
        if(temp1->index == index)
        {
            flag = 1;
            break;
        }

        temp1 = temp1->next;
    }

    if(flag == 1)
    {
        newnode->index = index;
        newnode->price = quantity*(temp1->price);
        newnode->quantity = quantity;
        strcpy(newnode->foodName, temp1->foodName);
        newnode->next = NULL;

        struct node * temp = headc;

        if(temp==NULL)
        headc = tailc = newnode;
        else
        {
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            tailc = newnode;
        }
    }
    else
    {
        cout<<endl<<"     This item is not present in the menu!"<<endl;
    }

    return headc;
};

void Restaurant::displayList(struct node *head)
{
    struct node * temp1 = head;

    if(temp1 == NULL)
        cout<<endl<<"     List is Empty!!"<<endl<<endl;
    else
    {
        cout<<endl;

        while(temp1 != NULL)
        {
            if(temp1->quantity == 0)
                cout<<"     "<<temp1->index<<"  "<<temp1->foodName<<"  "<<temp1->price<<endl;
            else
                cout<<"     "<<temp1->index<<"  "<<temp1->foodName<<"  "<<temp1->quantity<<"  "<<temp1->price<<endl;

            temp1 = temp1->next;
        }

        cout<<endl;
    }
}

struct node* Restaurant::totaldeals(int index, int quantity)
{
    newnode = new node;

    int flag = 0;

    struct node * temp1 = heada;

    while(temp1->index != index)
    {
        temp1 = temp1->next;
    }

    newnode->index = index;
    newnode->price = quantity*(temp1->price);
    newnode->quantity = quantity;
    strcpy(newnode->foodName, temp1->foodName);
    newnode->next = NULL;

    struct node *temp = head_s;

    if(temp==NULL)
        head_s = newnode;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->index==index)
            {
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1)
        {
            temp->quantity += newnode-> quantity;
            temp->price += newnode->price;
        }
        else
        {
            temp->next=newnode;
        }
    }

    return head_s;
}

void Restaurant::cal_tot_deals()
{
    struct node * temp = headc;

    while(temp != NULL)
    {
        head_s = totaldeals(temp->index, temp->quantity);
        temp = temp->next;
    }
}

struct node * Restaurant::Delete(int index, struct node * head, struct node * tail)
{
    if(head == NULL)
        cout<<endl<<"     List is Empty"<<endl;
    else
    {
        struct node * temp;

        if(index == head->index)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }
        else if(index == tail->index)
        {
            temp = tail;
            tail->next = NULL;
            delete(temp);
        }
        else
        {
            temp = head;
            struct node * temp1 = temp;

            while(index != temp->index)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
            delete(temp);
        }
    }

    return head;
};

int Restaurant::delete_admin()
{
    cout<<endl<<"     Enter serial no. of the food item which is to be deleted: ";
    int num;
    cin>>num;

    struct node * temp = heada;

    while(temp != NULL)
    {
        if(temp->index == num)
        {
            heada = Delete(num, heada, taila);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

int Restaurant::delete_customer()
{
    cout<<endl<<"    Enter serial no. of the food item which is to be deleted : ";
    int num;
    cin>>num;

    struct node * temp = headc;
    while(temp != NULL)
    {
        if(temp->index == num)
        {
            headc = Delete(num, headc, tailc);
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

void Restaurant::display_bill()
{
    displayList(headc);
    struct node *temp = headc;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price += (temp->price);
        temp = temp->next;
    }

    cout<<"          Total price: "<<total_price<<endl;
}

struct node * Restaurant::deleteList(struct node * head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node*n, *temp = head;
        while(temp!= NULL)
        {
            n = temp->next;
            free(temp);
            temp = n;
        }
        head = NULL;
    }

    return head;
};

void Restaurant::admin()
{
    cout<<endl<<"     ---------------------------------"<<endl;
    cout<<"              ADMIN DEPARTMENT"<<endl;
    cout<<"     ---------------------------------"<<endl;

    while(1){
    adminmenu();

    int option;
    cin>>option;

    if(option == 5)
        break;

    switch(option)
    {
    case 1:
        displayList(head_s);
        break;
    case 2:
        {
        cout<<endl<<"     Enter serial no. of the food item : ";
        int num, flag =0;
        char name[50];
        float price;
        cin>>num;
         struct node * temp = heada;
          while(temp != NULL)
          {
              if(temp->index == NULL)
              {
                  cout<<endl<<"     Food item already exists"<<endl<<endl;
                  flag = 1;
                  break;
              }
              temp = temp->next;
          }

          if(flag == 1)
            break;

          cout<<"     Enter food item: ";
          cin>>name;

          cout<<"     Enter price: ";
          cin>>price;

          adminList(num, name, price);

          cout<<endl<<"     Food item add to the list"<<endl<<endl;
          break;
        }
    case 3:
        if(delete_admin())
        {
            cout<<endl<<"     Updated List"<<endl;
            displayList(heada);
        }
        else
           cout<<endl<<"     Food item does not exist "<<endl<<endl;
          break;

    case 4:
        cout<<endl<<"     order menu"<<endl;
        displayList(heada);
        break;

    default:
        cout<<endl<<"     Wrong input"<<endl;
    }
    }
}

void Restaurant::customer()
{
    int flag = 0, j =1;
    char ch;

    cout<<endl<<"     ----------------------------------"<<endl;
    cout<<"             CUSTOMER DEPARTMENT"<<endl;
    cout<<"     ----------------------------------"<<endl;

    while(1){
    customermenu();

    int option;
    cin>>option;

    if(option == 5)
        break;

    switch(option)
    {
    case 1:
        displayList(heada);
        cout<<endl<<"     Enter serial no. of food item, you want to order : ";
        int n;
        cin>>n;

        int quantity;
        cout<<"     Enter quantity: ";
        cin>>quantity;

        headc = customerList(headc, n, quantity);
        break;

    case 2:
        cout<<endl<<"     List of ordered food items"<<endl;
        displayList(headc);
        break;

    case 3:
        if(delete_customer())
        {
            cout<<endl<<"     Updated List"<<endl;
            displayList(headc);
        }
        else
           cout<<endl<<"     Food item does not exist "<<endl<<endl;
          break;

    case 4:
        cal_tot_deals();
        cout<<endl<<"     Final Bill"<<endl;
        display_bill();
        headc = deleteList(headc);
        cout<<endl<<"     Press any key to return to main menu: "<<endl<<"     ";
        fflush(stdin);
        ch = fgetc(stdin);
        flag = 1;
        break;

    default:
        cout<<endl<<"     Wrong input"<<endl;
    }

    if(flag == 1)
        break;
    }
}

void Restaurant::MainMenu()
{
    cout<<endl<<"     ------------------------------------------------"<<endl;
    cout<<"         WELCOME TO THE FINE DINE RESTAURANT"<<endl;
    cout<<"     ------------------------------------------------"<<endl<<endl<<endl;

    cout<<"     1. ADMIN DEPARTMENT "<<endl;
    cout<<"     2. CUSTOMER DEPARTMENT"<<endl;
    cout<<"     3. EXIT"<<endl<<endl;
    cout<<"     Enter your choice : ";
}
