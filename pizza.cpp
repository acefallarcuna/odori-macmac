#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    const int pizzaTypes = 3;
    const int pizzaSizes = 3;

    int pizzaQuantities[pizzaTypes][pizzaSizes] = {
        {10, 10, 10},
        {10, 10, 10},
        {10, 10, 10}
    };

    const int numToppings = 10;
    const string toppings[numToppings] = {"PEPPERONI", "MUSHROOMS", "ONIONS", "SAUSAGE", "OLIVES",
                                          "BELL PEPPERS", "TOMATOES", "BACON", "HAM", "PINEAPPLE"};

    const int maxToppings = 5;

    struct Pizza {
        string name;
        double prices[pizzaSizes];
    };

    Pizza pizzas[pizzaTypes] = {
        {"MARGHERITA (8.99, 10.99, 12.99)", {8.99, 10.99, 12.99}},
        {"PEPPERONI (9.99, 11.99, 13.99)", {9.99, 11.99, 13.99}},
        {"SUPREME (10.99, 12.99, 14.99)", {10.99, 12.99, 14.99}}
    };

    cout << "WELCOME TO THE PIZZA ORDERING SYSTEM!" << endl;
    char orderAgainChoice;

    do {
        cout << "---------------------------------------" << endl;

        for (int i = 0; i < pizzaTypes; ++i) {
            int totalQuantity = 0;
            for (int j = 0; j < pizzaSizes; ++j) {
                totalQuantity += pizzaQuantities[i][j];
            }
            cout << i + 1 << " - " << pizzas[i].name << " - QUANTITY: " << totalQuantity << endl;
        }
        cout << "0 - CANCEL ORDER\n" << endl;

        int pizzaChoice;
        bool invalidInput;
        do {
            invalidInput = false;
            cout << "ENTER PIZZA CHOICE (0/1/2/3): ";
            cin >> pizzaChoice;

            if (cin.fail() || pizzaChoice < 0 || pizzaChoice > 3 || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT. PLEASE ENTER A SINGLE-DIGIT INTEGER BETWEEN 0 AND 3." << endl;
                invalidInput = true;
            }
        } while (invalidInput);

        if (pizzaChoice == 0) {
            cout << "ORDER CANCELLED. THANK YOU!" << endl;
            break;
        }

        char size;

        int sizeIndex;
        do {
            invalidInput = false;
        
            cout << "---------------------------------------" << endl;
            cout << "S - SMALL ($" << pizzas[pizzaChoice - 1].prices[0] << ") - QUANTITY: " << pizzaQuantities[pizzaChoice - 1][0] << endl;
            cout << "M - MEDIUM ($" << pizzas[pizzaChoice - 1].prices[1] << ") - QUANTITY: " << pizzaQuantities[pizzaChoice - 1][1] << endl;
            cout << "L - LARGE ($" << pizzas[pizzaChoice - 1].prices[2] << ") - QUANTITY: " << pizzaQuantities[pizzaChoice - 1][2] << endl;
            cout << "\nSELECT SIZES (S/M/L): ";
        
            cin >> size;
        
            size = toupper(size);
        
            switch (size) {
                case 'S':
                    sizeIndex = 0;
                    cout << "SMALL: ";
                    break;
                case 'M':
                    sizeIndex = 1;
                    cout << "MEDIUM: ";
                    break;
                case 'L':
                    sizeIndex = 2;
                    cout << "LARGE: ";
                    break;
                default:
                    cout << "INVALID SIZE CHOICE. PLEASE ENTER A VALID CHOICE (S/M/L)." << endl;
                    sizeIndex = -1;
                    invalidInput = true;
                    break;
            }
        
            if (cin.peek() != '\n') {
                cout << "INVALID INPUT. PLEASE ENTER ONLY 'S', 'M', OR 'L'." << endl;
                invalidInput = true;
            }
        
            if (invalidInput) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (sizeIndex == -1 || invalidInput);

        cout << pizzaQuantities[pizzaChoice - 1][sizeIndex] << " REMAINING" << endl;
        pizzaQuantities[pizzaChoice - 1][sizeIndex]--;

        cout << "---------------------------------------" << endl;

        cout << "TOPPINGS MENU:\n" << endl;
        for (int i = 0; i < numToppings; ++i) {
            cout << i + 1 << " - " << toppings[i] << " ($1.5)" << endl;
        }
        cout << endl;

        int toppingQuantity;
        do {
            invalidInput = false;
            cout << "ENTER THE NUMBER OF TOPPINGS (UP TO " << maxToppings << "): ";
            cin >> toppingQuantity;

            if (cin.fail() || toppingQuantity < 1 || toppingQuantity > maxToppings || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT. PLEASE ENTER AN INTEGER BETWEEN 1 AND " << maxToppings << "." << endl;
                invalidInput = true;
            }
        } while (invalidInput);

        string selectedToppings[maxToppings];
        for (int i = 0; i < toppingQuantity; ++i) {
            int toppingChoice;
            do {
                cout << "CHOOSE YOUR TOPPING #" << i + 1 << ": ";
                cin >> toppingChoice;
                if (toppingChoice < 1 || toppingChoice > numToppings) {
                    cout << "PLEASE ENTER A VALID CHOICE (1-" << numToppings << ")." << endl;
                } else {
                    selectedToppings[i] = toppings[toppingChoice - 1];
                }
            } while (toppingChoice < 1 || toppingChoice > numToppings);
        }

        double pizzaCost = pizzas[pizzaChoice - 1].prices[sizeIndex];
        double toppingCost = 1.5 * toppingQuantity;
        double totalCost = pizzaCost + toppingCost;

        cout << "---------------------------------------" << endl;

        char choice;
        do {
            invalidInput = false;
            cout << "DO YOU WANT A RECEIPT? (Y/N): ";
            cin >> choice;

            if ((choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') || cin.peek() != '\n') {
                cout << "INVALID INPUT. PLEASE ENTER 'Y' FOR YES OR 'N' FOR NO." << endl;
                invalidInput = true;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (invalidInput);

        cout << "-------------------------------------" << endl;

        if (toupper(choice) == 'Y') {
            cout << "RECEIPT:\n" << endl;
            cout << "PIZZA: " << pizzas[pizzaChoice - 1].name << endl;
            cout << "SIZE: " << size << " (COST: $" << pizzas[pizzaChoice - 1].prices[sizeIndex] << ")" << endl;
            
            cout << "TOPPINGS: ";
            for (int i = 0; i < toppingQuantity; ++i) {
                cout << selectedToppings[i];
                if (i < toppingQuantity - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
            
            cout << "TOTAL COST: $" << totalCost << endl;
            cout << "---------------------------------------" << endl;
        }

        do {
            invalidInput = false;
            cout << "DO YOU WANT TO ORDER AGAIN? (Y/N): ";
            cin >> orderAgainChoice;

            if ((orderAgainChoice != 'Y' && orderAgainChoice != 'y' && orderAgainChoice != 'N' && orderAgainChoice != 'n') || cin.peek() != '\n') {
                cout << "INVALID INPUT. PLEASE ENTER 'Y' FOR YES OR 'N' FOR NO." << endl;
                invalidInput = true;

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (invalidInput);

    } while (toupper(orderAgainChoice) == 'Y');

    return 0;
}
