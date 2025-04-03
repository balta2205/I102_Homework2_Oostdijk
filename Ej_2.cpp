#include "Ej_2.h"

int main() {
    Curso curso("Matemáticas");
    Curso* copiaShallow = nullptr;
    Curso copiaDeep("Temp");
    std::shared_ptr<Estudiante> estudiante = nullptr;
    
    int opcionPrincipal;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcionPrincipal;
        std::cout << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        
        switch (opcionPrincipal) {
            case 1: {
                int opcionEstudiante;
                do {
                    mostrarMenuEstudiante();
                    std::cin >> opcionEstudiante;
                    std::cout << std::endl;
                    std::cout << "--------------------------------------" << std::endl;
                    switch (opcionEstudiante) {
                        case 1: {
                            std::string nombre;
                            int legajo;
                            std::cout << "Nombre del estudiante: ";
                            std::cin >> nombre;
                            std::cout << "Legajo: ";
                            std::cin >> legajo;
                            estudiante = std::make_shared<Estudiante>(nombre, legajo);
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 2: {
                            if (estudiante) {
                                std::cout << *estudiante << "\n";
                            } else {
                                std::cout << "No hay estudiante creado.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 3: {
                            if (estudiante) {
                                std::string curso;
                                double nota;
                                std::cout << "Ingrese el curso: ";
                                std::cin >> curso;
                                std::cout << "Ingrese la nota: ";
                                std::cin >> nota;
                                estudiante->agregarCursoNota(curso, nota);
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 4: {
                            if (estudiante) {
                                std::string curso;
                                std::cout << "Ingrese el curso de la nota a eliminar: ";
                                std::cin >> curso;
                                estudiante->eliminarCursoNota(curso);
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 5: {
                            if (estudiante) {
                                std::cout << "Promedio: " << estudiante->getPromedio() << "\n";
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 6:
                            break;
                        default:
                            std::cout << "Opción no válida.\n";
                            std::cout << "--------------------------------------" << std::endl;
                    }
                } while (opcionEstudiante != 6);
                break;
            }
            case 2: {
                int opcionCurso;
                do {
                    mostrarMenuCurso();
                    std::cin >> opcionCurso;
                    std::cout << std::endl;
                    std::cout << "--------------------------------------" << std::endl;
                    switch (opcionCurso) {
                        case 1:
                            std::cout << "Curso creado: Matemáticas\n";
                            break;
                        case 2: {
                            std::string nombre;
                            int legajo;
                            std::cout << "Nombre del estudiante: ";
                            std::cin >> nombre;
                            std::cout << "Legajo: ";
                            std::cin >> legajo;
                            estudiante = std::make_shared<Estudiante>(nombre, legajo);
                            curso.inscribirEstudiante(estudiante);
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 3: {
                            int legajo;
                            std::cout << "Legajo del estudiante a desinscribir: ";
                            std::cin >> legajo;
                            curso.desinscribirEstudiante(legajo);
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 4: {
                            int legajo;
                            std::cout << "Ingrese el legajo a buscar: ";
                            std::cin >> legajo;
                            if (curso.buscarEstudiante(legajo)) {
                                std::cout << "El estudiante está inscripto.\n";
                            } else {
                                std::cout << "El estudiante NO está inscripto.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 5:
                            std::cout << (curso.completo() ? "El curso está completo.\n" : "Aún hay vacantes.\n");
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        case 6:
                            curso.imprimirEstudiantes();
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        case 7:
                            copiaShallow = new Curso(curso);
                            std::cout << "Se ha creado una copia superficial del curso.\n";
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        case 8:
                            std::cout << "Comparando copias:\n";
                            std::cout << "Original: \n";
                            curso.imprimirEstudiantes();
                            std::cout << std::endl;
                            std::cout << "Shallow Copy: \n";
                            if (copiaShallow) copiaShallow->imprimirEstudiantes();
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        case 9:
                            break;
                        default:
                            std::cout << "Opción no válida.\n";
                            std::cout << "--------------------------------------" << std::endl;
                    }
                } while (opcionCurso != 9);
                break;
            }
            case 3:
                std::cout << "Saliendo...\n";
                std::cout << "--------------------------------------" << std::endl;
                break;
            default:
                std::cout << "Opción no válida.\n";
                std::cout << "--------------------------------------" << std::endl;
        }
    } while (opcionPrincipal != 3);

    delete copiaShallow;
    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "\n--- MENU PRINCIPAL ---\n";
    std::cout << "1. Comprobar clase Estudiante\n";
    std::cout << "2. Comprobar clase Curso\n";
    std::cout << "3. Salir\n";
    std::cout << std::endl;
    std::cout << "Seleccione una opción: ";
}

void mostrarMenuEstudiante() {
    std::cout << "\n--- MENU ESTUDIANTE ---\n";
    std::cout << "1. Crear estudiante\n";
    std::cout << "2. Mostrar datos del estudiante\n";
    std::cout << "3. Agregar nota\n";
    std::cout << "4. Eliminar nota\n";
    std::cout << "5. Mostrar promedio\n";
    std::cout << "6. Volver\n";
    std::cout << std::endl;
    std::cout << "Seleccione una opción: ";
}

void mostrarMenuCurso() {
    std::cout << "\n--- MENU CURSO ---\n";
    std::cout << "1. Crear curso\n";
    std::cout << "2. Inscribir estudiante\n";
    std::cout << "3. Desinscribir estudiante\n";
    std::cout << "4. Buscar estudiante por legajo\n";
    std::cout << "5. Verificar si el curso está completo\n";
    std::cout << "6. Mostrar estudiantes ordenados\n";
    std::cout << "7. Copiar curso (shallow copy)\n";
    std::cout << "8. Comparar copias (prueba de independencia)\n";
    std::cout << "9. Volver\n";
    std::cout << std::endl;
    std::cout << "Seleccione una opción: ";
}
