#include "Ej_2.h"

// Clase Estudiante

// Constructor.
Estudiante::Estudiante(std::string name, int leg) : nombre(std::move(name)), legajo(leg) {}

// Metodos getters.
std::string Estudiante::getNombre() const {return nombre;} // Devuelve el nombre.

int Estudiante::getLegajo() const {return legajo;} // Devuelve el legajo

double Estudiante::getPromedio() const { // Devuelve el promedio de las notas 
    if(cursosNotas.empty()) return 0.0;
    double promedio = 0.0;
    for(const auto& pareja : cursosNotas) promedio += pareja.second;

    return promedio / cursosNotas.size();
}

// Metodo para agregar un curso y su nota.
void Estudiante::agregarCursoNota(std::string curso, double nota) {
    for(const auto& pareja : cursosNotas) {
        if (pareja.first == curso) {
            std::cout << "El curso ya esta anotado con nombre: " << pareja.first << ", y nota: " << pareja.second << "." << std::endl;
            return; 
        }
    }
    cursosNotas.push_back(std::make_pair(curso, nota));
    return;
}

// Metodo para eliminar un curso y su nota.
void Estudiante::eliminarCursoNota(std::string curso){ 
    for (size_t i = 0; i < cursosNotas.size(); i++) {
        if(cursosNotas[i].first == curso) {
            cursosNotas.erase(cursosNotas.begin() + i); 
            return;
        } 
    }
}

// Sobrecarga del operador < para ordenar estudiantes por nombre.
bool Estudiante::operator<(const Estudiante& otro) const {return nombre < otro.nombre;}

// Sobrecarga del operador << para imprimir estudiantes.
std::ostream& operator<<(std::ostream& os, const Estudiante& est) {
    os << "Nombre: " << est.nombre << ", Legajo: " << est.legajo;
    return os;
}


// Clase Curso.

// Constructor.
Curso::Curso(std::string nombre) : nombre(std::move(nombre)) {}

// Metodos Getters.
std::string Curso::getNombre(){return nombre;}

// Metodo para inscribir un estudiante. -> Inciso b) -> i)
void Curso::inscribirEstudiante(std::shared_ptr<Estudiante> estudiante){
    if (completo()){ std::cout << "Cupos llenos." << std::endl; return;}

    if(buscarEstudiante(estudiante -> getLegajo())){ 
        std::cout << "El estudiante ya esta inscripto en este curso." <<std::endl; 
        return; 
    }

    lista_estudiantes.push_back(estudiante);
    return;
}

// Metodo para desinscribir un estudiante. -> Inciso b) -> i)
void Curso::desinscribirEstudiante(int legajo){

    if (!buscarEstudiante(legajo)) {
        std::cout << "El estudiante con el legajo " << legajo << " no estaba inscripto." << std::endl;
        return;
    }

    for(size_t i = 0; i < lista_estudiantes.size(); i++){ 
        if(lista_estudiantes[i] -> getLegajo() == legajo){ 
            lista_estudiantes.erase(lista_estudiantes.begin() + i); 
            return; 
        } 
    }

}

// Metodo para saber si un estudiante esta inscripto o no. -> Inciso b) -> ii)
bool Curso::buscarEstudiante(int legajo){
    for (const auto& estudiante : lista_estudiantes) if(estudiante -> getLegajo() == legajo) return true; 
    return false;
}

// Metodo para saber si el curso esta completo. -> Inceso b) -> iii)
bool Curso::completo(){
    if (lista_estudiantes.size() == capacidad_max){
        std::cout << "El curso esta completo (hay 20 alumnos inscriptos)." << std::endl;
        return true;
    }
    return false;
}

// Método para ordenar la lista de estudiantes. -> Inciso b) -> iv)
void Curso::ordenarEstudiantes() {
    std::sort(lista_estudiantes.begin(), lista_estudiantes.end(), 
        [](const std::shared_ptr<Estudiante>& a, const std::shared_ptr<Estudiante>& b) {
            return *a < *b; // Usa el operador < sobrecargado
        });
}

// Metodo para imprimir la lista de estudiantes. -> Inciso b) -> iv)
void Curso::imprimirEstudiantes() {
    ordenarEstudiantes(); // Primero ordenamos la lista

    std::cout << "Lista de estudiantes en orden alfabetico:\n";
    for (const auto& estudiante : lista_estudiantes) {
        std::cout << *estudiante << std::endl; // Usa el operador << sobrecargado
    }
}

// Constructor de copia (shallow copy)
Curso::Curso(const Curso& otro) : nombre(otro.nombre), lista_estudiantes(otro.lista_estudiantes) {
    /*
    Esta es una copia superficial (shallow copy). Se copian los punteros shared_ptr, por lo que ambas instancias
    de Curso compartirán los mismos objetos Estudiante. Esto es eficiente, pero cualquier modificación en un estudiante
    afectará a ambas instancias.
    */
}
