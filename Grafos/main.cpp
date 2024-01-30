/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Grafos
Bicoloring (Problema B)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esBicolorable(const vector<vector<int>> &grafo)
{

    // -1 indica que no esta coloreado aún
    vector<int> color(grafo.size(), -1);
    queue<int> cola;
    for (int i = 0; i < grafo.size(); i++)
    {

        // Si el nodo aun no ha sido coloreado
        if (color[i] == -1)
        {
            color[i] = 0;
            cola.push(i);

            while (!cola.empty())
            {
                int actual = cola.front();
                cola.pop();

                for (int vecino : grafo[actual])
                {

                    // Si el vecino no esta coloreado
                    if (color[vecino] == -1)
                    {

                        // Coloreamos el vecino con el color opuesto al del nodo actual
                        color[vecino] = 1 - color[actual];
                        cola.push(vecino);
                    }
                    else if (color[vecino] == color[actual])
                    {

                        // Dos nodos adyacentes tienen el mismo color
                        return false;
                    }
                }
            }
        }
    }

    // Devuelve true si el grafo es bicolorable
    return true;
}

int main()
{
    int n, l, a, b;

    while (cin >> n && n != 0)
    {
        cin >> l;
        vector<vector<int>> grafo(n);

        for (int i = 0; i < l; i++)
        {
            cin >> a >> b;
            grafo[a].push_back(b);

            // Si el grafo no es dirigido
            grafo[b].push_back(a);
        }

        cout << (esBicolorable(grafo) ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
    return 0;
}
