#ifndef EJ_2_H  
#define EJ_2_H  

#include <iostream>
#include <vector>
#include <memory>  // Para shared_ptr
#include <string>
#include <utility> // Para std::pair 
#include <algorithm>

class Estudiante {
private:
    const std::string nombre;
    const int legajo;
    std::vector<std::pair<std::string, double>> cursosNotas;

public:
    // Constructor
    Estudiante(std::string nombre, int leg);

    // Destructor
    ~Estudiante() = default;

    // Métodos de acceso
    std::string getNombre() const;
    int getLegajo() const;
    double getPromedio() const;
    std::vector<std::pair<std::string, double>> getCursosNotas() const;

    // Método para agregar un curso y su nota
    void agregarCursoNota(std::string curso, double nota);
    void eliminarCursoNota(std::string curso);

    // Sobrecarga del operador < para ordenar estudiantes por nombre.
    bool operator<(const Estudiante& otro) const;

    // Sobrecarga del operador << para imprimir estudiantes.
    friend std::ostream& operator<<(std::ostream& os, const Estudiante& est);
};

class Curso {
private:
    const std::string nombre;
    static const int capacidad_max = 20;
    std::vector<std::shared_ptr<Estudiante>> lista_estudiantes;

public:
    // Constructor
    Curso(std::string nombre);

    // Destructor
    ~Curso() = default;

    // Getters
    std::string getNombre() const;

    // Métodos
    void inscribirEstudiante(std::shared_ptr<Estudiante> estudiante);
    void desinscribirEstudiante(int legajo);
    bool buscarEstudiante(int legajo);
    bool completo();

    void ordenarEstudiantes();  
    void imprimirEstudiantes(); 

    // Constructor de copia (shallow copy)
    Curso(const Curso& otro);
};

// Funciones para mostrar los menús.
void mostrarMenuPrincipal();
void mostrarMenuEstudiante();
void mostrarMenuCurso();

#endif