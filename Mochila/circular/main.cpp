/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Algoritmo de la mochila y manejo de cadenas
Circular Sequence (Problema B)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findSeqMasPeq(string seq)
{

    // Se duplica la secuencia para simular circularidad
    string SeqDoble = seq + seq;

    // Inicializa secuencia min con la primera secuencia posible (la original)
    string minSeq = SeqDoble.substr(0, seq.size());

    // Generar todas las secuencias posibles
    for (size_t i = 1; i < seq.size(); ++i)
    {
        string SeqAct = SeqDoble.substr(i, seq.size());

        // Encontrar la secuencia minima lexicograficamente
        if (SeqAct < minSeq)
        {
            minSeq = SeqAct;
        }
    }

    return minSeq;
}

int main()
{
    int T;
    cin >> T;
    vector<string> results;

    // Para cada secuencia encontrar la minima para cada una
    for (int i = 0; i < T; ++i)
    {
        string seq;
        cin >> seq;
        results.push_back(findSeqMasPeq(seq));
    }

    // Imprimir resultados
    for (const string &result : results)
    {
        cout << result << endl;
    }

    return 0;
}
