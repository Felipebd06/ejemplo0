#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

// Función para limpiar la palabra
std::string limpiarPalabra(const std::string& palabra) {
    std::string limpia;
    for (char ch : palabra) {
        if (std::isalpha(ch)) {
            limpia += std::tolower(ch);
        }
    }
    return limpia;
}

std::map<std::string, int> contarFrecuenciaPalabras(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::map<std::string, int> frecuencia;

    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return frecuencia;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string palabra;

        while (iss >> palabra) {
            std::string limpia = limpiarPalabra(palabra);
            if (!limpia.empty()) {
                ++frecuencia[limpia];
            }
        }
    }

    return frecuencia;
}

int main() {
    const std::string archivo = "sampleFile.txt";
    auto frecuencias = contarFrecuenciaPalabras(archivo);

    std::cout << "Frecuencia de palabras:\n";
    for (const auto& [palabra, cantidad] : frecuencias) {
        std::cout << palabra << ": " << cantidad << "\n";
    }

    return 0;
}
