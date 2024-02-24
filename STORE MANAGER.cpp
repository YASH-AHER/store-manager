#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

class Item
{
public:
        string name;
        double price;
        int quantity;

        Item() {} // Default constructor

        Item(string name, double price, int quantity)
        {
                this->name = name;
                this->price = price;
                this->quantity = quantity;
        }
};

int main()
{
        Item inventory[MAX_ITEMS];
        int itemCount = 0;

        stack<Item *> sales;
        queue<Item *> restockingRequests;

        int choice;
        do
        {
                cout << "1. Add item to inventory\n";
                cout << "2. Make sale\n";
                cout << "3. Request restocking\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                {
                        if (itemCount < MAX_ITEMS)
                        {
                                string name;
                                double price;
                                int quantity;

                                cout << "Enter item name: ";
                                cin >> name;
                                cout << "Enter item price: ";
                                cin >> price;
                                cout << "Enter item quantity: ";
                                cin >> quantity;

                                inventory[itemCount] = Item(name, price, quantity);
                                itemCount++;
                        }
                        else
                        {
                                cout << "Inventory is full!\n";
                        }
                        break;
                }
                case 2:
                {
                        if (itemCount > 0)
                        {
                                Item &item = inventory[itemCount - 1];
                                if (item.quantity > 0)
                                {
                                        sales.push(&item);
                                        item.quantity--;
                                        cout << "Sale made!\n";
                                }
                                else
                                {
                                        cout << "Item out of stock!\n";
                                }
                        }
                        else
                        {
                                cout << "Inventory is empty!\n";
                        }
                        break;
                }
                case 3:
                {
                        if (itemCount > 0)
                        {
                                restockingRequests.push(&inventory[itemCount - 1]);
                                cout << "Restocking requested!\n";
                        }
                        else
                        {
                                cout << "Inventory is empty!\n";
                        }
                        break;
                }
                case 4:
                        cout << "Exiting...\n";
                        break;
                default:
                        cout << "Invalid choice. Please try again.\n";
                }
        } while (choice != 4);

        return 0;
}