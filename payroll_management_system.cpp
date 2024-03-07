#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>
// include <bits/stdc++.h> includes everything

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
    string department;
};

void displayMenu() {
    cout << "1. List all employees records\n";
    cout << "2. Add new employee record\n";
    cout << "3. Update employee record\n";
    cout << "4. Delete employee record\n";
    cout << "5. Search employee record by ID\n";
    cout << "6. Print payslip\n";
    cout << "0. Quit\n";
}

void listEmployees(const vector<Employee>& employees) {
    cout << "Listing all employees:\n";
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << ", Department: " << emp.department << endl;
    }
}

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter employee salary: ";
    cin >> emp.salary;
    cout << "Enter employee department: ";
    cin.ignore();
    getline(cin, emp.department);
    employees.push_back(emp);
    cout << "Employee record added successfully.\n";
}

void updateEmployee(vector<Employee>& employees, int id) {
    for (auto& emp : employees) {
        if (emp.id == id) {
            cout << "Enter new name for employee " << id << ": ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Enter new salary for employee " << id << ": ";
            cin >> emp.salary;
            cout << "Enter new department for employee " << id << ": ";
            cin.ignore();
            getline(cin, emp.department);
            cout << "Employee record updated successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void deleteEmployee(vector<Employee>& employees, int id) {
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& emp) { return emp.id == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Employee record deleted successfully.\n";
    } else {
        cout << "Employee with ID " << id << " not found.\n";
    }
}

void searchEmployee(const vector<Employee>& employees, int id) {
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "Employee found:\n";
            cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << ", Department: " << emp.department << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void printPayslip(const vector<Employee>& employees, int id) {
    for (const auto& emp : employees) {
        if (emp.id == id) {
            // Open a file to write payslip
            string fileName = "payslip_" + to_string(emp.id) + ".txt";
            ofstream file(fileName);
            if (file.is_open()) {
                // Get current date
                time_t now = time(0);
                tm* currentDate = localtime(&now);
                file << "Payslip for " << emp.name << endl;
                file << "Date: " << currentDate->tm_mday << "/" << currentDate->tm_mon + 1 << "/" << currentDate->tm_year + 1900 << endl;
                file << "Salary: $" << emp.salary << endl;
                file.close();
                cout << "Payslip generated successfully. Check " << fileName << endl;
            } else {
                cout << "Error: Unable to open file.\n";
            }
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

int main() {
    vector<Employee> employees;
    int choice;

    while (true) {
        cout << "Enter 1 to login or 0 to quit: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        } else if (choice == 1) {
            displayMenu();
            int menuChoice;
            cout << "Enter your choice: ";
            cin >> menuChoice;

            switch (menuChoice) {
                case 1:
                    listEmployees(employees);
                    break;
                case 2:
                    addEmployee(employees);
                    break;
                case 3:
                    int updateId;
                    cout << "Enter employee ID to update: ";
                    cin >> updateId;
                    updateEmployee(employees, updateId);
                    break;
                case 4:
                    int deleteId;
                    cout << "Enter employee ID to delete: ";
                    cin >> deleteId;
                    deleteEmployee(employees, deleteId);
                    break;
                case 5:
                    int searchId;
                    cout << "Enter employee ID to search: ";
                    cin >> searchId;
                    searchEmployee(employees, searchId);
                    break;
                case 6:
                    int payslipId;
                    cout << "Enter employee ID to print payslip: ";
                    cin >> payslipId;
                    printPayslip(employees, payslipId);
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
    string department;
};

void displayMenu() {
    cout << "1. List all employees records\n";
    cout << "2. Add new employee record\n";
    cout << "3. Update employee record\n";
    cout << "4. Delete employee record\n";
    cout << "5. Search employee record by ID\n";
    cout << "6. Print payslip\n";
    cout << "0. Quit\n";
}

void listEmployees(const vector<Employee>& employees) {
    cout << "Listing all employees:\n";
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << ", Department: " << emp.department << endl;
    }
}

void addEmployee(vector<Employee>& employees) {
    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.id;
    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, emp.name);
    cout << "Enter employee salary: ";
    cin >> emp.salary;
    cout << "Enter employee department: ";
    cin.ignore();
    getline(cin, emp.department);
    employees.push_back(emp);
    cout << "Employee record added successfully.\n";
}

void updateEmployee(vector<Employee>& employees, int id) {
    for (auto& emp : employees) {
        if (emp.id == id) {
            cout << "Enter new name for employee " << id << ": ";
            cin.ignore();
            getline(cin, emp.name);
            cout << "Enter new salary for employee " << id << ": ";
            cin >> emp.salary;
            cout << "Enter new department for employee " << id << ": ";
            cin.ignore();
            getline(cin, emp.department);
            cout << "Employee record updated successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void deleteEmployee(vector<Employee>& employees, int id) {
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& emp) { return emp.id == id; });
    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Employee record deleted successfully.\n";
    } else {
        cout << "Employee with ID " << id << " not found.\n";
    }
}

void searchEmployee(const vector<Employee>& employees, int id) {
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "Employee found:\n";
            cout << "ID: " << emp.id << ", Name: " << emp.name << ", Salary: $" << emp.salary << ", Department: " << emp.department << endl;
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

void printPayslip(const vector<Employee>& employees, int id) {
    for (const auto& emp : employees) {
        if (emp.id == id) {
            // Open a file to write payslip
            string fileName = "payslip_" + to_string(emp.id) + ".txt";
            ofstream file(fileName);
            if (file.is_open()) {
                // Get current date
                time_t now = time(0);
                tm* currentDate = localtime(&now);
                file << "Payslip for " << emp.name << endl;
                file << "Date: " << currentDate->tm_mday << "/" << currentDate->tm_mon + 1 << "/" << currentDate->tm_year + 1900 << endl;
                file << "Salary: $" << emp.salary << endl;
                file.close();
                cout << "Payslip generated successfully. Check " << fileName << endl;
            } else {
                cout << "Error: Unable to open file.\n";
            }
            return;
        }
    }
    cout << "Employee with ID " << id << " not found.\n";
}

int main() {
    vector<Employee> employees;
    int choice;

    while (true) {
        cout << "Enter 1 to login or 0 to quit: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting program...\n";
            break;
        } else if (choice == 1) {
            displayMenu();
            int menuChoice;
            cout << "Enter your choice: ";
            cin >> menuChoice;

            switch (menuChoice) {
                case 1:
                    listEmployees(employees);
                    break;
                case 2:
                    addEmployee(employees);
                    break;
                case 3:
                    int updateId;
                    cout << "Enter employee ID to update: ";
                    cin >> updateId;
                    updateEmployee(employees, updateId);
                    break;
                case 4:
                    int deleteId;
                    cout << "Enter employee ID to delete: ";
                    cin >> deleteId;
                    deleteEmployee(employees, deleteId);
                    break;
                case 5:
                    int searchId;
                    cout << "Enter employee ID to search: ";
                    cin >> searchId;
                    searchEmployee(employees, searchId);
                    break;
                case 6:
                    int payslipId;
                    cout << "Enter employee ID to print payslip: ";
                    cin >> payslipId;
                    printPayslip(employees, payslipId);
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
