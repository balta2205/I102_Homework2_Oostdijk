#include "Ej_2.h"

int main() {
    Curso curso("Matemáticas");
    Curso* copiaShallow = nullptr;
    Curso copiaDeep("Temp");
    std::shared_ptr<Estudiante> estudiante = nullptr;
    std::vector<std::shared_ptr<Estudiante>> lista_estudiantes;
    
    int opcionPrincipal;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcionPrincipal;
        std::cout << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        
        switch (opcionPrincipal) {
            case 1: {
                int opcionEstudiante = 0;
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
                            lista_estudiantes.push_back(estudiante);
                            std::cout << "Estudiante creado: " << *estudiante << "\n";
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 2: {
                            if (lista_estudiantes.size() > 0) {
                                for(const auto& est : lista_estudiantes) {
                                    std::cout << *est << "\n";
                                }
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 3: {
                            if (lista_estudiantes.size() > 0) {

                                std::cout << "A que estudiante desea agregar un curso y nota?\n";
                                int h = 1;
                                for (const auto& est : lista_estudiantes) {
                                    std::cout << "[" << h << "] " << *est << "\n";
                                    h++;
                                }
                                std::cout << "Seleccione el número del estudiante: ";
                                size_t num_estudiante;
                                std::cin >> num_estudiante;
                                if (num_estudiante < 1 || num_estudiante > lista_estudiantes.size()) {
                                    std::cout << "Número de estudiante no válido.\n";
                                    break;
                                }
                                estudiante = lista_estudiantes[num_estudiante - 1];
                                std::cout << "Estudiante seleccionado: " << *estudiante << "\n" << std::endl;
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
                            if (lista_estudiantes.size() > 0) {

                                std::cout << "A que estudiante desea eliminar un curso y su nota?\n";
                                int h = 1;
                                for (const auto& est : lista_estudiantes) {
                                    std::cout << "[" << h << "] " << *est << "\n";
                                    h++;
                                }
                                std::cout << "\nSeleccione el número del estudiante: ";
                                size_t num_estudiante;
                                std::cin >> num_estudiante;
                                if (num_estudiante < 1 || num_estudiante > lista_estudiantes.size()) {
                                    std::cout << "Número de estudiante no válido.\n";
                                    break;
                                }
                                if (lista_estudiantes[num_estudiante - 1]->getCursosNotas().empty()) {
                                    std::cout << "El estudiante no tiene cursos para eliminar.\n";
                                    std::cout << "\n--------------------------------------";
                                    break;
                                }
                                estudiante = lista_estudiantes[num_estudiante - 1];
                                std::cout << "Estudiante seleccionado: " << *estudiante << "\n" << std::endl;
                                std::cout << "Los cursos y notas son: ";
                                for(const auto& cursoNota : estudiante->getCursosNotas()) {
                                    std::cout << cursoNota.first << " - "; 
                                }
                                std::string curso;
                                std::cout << "\nIngrese el curso a eliminar: ";
                                std::cin >> curso;
                                estudiante->eliminarCursoNota(curso);
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 5: {
                            if (lista_estudiantes.size() > 0) {

                                std::cout << "A que estudiante desea agregar calcularle el promedio?\n";
                                int h = 1;
                                for (const auto& est : lista_estudiantes) {
                                    std::cout << "[" << h << "] " << *est << "\n";
                                    h++;
                                }
                                std::cout << "Seleccione el número del estudiante: ";
                                size_t num_estudiante;
                                std::cin >> num_estudiante;
                                if (num_estudiante < 1 || num_estudiante > lista_estudiantes.size()) {
                                    std::cout << "Número de estudiante no válido.\n";
                                    break;
                                }
                                estudiante = lista_estudiantes[num_estudiante - 1];
                                std::cout << "\nEstudiante seleccionado: " << *estudiante << "\n";
                                std::cout << "Promedio: " << estudiante->getPromedio() << "\n";
                            } else {
                                std::cout << "Debe crear un estudiante primero.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 6: {
                            break;
                        }
                        default:{
                            std::cout << "Opción no válida.\n";
                            std::cout << "--------------------------------------" << std::endl;
                        }
                    }
                } while (opcionEstudiante != 6);
                break;
            }
            case 2: {
                int opcionCurso = 0;
                do {
                    mostrarMenuCurso();
                    std::cin >> opcionCurso;
                    std::cout << std::endl;
                    std::cout << "--------------------------------------" << std::endl;
                    switch (opcionCurso) {
                        case 1:{
                            std::cout << "Curso creado: Matemáticas\n";
                            break;
                        }
                        case 2: {
                            std::string nombre;
                            int h = 0;
                            size_t num_estudiante;

                            for(const auto& est : lista_estudiantes) {
                                std::cout << "[" << h << "] " << *est << "\n";
                                h++;
                            }
                            std::cout << "Seleccione el número del estudiante a inscribir: ";
                            std::cin >> num_estudiante;
                            if (num_estudiante < 1 || num_estudiante >= lista_estudiantes.size()) {
                                std::cout << "Número de estudiante no válido.\n";
                                break;
                            }
                            estudiante = lista_estudiantes[num_estudiante];
                            std::cout << "Estudiante seleccionado: " << *estudiante << "\n" << std::endl;
                            curso.inscribirEstudiante(estudiante);
                            std::cout << "El estudiante " << estudiante->getNombre() << " con legajo " << estudiante->getLegajo() << " ha sido inscripto en el curso.\n";
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 3: {
                            int  h = 0;
                            size_t num_estudiante;

                            for(const auto& est : lista_estudiantes) {
                                std::cout << "[" << h << "] " << *est << "\n";
                                h++;
                            }
                            std::cout << "Seleccione el número del estudiante a inscribir: ";
                            std::cin >> num_estudiante;
                            if (num_estudiante < 1 || num_estudiante >= lista_estudiantes.size()) {
                                std::cout << "Número de estudiante no válido.\n";
                                break;
                            }
                            estudiante = lista_estudiantes[num_estudiante];
                            std::cout << "Estudiante seleccionado: " << *estudiante << "\n" << std::endl;
                            curso.desinscribirEstudiante(estudiante->getLegajo());
                            std::cout << "El estudiante " << estudiante->getNombre() << " con legajo " << estudiante->getLegajo() << " ha sido desinscripto del curso.\n";
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
                        case 5:{
                            std::cout << (curso.completo() ? "El curso está completo.\n" : "Aún hay vacantes.\n");
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 6:{
                            curso.imprimirEstudiantes();
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 7:{
                            if (copiaShallow) delete copiaShallow;
                            copiaShallow = new Curso(curso);
                            std::cout << "Se ha creado una copia superficial del curso.\n";
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 8:{
                            std::cout << "Comparando copias:\n";
                            std::cout << "Original: \n";
                            curso.imprimirEstudiantes();
                            std::cout << std::endl;
                            std::cout << "Shallow Copy: \n";
                            if (copiaShallow) {
                                std::cout << "Shallow Copy: \n";
                                copiaShallow->imprimirEstudiantes();
                            } else {
                                std::cout << "No hay copia creada.\n";
                            }
                            std::cout << "--------------------------------------" << std::endl;
                            break;
                        }
                        case 9:{
                            break;
                        }
                        default:{
                            std::cout << "Opción no válida.\n";
                            std::cout << "--------------------------------------" << std::endl;
                        }
                    }
                } while (opcionCurso != 9);
                break;
            }
            case 3:{
                std::cout << "Saliendo...\n";
                std::cout << "--------------------------------------" << std::endl;
                break;
            }
            default:{
                std::cout << "Opción no válida.\n";
                std::cout << "--------------------------------------" << std::endl;
            }
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
