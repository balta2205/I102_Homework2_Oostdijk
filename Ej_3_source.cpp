#include "Ej_3.h"

// Implementación de Entero
Entero::Entero(int v) : valor(v) {}

std::unique_ptr<Numero> Entero::suma(const Numero& otro) const {
    return std::make_unique<Entero>(valor + dynamic_cast<const Entero&>(otro).valor);
}

std::unique_ptr<Numero> Entero::resta(const Numero& otro) const {
    return std::make_unique<Entero>(valor - dynamic_cast<const Entero&>(otro).valor);
}

std::unique_ptr<Numero> Entero::multiplicacion(const Numero& otro) const {
    return std::make_unique<Entero>(valor * dynamic_cast<const Entero&>(otro).valor);
}

std::string Entero::toString() const {
    return std::to_string(valor);
}

// Implementación de Real
Real::Real(double v) : valor(v) {}

std::unique_ptr<Numero> Real::suma(const Numero& otro) const {
    return std::make_unique<Real>(valor + dynamic_cast<const Real&>(otro).valor);
}

std::unique_ptr<Numero> Real::resta(const Numero& otro) const {
    return std::make_unique<Real>(valor - dynamic_cast<const Real&>(otro).valor);
}

std::unique_ptr<Numero> Real::multiplicacion(const Numero& otro) const {
    return std::make_unique<Real>(valor * dynamic_cast<const Real&>(otro).valor);
}

std::string Real::toString() const {
    return std::to_string(valor);
}

// Implementación de Complejo
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

std::unique_ptr<Numero> Complejo::suma(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return std::make_unique<Complejo>(real + c.real, imaginario + c.imaginario);
}

std::unique_ptr<Numero> Complejo::resta(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return std::make_unique<Complejo>(real - c.real, imaginario - c.imaginario);
}

std::unique_ptr<Numero> Complejo::multiplicacion(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return std::make_unique<Complejo>(
        real * c.real - imaginario * c.imaginario, 
        real * c.imaginario + imaginario * c.real
    );
}

std::string Complejo::toString() const {
    std::ostringstream oss;
    oss << real << " + " << imaginario << "i";
    return oss.str();
}
