#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>

// Función para limpiar palabras: quita puntuación y pone todo en minúsculas
std::string limpiarPalabra(const std::string& palabra) {
    std::string limpia;
    for (char ch : palabra) {
        if (std::isalpha(ch)) {
            limpia += std::tolower(ch);
        }
    }
    return limpia;
}

std::set<std::string> leerPalabrasDeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    std::set<std::string> conjuntoPalabras;

    if (!archivo) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return conjuntoPalabras;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream streamLinea(linea);
        std::string palabra;

        while (streamLinea >> palabra) {
            std::string limpia = limpiarPalabra(palabra);
            if (!limpia.empty()) {
                conjuntoPalabras.insert(limpia);
            }
        }
    }

    return conjuntoPalabras;
}

int main() {
    const std::string archivo = "sampleFile.txt";
    std::set<std::string> palabras = leerPalabrasDeArchivo(archivo);

    std::cout << "Palabras únicas encontradas (" << palabras.size() << "):\n";
    for (const auto& palabra : palabras) {
        std::cout << palabra << "\n";
    }

    return 0;
}
