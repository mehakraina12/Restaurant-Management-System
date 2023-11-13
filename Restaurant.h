#ifndef RESTAURANT_H
#define RESTAURANT_H


struct node
{
    char foodName[50];
    int quantity;
    float price;
    int index;
    struct node * next;
};

class Restaurant
{
    struct node *headc, *tailc, *heada, *taila, *newnode, *head_s;

public:
    Restaurant();
    void adminmenu();
    void customermenu();
    void adminList(int index, char foodName[50], float price);
    struct node* customerList(struct node *headc, int index, int quantity);
    void displayList(struct node *head);
    struct node* totaldeals(int index, int quantity);
    void cal_tot_deals();
    struct node * Delete(int index, struct node * head, struct node * tail);
    int delete_admin();
    int delete_customer();
    void display_bill();
    struct node * deleteList(struct node * head);
    void admin();
    void customer();
    void MainMenu();

};

#endif // RESTAURANT_H