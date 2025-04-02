#ifndef NUMERO_H
#define NUMERO_H

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

class Numero {
public:
    virtual ~Numero() = default;
    virtual std::unique_ptr<Numero> suma(const Numero& otro) const = 0;
    virtual std::unique_ptr<Numero> resta(const Numero& otro) const = 0;
    virtual std::unique_ptr<Numero> multiplicacion(const Numero& otro) const = 0;
    virtual std::string toString() const = 0;
};

class Entero : public Numero {
private:
    int valor;

public:
    Entero(int v);
    std::unique_ptr<Numero> suma(const Numero& otro) const override;
    std::unique_ptr<Numero> resta(const Numero& otro) const override;
    std::unique_ptr<Numero> multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

class Real : public Numero {
private:
    double valor;

public:
    Real(double v);
    std::unique_ptr<Numero> suma(const Numero& otro) const override;
    std::unique_ptr<Numero> resta(const Numero& otro) const override;
    std::unique_ptr<Numero> multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

class Complejo : public Numero {
private:
    double real, imaginario;

public:
    Complejo(double r, double i);
    std::unique_ptr<Numero> suma(const Numero& otro) const override;
    std::unique_ptr<Numero> resta(const Numero& otro) const override;
    std::unique_ptr<Numero> multiplicacion(const Numero& otro) const override;
    std::string toString() const override;
};

void probarOperaciones(const Numero& a, const Numero& b);

#endif // NUMERO_H
