#include "Ej_1.h"
#include "Ej_1_source.cpp"

void modificarTiempo(Tiempo &t1);
void cambioDeFormato(Tiempo &t1);

int main(){

    int n, h, m, s;
    Tiempo t1;

    std::cout << "Ejercicio 1" << std::endl;
    std::cout << "[1] Ingresar tiempo solo con horas" << std::endl;
    std::cout << "[2] Ingresar tiempo con horas y minutos" << std::endl; 
    std::cout << "[3] Ingresar tiempo con horas, minutos y segundos" << std::endl;
    std::cout << "[4] Ingresar tiempo con horas, minutos, segundos y periodo" << std::endl;\

    std::cin >> n;
    switch(n){
        case 1:
            do{
                std::cout << "Ingrese horas: ";
                std::cin >> h;
                t1.setHora(h);
            }while(h > 12 || h < 1);
            break; 
            
        case 2:
            do{
                std::cout << "Ingrese horas: ";
                std::cin >> h;
                t1.setHora(h);
            }while(h > 12 || h < 1);

            do{
                std::cout << "Ingrese minutos: ";
                std::cin >> m;
                t1.setMinuto(m);
            }while(m > 59 || m < 0);
            break;
        
        case 3:
            do{
                std::cout << "Ingrese horas: ";
                std::cin >> h;
                t1.setHora(h);
            }while(h > 12 || h < 1);

            do{
                std::cout << "Ingrese minutos: ";
                std::cin >> m;
                t1.setMinuto(m);
            }while(m > 59 || m < 0);

            do{
                std::cout << "Ingrese segundos: ";
                std::cin >> s;
                t1.setSegundo(s);
            }while(s > 59 || s < 0);
            break;

        case 4: 
            do{
                std::cout << "Ingrese horas: ";
                std::cin >> h;
                t1.setHora(h);
            }while(h > 12 || h < 1);

            do{
                std::cout << "Ingrese minutos: ";
                std::cin >> m;
                t1.setMinuto(m);
            }while(m > 59 || m < 0);

            do{
                std::cout << "Ingrese segundos: ";
                std::cin >> s;
                t1.setSegundo(s);
            }while(s > 59 || s < 0);
            
            do{
                std::cout << "Ingrese periodo: [1] a.m. [2] p.m." << std::endl;
                std::cin >> n;
                switch(n){
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
            }while(n != 1 && n != 2);
            break;
    }

    std::cout << "Que desea hacer ahora?" << std::endl;
    std::cout << "[1] Modificar valores." << std::endl;
    std::cout << "[2] Mostrar horas." << std::endl;
    std::cout << "[3] Mostrar minutos." << std::endl;
    std::cout << "[4] Mostrar segundos." << std::endl;
    std::cout << "[5] Mostrar periodo." << std::endl;
    std::cout << "[6] Mostrar todo." << std::endl;
    std::cout << "[7] Salir." << std::endl;
    int k; std::cin >> k; 

    switch(k){
        case 1:
            modificarTiempo(t1);
            break;
            
        case 2:
            std::cout << "La hora es: " << t1.getHora() << "hs" << std::endl;
            break;
        case 3:
            std::cout << "Los minutos son: " << t1.getMinuto() << "m" << std::endl;
            break;
        case 4:
            std::cout << "Los segundos son: " << t1.getSegundo() << "s" << std::endl;
            break;
        case 5:
            std::cout << "El periodo es: " << t1.getPeriodo() << std::endl;
            break;
        case 6:
            cambioDeFormato(t1);
            break;
        case 7:
            std::cout << "Saliendo..." << std::endl;
            return 0;
    }
}

void modificarTiempo(Tiempo &t1){
    int n, h, m, s;
    std::string p;
    
    do{
        std::cout << "Quiere modificar alguno de los valores? [1] Si [2] No" << std::endl;
        std::cin >> n;

        switch (n){
            case 1:
                std::cout << "Que desea modificar? [1] Hora [2] Minuto [3] Segundo [4] Periodo" << std::endl;
                int i; std::cin >> i;

                switch (i){
                    case 1:
                        std::cout << "Ingrese nueva hora: ";
                        std::cin >> h;
                        t1.setHora(h);
                        if (h > 12 || h < 1) return;
                        break;
                    case 2:
                        std::cout << "Ingrese nuevo minuto: ";
                        std::cin >> m;
                        t1.setMinuto(m);
                        if (m > 59 || m < 0) return;
                        break;
                    case 3:
                        std::cout << "Ingrese nuevo segundo: ";
                        std::cin >> s;
                        t1.setSegundo(s);
                        if (s > 59 || s < 0) return;
                        break;
                    case 4:
                        std::cout << "Ingrese nuevo periodo: [1] a.m. [2] p.m." << std::endl;
                        int j; std::cin >> j;
                        switch(j){
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
                }
                break;
            case 2:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                break;
        }
    }while (n == 1);
    return;
}

void cambioDeFormato(Tiempo &t1){

    std::cout << "Queres la hora en formato 12hs o 24hs? [1]12hs, [2]24hs" << std::endl;
    int l; std::cin >> l;

    if (l == 1){
        std::cout << "La hora es: ";
        t1.mostrar();
        std::cout << std::endl;
    }
    else if (l == 2){
        if (t1.getPeriodo() == "p.m." && t1.getHora() != 12) {
            std::cout << "La hora es: " << t1.getHora() + 12 << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
        }
        else if (t1.getPeriodo() == "p.m." && t1.getHora() == 12) {
            std::cout << "La hora es: " << 0 << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
        }
        else {
            std::cout << "La hora es: " << t1.getHora() << "hs, " << t1.getMinuto() << "m, " << t1.getSegundo() << "s" << std::endl;
        }
    }
    else{
        std::cout << "Opcion invalida" << std::endl;
    }
}