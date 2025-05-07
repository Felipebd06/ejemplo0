#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // Simulación de la tabla Employee
    vector<pair<int, int>> employee = {
        {1, 100},
        {2, 200},
        {3, 300}
    };

    // Usamos un set para obtener salarios únicos
    set<int, greater<int>> uniqueSalaries;  // Orden descendente

    for (const auto& e : employee) {
        uniqueSalaries.insert(e.second);
    }

    // Verificamos si hay al menos 2 salarios distintos
    if (uniqueSalaries.size() < 2) {
        cout << "SecondHighestSalary: null" << endl;
    } else {
        auto it = uniqueSalaries.begin();
        ++it;  // Apuntamos al segundo salario más alto
        cout << "SecondHighestSalary: " << *it << endl;
    }

    return 0;
}
