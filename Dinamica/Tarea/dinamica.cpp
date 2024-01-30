/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Algoritmos Dinamicos
Let me count the ways (Problema B)
*/

#include <iostream>
#include <vector>

using namespace std;

// Definimos una funcion que nos devolvera el numero de maneras de producir el cambio.
long long countWays(const vector<int>& deno, int money) {
    vector<long long> ways(money + 1, 0);

     // Solo hay una manera de devolver 0 centavos (no devolviendo nada).
    ways[0] = 1;

    // Recorremos cada denominacion de moneda.
    for (int coin : deno) {

        // Actualizamos las maneras de devolver cada cantidad empezando desde el valor de la moneda.
        for (int j = coin; j <= money; j++) {
            ways[j] += ways[j - coin];
        }
    }

    // Devolvemos el numero de maneras de devolver la cantidad total.
    return ways[money];
}

int main() {

    // Las denominaciones de las monedas en centavos.
    vector<int> deno = {1, 5, 10, 25, 50}; 
    int n;

    // Leer dinero de la entrada.
    while (cin >> n) {
        long long m = countWays(deno, n);

        if (m == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        } else {
            cout << "There are " << m << " ways to produce " << n << " cents change." << endl;
        }
    }

    return 0;
}
