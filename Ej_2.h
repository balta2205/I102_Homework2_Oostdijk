#ifndef Ej_2.H
#define Ej_2.H

#include <iostream>
#include <vector>
#include <memory>  // Para unique_ptr
#include <string>
#include <utility> // Para std::pair 

class Estudiante {
private:
    const std::string nombre;
    const int legajo;
    std::vector<std::pair<std::string, double>> cursosNotas;

public:
    // Constructor
    Estudiante(std::string nombre, int leg);

    //Destructor
    ~Estudiante() = default;

    // Métodos de acceso
    std::string getNombre() const;
    int getLegajo() const;
    double getPromedio() const;

    // Método para agregar un curso y su nota
    void agregarCursoNota(std::string curso, double nota);
    void eliminarCursoNota(std::string curso);

};

class Curso {
private:
    const std::string nombre;
    const int capacidad_max = 20;
    std::vector<std::unique_ptr<Estudiante>> lista_estudiantes;

public:

    // Constructor
    Curso(std::string nombre);

    // Destructor
    ~Curso() = default;

    // Getters.
    std::string getCurso();
    std::string getNombre();

    // Metodos
    void inscribirEstudiante(std::unique_ptr<Estudiante> estudiante);
    void desinscribirEstudiante(int legajo);
    bool buscarEstudiante(int legajo);
    bool completo();
    void imprimirEstudiantes();
    void ordenarEstudiantes();
};

#endif