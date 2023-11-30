#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    std::string name;
    int totalLeaves;
    int leavesTaken;

public:
    Employee(const std::string& n) : name(n), totalLeaves(20), leavesTaken(0) {}

    const std::string& getName() const {
        return name;
    }

    void requestLeave(int days) {
        if (days <= totalLeaves - leavesTaken) {
            cout << "LEAVE REQUEST APPROVED FOR " << days << " DAYS.\n" << endl;
            leavesTaken += days;
        } else {
            cout << "INSUFFICIENT LEAVE BALANCE.\n";
        }
    }

    void displayDetails() const {
        cout << "EMPLOYEE NAME: " << name << "\n";
        cout << "TOTAL LEAVES: " << totalLeaves << "\n";
        cout << "LEAVES TAKEN: " << leavesTaken << "\n";
        cout << "LEAVE BALANCE: " << totalLeaves - leavesTaken << "\n";
    }
};

void manageEmployeeList(Employee* employees, int& employeeCount, bool& newEmployeeAdded) {
    cout << "\nEMPLOYEE MANAGEMENT MENU:\n";
    cout << "1. SHOW EMPLOYEE LIST\n";
    cout << "2. ADD NEW EMPLOYEE\n" << endl;
    cout << "ENTER YOUR CHOICE: ";
    char choice;
    cin >> choice;

    switch (choice) {
        case '1':
            if (employeeCount == 0) {
                cout << "NO EMPLOYEES IN THE LIST." << endl;
                cout << "ADD NEW EMPLOYEE" << endl;
            } else {
                cout << "EMPLOYEE LIST:\n";
                for (int i = 0; i < employeeCount; ++i) {
                    cout << "- " << employees[i].getName() << "\n";
                }
            }
            break;
        case '2': {
            string newName;
            cout << "NAME: ";
            cin >> newName;
            employees[employeeCount++] = Employee(newName);
            cout << "NEW EMPLOYEE ADDED.\n";
            newEmployeeAdded = true;
            break;
        }
        default:
            cout << "INVALID CHOICE. CONTINUING WITH THE PROGRAM...\n";
    }
}

int findEmployeeIndex(const Employee* employees, int employeeCount, const string& name) {
    for (int i = 0; i < employeeCount; ++i) {
        if (employees[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << "WELCOME TO LEAVE MANAGEMENT SYSTEM" << endl;
    cout << "----------------------------------";
    const int maxEmployees = 100;
    Employee employees[maxEmployees];
    int employeeCount = 0;
    string name;
    char choice;

    do {
        bool newEmployeeAdded = false;

        manageEmployeeList(employees, employeeCount, newEmployeeAdded);

        if (!newEmployeeAdded) {
            cout << "\nNAME: ";
            cin >> name;
        }

        int employeeIndex = findEmployeeIndex(employees, employeeCount, name);

        if (employeeIndex == -1 && !newEmployeeAdded) {
            employees[employeeCount++] = Employee(name);
            cout << "NEW EMPLOYEE ADDED.\n";
        }

        cout << "\nEMPLOYEE MENU:\n";
        cout << "1. REQUEST LEAVE\n";
        cout << "2. DISPLAY LEAVE DETAILS\n";
        cout << "3. EXIT\n" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int days;
                cout << "ENTER THE NUMBER OF DAYS FOR LEAVE: ";
                cin >> days;
                employees[employeeIndex].requestLeave(days);
                break;
            }
            case '2':
                employees[employeeIndex].displayDetails();
                break;
            case '3':
                cout << "EXITING...\n";
                break;
            default:
                cout << "INVALID CHOICE. PLEASE TRY AGAIN.\n";
        }

        cout << "GO BACK TO EMPLOYEE MANAGEMENT MENU (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
