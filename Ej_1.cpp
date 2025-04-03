#include "Ej_1.h"

int main(){
    int n, h, m, s;
    Tiempo t1;

    std::cout << "Ejercicio 1" << std::endl;
    std::cout << "[1] Ingresar tiempo solo con horas" << std::endl;
    std::cout << "[2] Ingresar tiempo con horas y minutos" << std::endl; 
    std::cout << "[3] Ingresar tiempo con horas, minutos y segundos" << std::endl;
    std::cout << "[4] Ingresar tiempo con horas, minutos, segundos y periodo" << std::endl;\

    do{ //Repetir hasta que el usuario ingrese un valor correcto.
        std::cout << "Que desea hacer? [1] [2] [3] [4]" << std::endl;     
        std::cin >> n;
        switch(n){
            case 1: // Solo horas.
                do{
                    std::cout << "Ingrese horas (entre 1 y 12): ";
                    std::cin >> h;
                    t1.setHora(h);
                }while(h > 12 || h < 1);
                break; 
                
            case 2: // Solo horas y minutos.
                do{
                    std::cout << "Ingrese horas (entre 1 y 12): ";
                    std::cin >> h;
                    t1.setHora(h);
                }while(h > 12 || h < 1);

                do{
                    std::cout << "Ingrese minutos (entre 0 y 59): ";
                    std::cin >> m;
                    t1.setMinuto(m);
                }while(m > 59 || m < 0);
                break;
            
            case 3: // Solo horas, minutos y segundos.
                do{
                    std::cout << "Ingrese horas (entre 1 y 12): ";
                    std::cin >> h;
                    t1.setHora(h);
                }while(h > 12 || h < 1);

                do{
                    std::cout << "Ingrese minutos (entre 0 y 59): ";
                    std::cin >> m;
                    t1.setMinuto(m);
                }while(m > 59 || m < 0);

                do{
                    std::cout << "Ingrese segundos (entre 0 y 59): ";
                    std::cin >> s;
                    t1.setSegundo(s);
                }while(s > 59 || s < 0);
                break;

            case 4: // Solo horas, minutos, segundos y periodo.
                do{
                    std::cout << "Ingrese horas (entre 1 y 12): ";
                    std::cin >> h;
                    t1.setHora(h);
                }while(h > 12 || h < 1);

                do{
                    std::cout << "Ingrese minutos (entre 0 y 59): ";
                    std::cin >> m;
                    t1.setMinuto(m);
                }while(m > 59 || m < 0);

                do{
                    std::cout << "Ingrese segundos (entre 0 y 59): ";
                    std::cin >> s;
                    t1.setSegundo(s);
                }while(s > 59 || s < 0);
                
                int o;
                do{
                    std::cout << "Ingrese periodo: [1] a.m. [2] p.m." << std::endl;
                    std::cin >> o; 
                    switch(o){
                        case 1:
                            t1.setPeriodo("a.m.");
                            break;
                        case 2:
                            t1.setPeriodo("p.m.");
                            break;
                        default:
                            std::cout << "Opcion invalida" << std::endl;
                            break;
                    }
                }while(o != 1 && o != 2);
                break;
            default: // Input fuera de rango aceptado.
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    }while(n < 1 || n > 4);

    interfazAcciones(t1); // Una vez ingresada la hora, se llama a la funcion para mostrar el menu de acciones.
}

void interfazAcciones(Tiempo &t1){
    int k;
    do{
        std::cout << "" << std::endl;
        std::cout << "Que desea hacer ahora?" << std::endl;
        std::cout << "[1] Modificar valores." << std::endl;
        std::cout << "[2] Mostrar horas." << std::endl;
        std::cout << "[3] Mostrar minutos." << std::endl;
        std::cout << "[4] Mostrar segundos." << std::endl;
        std::cout << "[5] Mostrar periodo." << std::endl;
        std::cout << "[6] Mostrar todo." << std::endl;
        std::cout << "[7] Salir." << std::endl;
        std::cin >> k; 

        switch(k){
            case 1: // Modificar valores.
                modificarTiempo(t1);
                break;   
            case 2: // Mostrar horas.
                std::cout << "La hora es: " << t1.getHora() << "hs" << std::endl;
                break;
            case 3: // Mostrar minutos.
                std::cout << "Los minutos son: " << t1.getMinuto() << "m" << std::endl;
                break;
            case 4: // Mostrar segundos.
                std::cout << "Los segundos son: " << t1.getSegundo() << "s" << std::endl;
                break;
            case 5: // Mostrar periodo.
                std::cout << "El periodo es: " << t1.getPeriodo() << std::endl;
                break;
            case 6: // Mostrar todo, llama a cambioDeFormato() para elegir entre formato 12hs o 24hs.
                cambioDeFormato(t1);
                break;
            case 7: // Salir.
                std::cout << "Saliendo..." << std::endl;
                return;
            default: // Input fuera de rango aceptado.
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    }while(k != 7);
}

void modificarTiempo(Tiempo &t1){
    int n, h, m, s;
    std::string p;
    
    do{
        std::cout << "Quiere modificar alguno de los valores? [1] Si [2] No" << std::endl;
        std::cin >> n;

        switch (n){
            case 1: // El usuario quiere modifiar valores.
                std::cout << "Que desea modificar? [1] Hora [2] Minuto [3] Segundo [4] Periodo" << std::endl;
                int i; std::cin >> i;
                do{
                    switch (i){
                        case 1: // Modificar hora.
                            std::cout << "Ingrese nueva hora: ";
                            std::cin >> h;
                            t1.setHora(h);
                            if (h > 12 || h < 1) return;
                            break;
                        case 2: // Modificar minuto. 
                            std::cout << "Ingrese nuevo minuto: ";
                            std::cin >> m;
                            t1.setMinuto(m);
                            if (m > 59 || m < 0) return;
                            break;
                        case 3: // Modificar segundo.
                            std::cout << "Ingrese nuevo segundo: ";
                            std::cin >> s;
                            t1.setSegundo(s);
                            if (s > 59 || s < 0) return;
                            break;
                        case 4: // Modificar periodo.
                            std::cout << "Ingrese nuevo periodo: [1] a.m. [2] p.m." << std::endl;
                            int j; std::cin >> j;
                            do{
                                switch(j){
                                    case 1: // Modificar periodo a a.m.
                                        t1.setPeriodo("a.m.");
                                        break;
                                    case 2: // Modificar periodo a p.m.
                                        t1.setPeriodo("p.m.");
                                        break;
                                    default: // Opcion invalida.
                                        std::cout << "Opcion invalida" << std::endl;
                                        break;
                                }
                            }while(j != 1 && j != 2);
                    }
                }while(i != 1 && i != 2 && i != 3 && i != 4);
                break;
            case 2: // El usuario no quiere modificar valores.
                std::cout << "Saliendo..." << std::endl;
                break;
            default: // Input fuera de rango aceptado.
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    }while (n == 1);
    return;
}

void cambioDeFormato(Tiempo &t1){

    std::cout << "Queres la hora en formato 12hs o 24hs? [1]12hs, [2]24hs" << std::endl;
    int l; 
    do{
        std::cin >> l;

        if (l == 1){ // Formato 12hs.
            std::cout << "La hora es: ";
            t1.mostrar();
            std::cout << std::endl;
        }
        else if (l == 2){ // Formato 24hs.
            if (t1.getPeriodo() == "p.m." && t1.getHora() != 12) { // Si es p.m. y no es 12, sumamos 12 a la hora.
                std::cout << "La hora es: " << t1.getHora() + 12 << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
            }
            else if (t1.getPeriodo() == "a.m." && t1.getHora() == 12) { // Si es a.m. y es 12, la hora es 0.
                std::cout << "La hora es: " << 0 << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
            }
            else { // Si es a.m. y no es 12, la hora es la misma.
                std::cout << "La hora es: " << t1.getHora() << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
            }
        }
        else{ // Input fuera de rango aceptado.
            std::cout << "Opcion invalida" << std::endl;
        }
    }while(l != 1 && l != 2);
}