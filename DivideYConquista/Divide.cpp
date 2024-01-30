/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Divide y conquista
Problema D: Suma Exacta 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funcion 'findBooks' para encontrar dos libros cuyos precios sumen la cantidad de dinero disponible.
void findBooks(vector<int>& prices, int money) {

    // Ordena los precios de los libros en orden ascendente.
    sort(prices.begin(), prices.end());

    // Inicializa indices para la busqueda: 'i' al inicio y 'j' al final del vector.
    int i = 0, j = prices.size() - 1;
    int book1 = 0, book2 = 0;

    // Mientras 'i' sea menor que 'j', sigue buscando.
    while (i < j) {

        // Calcula la suma de los precios en los indices 'i' y 'j'.
        int sum = prices[i] + prices[j];

        // Si la suma es igual al dinero disponible, guarda los precios y ajusta los indices.
        if (sum == money) {
            book1 = prices[i];
            book2 = prices[j];
            i++;
            j--;
        } 

        // Si la suma es menor que el dinero, aumenta 'i' para considerar un libro mas caro.
        else if (sum < money) {
            i++;
        } 

        // Si la suma es mayor que el dinero, disminuye 'j' para considerar un libro mas barato.
        else {
            j--;
        }
    }

    // Imprime los precios de los libros
    cout << "Peter should buy books whose prices are " << book1 << " and " << book2 << "." << endl;
}

int main() {

    // 'N' para el numero de libros, 'M' para el dinero disponible.
    int N, M; 

    // Lee casos de prueba hasta que se acaben los datos de entrada.
    while (cin >> N) {

        vector<int> prices(N); 

        // Precios de los libros.
        for (int i = 0; i < N; i++) {
            cin >> prices[i];
        }

        // Cantidad de dinero disponible.
        cin >> M;

        // Llama a la funcion
        findBooks(prices, M);

        cout << endl;
    }
    return 0; 
}

