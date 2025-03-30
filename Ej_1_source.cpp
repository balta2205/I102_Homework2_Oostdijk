#include "Ej_1.h"

// Constructores.

Tiempo::Tiempo() : horas(0), minutos(0), segundos(0) {} // Constructor por defecto.

Tiempo::Tiempo(int h){ // Constructor con un parámetro horas.
    setHora(h);
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}

Tiempo::Tiempo(int h, int m){ // Constructor con dos parámetros horas y minutos.
    setHora(h);
    setMinuto(m);
    segundos = 0;
    periodo = "a.m.";
}

Tiempo::Tiempo(int h, int m, int s){ // Constructor con tres parámetros horas, minutos y segundos.
    setHora(h);
    setMinuto(m);
    setSegundo(s);
    periodo = "a.m.";
}

Tiempo::Tiempo(int h, int m, int s, std::string p){ // Constructor con cuatro parámetros horas, minutos, segundos y periodo.
    setHora(h);
    setMinuto(m);
    setSegundo(s);
    setPeriodo(p);
}

// Métodos setters con validaciones.

void Tiempo::setHora(int h) { // Método para establecer la hora.
    if (h >= 1 && h <= 12) horas = h;
    else std::cerr << "Error: Hora inválida. Debe estar entre 1 y 12.\n";
}

void Tiempo::setMinuto(int m) { // Método para establecer el minuto.
    if (m >= 0 && m <= 59) minutos = m;
    else std::cerr << "Error: Minuto inválido. Debe estar entre 0 y 59.\n";
}

void Tiempo::setSegundo(int s) { // Método para establecer el segundo.
    if (s >= 0 && s <= 59) segundos = s;
    else std::cerr << "Error: Segundo inválido. Debe estar entre 0 y 59.\n";
}

void Tiempo::setPeriodo(std::string p) { // Método para establecer el periodo.
    if (p == "a.m." || p == "p.m.") periodo = p;
    else std::cerr << "Error: Período inválido. Debe ser 'a.m.' o 'p.m.'\n";
}

// Métodos getters.

int Tiempo::getHora() const { return horas; }
int Tiempo::getMinuto() const { return minutos; }
int Tiempo::getSegundo() const { return segundos; }
std::string Tiempo::getPeriodo() const { return periodo; }