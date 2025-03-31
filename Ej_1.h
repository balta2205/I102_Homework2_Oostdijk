#ifndef Ej1_H
#define Ej1_H

#include <iostream>
#include <iomanip>



class Tiempo {
private:
    int horas;
    int minutos;
    int segundos;
    std::string periodo;

public:
    // Constructores
    Tiempo();  
    Tiempo(int h);
    Tiempo(int h, int m);
    Tiempo(int h, int m, int s);
    Tiempo(int h, int m, int s, std::string p);

    // Métodos setters (validan antes de asignar)
    void setHora(int h);
    void setMinuto(int m);
    void setSegundo(int s);
    void setPeriodo(std::string p);

    // Métodos getters
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;
    std::string getPeriodo() const;

    void mostrar() const;
};

#endif