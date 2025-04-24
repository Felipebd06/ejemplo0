Ordenamiento personalizado con pair
void ordenarDatos() {
    vector<pair<int, string>> datos = {
        {5, "manzana"},
        {3, "banana"},
        {8, "uva"},
        {2, "pera"}
    };

    sort(datos.begin(), datos.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first; // Descendente
    });

    cout << "\n--- Datos ordenados por valor numérico descendente ---\n";
    for (const auto& [num, fruta] : datos) {
        cout << num << " - " << fruta << endl;
    }
}

// MAIN
int main() {
    // Ejercicio 1: Set de palabras
    set<string> palabras;
    leerArchivoEnSet("samplefile.txt", palabras);

    cout << "--- Palabras únicas del archivo ---\n";
    for (const auto& palabra : palabras) {
        cout << palabra << "\n";
    }

    // Ejercicio 2: Frecuencia de palabras
    map<string, int> frecuencia;
    contarFrecuenciaPalabras("samplefile.txt", frecuencia);

    cout << "\n--- Frecuencia de palabras ---\n";
    for (const auto& [palabra, conteo] : frecuencia) {
        cout << palabra << ": " << conteo << "\n";
    }

    // Ejercicio 3: Cola de prioridad
    manejarTareas();

    // Ejercicio 4: find_if
    vector<int> numeros = {7, 8, 9, 15, 6, 21};
    buscarPrimerMayorA10(numeros);

    // Ejercicio 5: Ordenamiento personalizado
    ordenarDatos();

    return 0;
}