#include "Ej_3.h"

// Implementación de Entero
Entero::Entero(int v) : valor(v) {}

std::unique_ptr<Numero> Entero::suma(const Numero& otro) const {
    if (const Entero* e = dynamic_cast<const Entero*>(&otro)) {
        return std::make_unique<Entero>(valor + e->valor);
    }
    throw std::invalid_argument("Suma incompatible");
}

std::unique_ptr<Numero> Entero::resta(const Numero& otro) const {
    if (const Entero* e = dynamic_cast<const Entero*>(&otro)) {
        return std::make_unique<Entero>(valor - e->valor);
    }
    throw std::invalid_argument("Resta incompatible");
}

std::unique_ptr<Numero> Entero::multiplicacion(const Numero& otro) const {
    if (const Entero* e = dynamic_cast<const Entero*>(&otro)) {
        return std::make_unique<Entero>(valor * e->valor);
    }
    throw std::invalid_argument("Multiplicacion incompatible");
}

std::string Entero::toString() const {
    return std::to_string(valor);
}

// Implementación de Real
Real::Real(double v) : valor(v) {}

std::unique_ptr<Numero> Real::suma(const Numero& otro) const {
    if (const Real* r = dynamic_cast<const Real*>(&otro)) {
        return std::make_unique<Real>(valor + r->valor);
    }
    throw std::invalid_argument("Suma incompatible");
}

std::unique_ptr<Numero> Real::resta(const Numero& otro) const {
    if (const Real* r = dynamic_cast<const Real*>(&otro)) {
        return std::make_unique<Real>(valor - r->valor);
    }
    throw std::invalid_argument("Resta incompatible");
}

std::unique_ptr<Numero> Real::multiplicacion(const Numero& otro) const {
    if (const Real* r = dynamic_cast<const Real*>(&otro)) {
        return std::make_unique<Real>(valor * r->valor);
    }
    throw std::invalid_argument("Multiplicacion incompatible");
}

std::string Real::toString() const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << valor;
    return oss.str();
}

// Implementación de Complejo
Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

std::unique_ptr<Numero> Complejo::suma(const Numero& otro) const {
    if (const Complejo* c = dynamic_cast<const Complejo*>(&otro)) {
        return std::make_unique<Complejo>(real + c->real, imaginario + c->imaginario);
    }
    throw std::invalid_argument("Suma incompatible");
}

std::unique_ptr<Numero> Complejo::resta(const Numero& otro) const {
    if (const Complejo* c = dynamic_cast<const Complejo*>(&otro)) {
        return std::make_unique<Complejo>(real - c->real, imaginario - c->imaginario);
    }
    throw std::invalid_argument("Resta incompatible");
}

std::unique_ptr<Numero> Complejo::multiplicacion(const Numero& otro) const {
    if (const Complejo* c = dynamic_cast<const Complejo*>(&otro)) {
        return std::make_unique<Complejo>(
            real * c->real - imaginario * c->imaginario, 
            real * c->imaginario + imaginario * c->real
        );
    }
    throw std::invalid_argument("Multiplicacion incompatible");
}

std::string Complejo::toString() const {
    std::ostringstream oss;
    oss << real << " + " << imaginario << "i";
    return oss.str();
}
