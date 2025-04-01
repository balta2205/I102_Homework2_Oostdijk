#include "Ej_2.h"

/*
ii. Ver si un estudiante se encuentra inscripto o no en el curso buscándolo por
su legajo.
iii. Indicar si el curso está completo o no, teniendo en cuenta que el curso tiene
una capacidad de 20 alumnos.
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

// Constructor.
Estudiante::Estudiante(std::string nombre, int legajo) : nombre(nombre), legajo(legajo) {}

// Metodos getters.
std::string Estudiante::getNombre() const {return nombre;} // Devuelve el nombre.

int Estudiante::getLegajo() const {return legajo;} // Devuelve el legajo

double Estudiante::getPromedio() const { // Devuelve el promedio de las notas 
    if(cursosNotas.empty()) return 0.0;
    double promedio = 0.0;
    for(int i = 0; i < cursosNotas.size(); i++){
        promedio += cursosNotas[i].second;
    }

    return promedio / cursosNotas.size();
}

// Metodo para agregar un curso y su nota.
void Estudiante::agregarCursoNota(std::string curso, double nota) {cursosNotas.push_back(std::make_pair(curso, nota));}

void Estudiante::eliminarCursoNota(std::string curso){

    for(int i = 0; i < cursosNotas.size(); i++){
        if(cursosNotas[i].first == curso){
            cursosNotas.erase(cursosNotas.begin() + i);
            return;
        }
    }
}

Curso::Curso(std::string nombre) : {nombre(nombre);} 

std::string Curso::getNombre(){return nombre;}

void Curso::inscribirEstudiante(std::unique_ptr<Estudiante> estudiante){
    if (capacidad_max == 20){
        std::cout << "Cupos llenos." << std::endl;
        return;
    }
    lista_estudiantes.push_back(estudiante);
    return;
}

void Curso::desinscribirEstudiante(int legajo){

    for(int i = 0; i < lista_estudiantes.size(); i++){
        if(lista_estudiantes[i].getLegajo() == legajo){
            lista_estudiantes[i].eliminarCursoNota(this.getNombre())
            lista_estudiantes.erase(i);
            return;
        }
    }

    std::cout << "El estudiante con el legajo " << legajo << " no estaba inscripto." << std::endl;
}

