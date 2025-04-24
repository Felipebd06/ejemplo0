#include <iostream>
#include <queue>
#include <string>
#include <vector>

// Estructura para representar una tarea
struct Tarea {
    int prioridad;
    std::string descripcion;

    // Comparador para priority_queue (max heap)
    bool operator<(const Tarea& otra) const {
        return prioridad < otra.prioridad;
    }
};

int main() {
    std::priority_queue<Tarea> tareas;

    // Insertamos las tareas (en orden aleatorio)
    tareas.push({3, "Revisión de informes"});
    tareas.push({1, "Preparar presentación"});
    tareas.push({4, "Responder correos urgentes"});
    tareas.push({2, "Reunión con el equipo"});
    tareas.push({5, "Planificar nueva estrategia"});

    // Mostramos las tareas en orden de prioridad (mayor primero)
    std::cout << "Tareas ordenadas por prioridad:\n";
    while (!tareas.empty()) {
        const auto& tarea = tareas.top();
        std::cout << "Prioridad " << tarea.prioridad << ": " << tarea.descripcion << "\n";
        tareas.pop();
    }

    return 0;
}
