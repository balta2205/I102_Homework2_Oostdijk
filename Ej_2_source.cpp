#include "Ej_2.h"

/*

iv. Imprimir la lista de estudiantes en orden alfabético. Para ello, utilice el
algoritmo std::sort() en <algorithm>, el cual requerirá sobreescribir el
operador “<”, y sobreescriba el operador “<<” (del método y clase que
correspondan) para presentar los datos por pantalla.

v. Dado que algunos cursos comparten la mayor parte de los estudiantes, se
desea poder hacer una copia del objeto curso. Justifique su respuesta con
un comentario en el código (esta puede llevar varias líneas), indicando de
que tipo de copia se trata y como la hizo.

c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
d.*/

// Clase Estudiante

// Constructor.
Estudiante::Estudiante(std::string name, int leg) : nombre(std::move(name)), legajo(leg) {}

// Metodos getters.
std::string Estudiante::getNombre() const {return nombre;} // Devuelve el nombre.

int Estudiante::getLegajo() const {return legajo;} // Devuelve el legajo

double Estudiante::getPromedio() const { // Devuelve el promedio de las notas 
    if(cursosNotas.empty()) return 0.0;
    double promedio = 0.0;
    for(int i = 0; i < cursosNotas.size(); i++) promedio += cursosNotas[i].second;

    return promedio / cursosNotas.size();
}

// Metodo para agregar un curso y su nota.
void Estudiante::agregarCursoNota(std::string curso, double nota) {
    for(int i = 0; i < cursosNotas.size(); i++) {
        if (cursosNotas[i].first == curso) {
            std::cout << "El curso ya esta anotado con nombre: " << cursosNotas[i].first << ", y nota: " << cursosNotas[i].second << "." << std::endl;
            return; 
        }
    }
    cursosNotas.push_back(std::make_pair(curso, nota));
    return;
}

// Metodo para eliminar un curso y su nota.
void Estudiante::eliminarCursoNota(std::string curso){ 
    for (int i = 0; i < cursosNotas.size(); i++) {
        if(cursosNotas[i].first == curso) {
            cursosNotas.erase(cursosNotas.begin() + i); 
            return;
        } 
    }
}


// Clase Curso.

// Constructor.
Curso::Curso(std::string nombre) : nombre(std::move(nombre)) {}

// Metodos Getters.
std::string Curso::getNombre(){return nombre;}

// Metodo para inscribir un estudiante. -> Inciso b) -> i)
void Curso::inscribirEstudiante(std::unique_ptr<Estudiante> estudiante){
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

    for(int i = 0; i < lista_estudiantes.size(); i++){ 
        if(lista_estudiantes[i] -> getLegajo() == legajo){ 
            lista_estudiantes[i] -> eliminarCursoNota(nombre);
            lista_estudiantes.erase(lista_estudiantes.begin() + i); 
            return; 
        } 
    }

}

// Metodo para saber si un estudiante esta inscripto o no. -> Inciso b) -> ii)
bool Curso::buscarEstudiante(int legajo){
    for (int i; i < lista_estudiantes.size(); i++) if(lista_estudiantes[i] -> getLegajo() == legajo) return true; 
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