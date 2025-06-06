#include "Ej_3.h"

int main() {
    std::vector<std::unique_ptr<Numero>> numeros;

    // Agregar números de diferentes tipos
    numeros.push_back(std::make_unique<Entero>(5)); 
    numeros.push_back(std::make_unique<Entero>(-3));
    numeros.push_back(std::make_unique<Real>(4.7));
    numeros.push_back(std::make_unique<Real>(-2.1));
    numeros.push_back(std::make_unique<Complejo>(3, 4));
    numeros.push_back(std::make_unique<Complejo>(-1, 2));

    // Probar operaciones entre números del mismo tipo
    for (size_t i = 0; i < numeros.size(); ++i) {
        for (size_t j = i + 1; j < numeros.size(); ++j) {
            if (typeid(*numeros[i]) == typeid(*numeros[j])) {
                probarOperaciones(*numeros[i], *numeros[j]);
            }
        }
    }

    return 0;
}

// Función para probar operaciones entre dos números
void probarOperaciones(const Numero& a, const Numero& b) {
    std::cout << "\nProbando con: " << a.toString() << " y " << b.toString() << "\n";
    try {
        std::cout << "Suma: " << a.suma(b)->toString() << "\n";
        std::cout << "Resta: " << a.resta(b)->toString() << "\n";
        std::cout << "Multiplicacion: " << a.multiplicacion(b)->toString() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
