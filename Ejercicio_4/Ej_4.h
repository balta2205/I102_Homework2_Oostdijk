#ifndef EJ_4_H
#define EJ_4_H

#include <iostream>
#include <string>
using namespace std;

// Clase abstracta
class Cuenta {
protected:
    const string titularCuenta;
    double balance;

public:
    Cuenta(const string titular, double saldoInicial);
    virtual ~Cuenta() {}

    void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() = 0;
};

// Clase derivada: CajaDeAhorro
class CajaDeAhorro : public Cuenta {
private:
    int vecesMostradoInfo;

public:
    CajaDeAhorro(string titular, double saldoInicial);
    void retirar(double cantidad) override;
    void mostrarInfo() override;

    // Se necesita acceso para CuentaCorriente
    friend class CuentaCorriente; 
};

// Clase derivada: CuentaCorriente
class CuentaCorriente : public Cuenta {
private:
    CajaDeAhorro* cajaAsociada; // Puntero a caja asociada

public:
    CuentaCorriente(string titular, double saldoInicial);

    // Recibe CajaDeAhorro para intentar retiro si no hay saldo suficiente
    void retirar(double cantidad) override;
    void mostrarInfo() override;

    // Vincular CajaDeAhorro a CuentaCorriente, para poder acceder a su saldo
    void asociarCaja(CajaDeAhorro* caja);
};

#endif