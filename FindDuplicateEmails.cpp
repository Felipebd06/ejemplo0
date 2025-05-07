#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Person {
    int id;
    string email;
};

int main() {
    // Simulación de la tabla Person
    vector<Person> people = {
        {1, "a@b.com"},
        {2, "c@d.com"},
        {3, "a@b.com"}
    };

    // Mapa para contar las ocurrencias de cada email
    unordered_map<string, int> emailCount;

    // Contamos la cantidad de veces que aparece cada email
    for (const auto& person : people) {
        emailCount[person.email]++;
    }

    // Imprimimos los correos que tienen más de una ocurrencia
    for (const auto& entry : emailCount) {
        if (entry.second > 1) {
            cout << entry.first << endl;
        }
    }

    return 0;
}
