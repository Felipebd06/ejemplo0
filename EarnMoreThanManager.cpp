#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    int salary;
    int managerId; // -1 representa NULL
};

int main() {
    // Simulación de la tabla Employee
    vector<Employee> employees = {
        {1, "Joe", 70000, 3},
        {2, "Henry", 80000, 4},
        {3, "Sam", 60000, -1},
        {4, "Max", 90000, -1}
    };

    // Buscar empleados que ganen más que su manager
    for (const auto& emp : employees) {
        if (emp.managerId == -1) continue; // Sin manager

        for (const auto& manager : employees) {
            if (emp.managerId == manager.id && emp.salary > manager.salary) {
                cout << "Employee: " << emp.name << endl;
            }
        }
    }

    return 0;
}
