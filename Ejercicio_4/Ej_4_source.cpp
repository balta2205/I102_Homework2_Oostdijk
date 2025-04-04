#include "Ej_4.h"

// ================= Cuenta =================
Cuenta::Cuenta(const string titular, double saldoInicial) : titularCuenta(titular), balance(saldoInicial) {}

void Cuenta::depositar(double cantidad) {
    if (cantidad > 0) {
        balance += cantidad;
        cout << "Deposito de $" << cantidad << " realizado." << endl;
    } else {
        cout << "Cantidad invalida." << endl;
    }
}

// ================= CajaDeAhorro =================
CajaDeAhorro::CajaDeAhorro(const string titular, double saldoInicial) : Cuenta(titular, saldoInicial), vecesMostradoInfo(0) {}

void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
        cout << "Retiro de $" << cantidad << " realizado desde Caja de Ahorro." << endl;
    } else {
        cout << "Saldo insuficiente en Caja de Ahorro." << endl;
    }
}

void CajaDeAhorro::mostrarInfo() {
    cout << "Caja de Ahorro - Titular: " << titularCuenta << endl;
    cout << "Balance: $" << balance << endl;

    vecesMostradoInfo++;
    if (vecesMostradoInfo > 2) {
        balance -= 20;
        cout << "Se aplico un descuento de $20 por exceder vistas.\n" << endl;
    }
}

// ================= CuentaCorriente =================
CuentaCorriente::CuentaCorriente(const string titular, double saldoInicial) : Cuenta(titular, saldoInicial) {}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad <= balance) {
        balance -= cantidad;
        cout << "Retiro exitoso de $" << cantidad << " de Cuenta Corriente.\n" << endl;
    }else if (cajaAsociada && cajaAsociada->balance >= (cantidad - balance)) {
        double faltante = cantidad - balance;
        cajaAsociada->balance -= faltante;
        balance = 0;
        cout << "Cuenta Corriente no tenía suficiente, se usaron $" << faltante << " de la Caja de Ahorro asociada.\n" << endl;
    } else {
        cout << "Saldo insuficiente en ambas cuentas. \n" << endl;
    }
}


void CuentaCorriente::mostrarInfo() {
    cout << "Cuenta Corriente - Titular: " << titularCuenta << endl; 
    cout << "Balance: $" << balance << "\n" << endl;
}

void CuentaCorriente::asociarCaja(CajaDeAhorro* caja) {cajaAsociada = caja;}