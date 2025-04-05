#include "Ej_4.h"

using namespace std;

int main() {
    cout << "=== Creando cuentas ===" << endl;
    CajaDeAhorro ahorro("Baltasar", 300);
    CuentaCorriente corriente("Baltasar", 100);
    corriente.asociarCaja(&ahorro);
    cout << "=== Cuentas creadas ===" << endl;
    cout << "Caja de Ahorro: Titular: Baltasar, Balance: 300" << endl;
    cout << "Cuenta Corriente: Titular: Baltasar, Balance: 100" << endl;

    cout << "\n=== DEPOSITAR DINERO ===" << endl;
    ahorro.depositar(200);       // Debería quedar con 500.
    corriente.depositar(150);    // Debería quedar con 250.

    cout << "\n=== MOSTRAR INFORMACIÓN (CajaDeAhorro) ===" << endl;
    ahorro.mostrarInfo();  // 1° vez — no descuenta.
    cout << endl;
    ahorro.mostrarInfo();  // 2° vez — no descuenta.
    cout << endl;
    ahorro.mostrarInfo();  // 3° vez — descuenta $20.
    ahorro.mostrarInfo();  // 4° vez — descuenta $20.
    ahorro.mostrarInfo();  // 5° vez — descuenta $20.

    cout << "=== MOSTRAR INFORMACIÓN (CuentaCorriente) ===" << endl;
    corriente.mostrarInfo();

    cout << "=== RETIRAR DINERO DESDE CajaDeAhorro ===" << endl;
    ahorro.retirar(100);         // Válido.
    ahorro.retirar(1000);        // Inválido: más que balance.

    cout << "\n=== RETIRAR DESDE CuentaCorriente ===" << endl;
    
    cout << "Caso 1: suficiente en CuentaCorriente" << endl;
    corriente.retirar(100);  // Tiene 250 → OK.

    cout << "Caso 2: insuficiente en CuentaCorriente, pero cubierto por CajaDeAhorro"<< endl;
    corriente.retirar(300);  // Tiene 150 restante → pide 150 extra de ahorro.

    // Mostrar balances actualizados.
    cout << "=== INFO POST-RETIROS ===" << endl;
    corriente.mostrarInfo();
    ahorro.mostrarInfo();

    cout << "Caso 3: insuficiente en ambas cuentas" << endl;
    corriente.retirar(1000);  // No hay plata suficiente en ninguna.

    cout << "=== ESTADO FINAL DE CUENTAS ===" << endl;
    corriente.mostrarInfo();
    ahorro.mostrarInfo();

    return 0;
}
