#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int pizzaTypes = 3;
const int pizzaSizes = 3;

int pizzaQuantities[pizzaTypes][pizzaSizes] = {
    {10, 10, 10},
    {10, 10, 10},
    {10, 10, 10}
};

struct Topping {
    string name;
    double cost;
};

const int numToppings = 5;
Topping toppings[numToppings] = {
    {"PEPPERONI", 1.5},
    {"MUSHROOMS", 1.5},
    {"ONIONS", 1.5},
    {"SAUSAGE", 1.5},
    {"OLIVES", 1.5}
};

int main() {
    cout << "WELCOME TO THE PIZZA ORDERING SYSTEM!" << endl;
    char choice;

    do {
        cout << "-------------------------------------" << endl;

        cout << "PIZZA CHOICES:\n" << endl;
        cout << "1 - MARGHERITA ($9.99)" << endl;
        cout << "2 - PEPPERONI ($11.99)" << endl;
        cout << "3 - SUPREME ($14.99)\n" << endl;

        int pizzaChoice;
        do {
            cout << "ENTER PIZZA CHOICE (1/2/3): ";
            cin >> pizzaChoice;
            if (pizzaChoice < 1 || pizzaChoice > 3) {
                cout << "INVALID PIZZA CHOICE. PLEASE ENTER A VALID CHOICE (1/2/3)." << endl;
            }
        } while (pizzaChoice < 1 || pizzaChoice > 3);

        char size;

        int sizeIndex;
        do {
            cout << "SELECT SIZES (S/M/L): ";
            cin >> size;
            switch (size) {
                case 'S':
                case 's':
                    sizeIndex = 0;
                    cout << "SMALL: ";
                    break;
                case 'M':
                case 'm':
                    sizeIndex = 1;
                    cout << "MEDIUM: ";
                    break;
                case 'L':
                case 'l':
                    sizeIndex = 2;
                    cout << "LARGE: ";
                    break;
                default:
                    cout << "INVALID SIZE CHOICE. PLEASE ENTER A VALID CHOICE (S/M/L)." << endl;
                    sizeIndex = -1;
                    break;
            }
        } while (sizeIndex == -1);

        cout << pizzaQuantities[pizzaChoice - 1][sizeIndex] << " REMAINING" << endl;
        pizzaQuantities[pizzaChoice - 1][sizeIndex]--;
        
        cout << "-------------------------------------" << endl;

        cout << "TOPPINGS MENU:\n" << endl;
        cout << "1 - PEPPERONI ($1.5)" << endl;
        cout << "2 - MUSHROOMS ($1.5)" << endl;
        cout << "3 - ONIONS ($1.5)" << endl;
        cout << "4 - SAUSAGE ($1.5)" << endl;
        cout << "5 - OLIVES ($1.5)\n" << endl;

        int toppingQuantity;
            cout << "ENTER THE NUMBER OF TOPPINGS: ";
            cin >> toppingQuantity;

        vector<string> selectedToppings;
        for (int i = 0; i < toppingQuantity; ++i) {
            int toppingChoice;
            do {
                cout << "CHOOSE YOUR TOPPING #" << i + 1 << ": ";
                cin >> toppingChoice;
                if (toppingChoice < 1 || toppingChoice > 5) {
                    cout << "PLEASE ENTER A VALID CHOICE (1-5)." << endl;
                } else {
                    selectedToppings.push_back(toppings[toppingChoice - 1].name);
                }
            } while (toppingChoice < 1 || toppingChoice > 5);
        }

        double pizzaCost;
        switch (pizzaChoice) {
            case 1:
                pizzaCost = 9.99;
                break;
            case 2:
                pizzaCost = 11.99;
                break;
            case 3:
                pizzaCost = 14.99;
                break;
            default:
                cout << "INVALID PIZZA CHOICE." << endl;
                return 1;
        }

        double toppingCost = 0.0;
        for (const string& topping : selectedToppings) {
            for (const Topping& t : toppings) {
                if (topping == t.name) {
                    toppingCost += t.cost;
                    break;
                }
            }
        }

        double totalCost = pizzaCost + toppingCost;

        cout << "-------------------------------------" << endl;

        cout << "DO YOU WANT A RECEIPT? (Y/N): ";
        cin >> choice;
        cout << "-------------------------------------" << endl;

        if (toupper(choice) == 'Y') {

            cout << "RECEIPT:\n" << endl;
            cout << "PIZZA: ";
            switch (pizzaChoice) {
                case 1:
                    cout << "MARGHERITA";
                    break;
                case 2:
                    cout << "PEPPERONI";
                    break;
                case 3:
                    cout << "SUPREME";
                    break;
                default:
                    cout << "INVALID PIZZA CHOICE.";
                    break;
            }
            cout << endl;

            cout << "SIZE: ";
            switch (size) {
                case 'S':
                case 's':
                    cout << "SMALL";
                    break;
                case 'M':
                case 'm':
                    cout << "MEDIUM";
                    break;
                case 'L':
                case 'l':
                    cout << "LARGE";
                    break;
                default:
                    break;
            }
            cout << endl;

            cout << "TOPPINGS: ";
            for (size_t i = 0; i < selectedToppings.size(); ++i) {
                cout << selectedToppings[i];
                if (i < selectedToppings.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;

            cout << "TOTAL COST: $" << fixed << setprecision(2) << totalCost << endl;
            cout << "-------------------------------------" << endl;
        }

        cout << "DO YOU WANT TO ORDER AGAIN? (Y/N): ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    return 0;
}