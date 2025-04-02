#include "Ej_3.h"

int main() {
    std::vector<std::unique_ptr<Numero>> numeros;
    
    numeros.push_back(std::make_unique<Entero>(5));
    numeros.push_back(std::make_unique<Entero>(-3));
    numeros.push_back(std::make_unique<Real>(4.7));
    numeros.push_back(std::make_unique<Real>(-2.1));
    numeros.push_back(std::make_unique<Complejo>(3, 4));
    numeros.push_back(std::make_unique<Complejo>(-1, -2));
    
    for (size_t i = 0; i < numeros.size(); ++i) {
        for (size_t j = 0; j < numeros.size(); ++j) {
            probarOperaciones(*numeros[i], *numeros[j]);
        }
    }
    
    return 0;
}

void probarOperaciones(const Numero& a, const Numero& b) {
    std::cout << "\nProbando con: " << a.toString() << " y " << b.toString() << "\n";
    std::cout << "Suma: " << a.suma(b)->toString() << "\n";
    std::cout << "Resta: " << a.resta(b)->toString() << "\n";
    std::cout << "Multiplicación: " << a.multiplicacion(b)->toString() << "\n";
}