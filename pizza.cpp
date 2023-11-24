#include <iostream>
#include <iomanip>

using namespace std;

int smallQuantity = 10, mediumQuantity = 10, largeQuantity = 10;

int main() {
        cout << "Welcome to the Pizza Ordering System!" << endl;
    char choice;
    do {
        cout << "-------------------------------------" << endl;
        // pizza choices
        cout << "Pizza Choices:\n" << endl;
        cout << "1 - Margherita ($9.99)" << endl;
        cout << "2 - Pepperoni ($11.99)" << endl;
        cout << "3 - Supreme ($14.99)\n" << endl;

        // get user input for pizza choice
        cout << "Enter pizza choice (1/2/3): ";
        int pizzaChoice;
        cin >> pizzaChoice;

        // pizza sizes
        char size;

        // get user input for pizza size
        cout << "Select Sizes (S/M/L): ";
        cin >> size;

        // decrease quantity based on size
        switch (size) {
            case 'S':
            case 's':
                cout << "Small: " << smallQuantity << " remaining" << endl;
                smallQuantity--;
                break;
            case 'M':
            case 'm':
                cout << "Medium: " << mediumQuantity << " remaining" << endl;
                mediumQuantity--;
                break;
            case 'L':
            case 'l':
                cout << "Large: " << largeQuantity << " remaining" << endl;
                largeQuantity--;
                break;
            default:
                cout << "Invalid size choice." << endl;
                return 1;
        }

        cout << "-------------------------------------" << endl;
        // toppings menu
        cout << "Toppings Menu:\n" << endl;
        cout << "1 - Pepperoni ($1.5)" << endl;
        cout << "2 - Mushrooms ($1.5)" << endl;
        cout << "3 - Onions ($1.5)" << endl;
        cout << "4 - Sausage ($1.5)" << endl;
        cout << "5 - Olives ($1.5)\n" << endl;

        // get user input for toppings and quantity
        cout << "Choose your toppings (1-5): ";
        int toppingChoice;
        cin >> toppingChoice;

        cout << "Enter the quantity: ";
        int toppingQuantity;
        cin >> toppingQuantity;

        // calculate total cost
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
                cout << "Invalid pizza choice." << endl;
                return 1;
        }

        double toppingCost = 1.5 * toppingQuantity;
        double totalCost = pizzaCost + toppingCost;

        cout << "-------------------------------------" << endl;
        // print receipt
        cout << "Do you want a receipt? (Y/N): ";
        cin >> choice;
        cout << "-------------------------------------" << endl;
        
        if (toupper(choice) == 'Y') {
            // details
            cout << "Receipt:\n" << endl;
            cout << "Pizza: ";
            switch (pizzaChoice) {
                case 1:
                    cout << "Margherita";
                    break;
                case 2:
                    cout << "Pepperoni";
                    break;
                case 3:
                    cout << "Supreme";
                    break;
                default:
                    cout << "Invalid pizza choice.";
                    break;
            }
            cout << endl;

            cout << "Size: ";
            switch (size) {
                case 'S':
                case 's':
                    cout << "Small";
                    break;
                case 'M':
                case 'm':
                    cout << "Medium";
                    break;
                case 'L':
                case 'l':
                    cout << "Large";
                    break;
                default:
                    break;
            }
            cout << endl;

            cout << "Toppings: ";
            switch (toppingChoice) {
                case 1:
                    cout << "Pepperoni";
                    break;
                case 2:
                    cout << "Mushrooms";
                    break;
                case 3:
                    cout << "Onions";
                    break;
                case 4:
                    cout << "Sausage";
                    break;
                case 5:
                    cout << "Olives";
                    break;
                default:
                    cout << "Invalid topping choice.";
                    break;
            }
            cout << " (" << toppingQuantity << " quantity)" << endl;

            cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
            cout << "-------------------------------------" << endl;
        }

        // option to order again
        cout << "Do you want to order again? (Y/N): ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    return 0;
}
