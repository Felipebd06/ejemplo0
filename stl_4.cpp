#include <iostream>
#include <vector>
#include <algorithm> // para std::find_if

bool esPar(int n) {
    return n % 2 == 0;
}

int main() {
    std::vector<int> numeros = {7, 13, 9, 8, 15, 6, 21};

    auto it = std::find_if(numeros.begin(), numeros.end(), esPar);

    if (it != numeros.end()) {
        std::cout << "Primer número par encontrado: " << *it << std::endl;
    } else {
        std::cout << "No se encontró ningún número par.\n";
    }

    return 0;
}
