/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Actividad Integradora 1
16/01/24

Algoritmo KMP para la busqueda de codigos maliciosos (Parte 1)
Algoritmo de Manacher para la búsqueda de los palindromos (Parte 2)
Algoritmo de la subcadena comun mas larga (LCS) (Parte 3)

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



/*
Creacion de la tabla de fallos KMP
Esta funcion genera la tabla de fallos para el algoritmo de KMP,
la usamos para determinar cuantos caracteres se pueden saltar en el texto
*/
vector<int> KMP_table(const string &pattern) {
    vector<int> table(pattern.length(), 0);
    int j = 0;
    for (int i = 1; i < pattern.length(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        table[i] = j;
    }
    return table;
}

/*
Busqueda de KMP en el texto
Esta funcion busca el patron en el texto usando la tabla de fallos
*/ 
void KMP_search(const string &text, const string &pattern, const string &pattern_name) {
    vector<int> table = KMP_table(pattern);
    int j = 0;
    bool found = false;

    // Busqueda del patron en el texto
    for (int i = 0; i < text.length(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
            if (j == pattern.length()) {
                cout << pattern_name << " - true, start at position " << (i - j + 1) << endl;
                found = true;

                // Continua la busqueda del patron en el texto
                j = table[j - 1];  
            }
        }
    }

    // Si no se encontró el patron en el texto arroja false
    if (!found) {
        cout << pattern_name << " - false" << endl;
    }
}

/*
Funciones para el algoritmo de Manacher
Esta funcion se utiliza para encontrar palindromos en una cadena
Expande la cadena alrededor de un centro dado y verifica si es un palindromo
*/ 
string expandAroundCenter(const string &s, int c1, int c2)
{

    // Funcion para expandir el centro de la cadena
    int l = c1, r = c2;
    int n = s.length();
    while (l >= 0 && r < n && s[l] == s[r])
    {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

// Funcion que encuentra el substring palindromo mas largo en una cadena
string longestPalindromicSubstring(const string &s)
{

    int n = s.length();
    if (n == 0)
        return "";
    string longest = s.substr(0, 1);

    for (int i = 0; i < n - 1; i++)
    {
        string p1 = expandAroundCenter(s, i, i);
        if (p1.length() > longest.length())
        {
            longest = p1;
        }
        string p2 = expandAroundCenter(s, i, i + 1);
        if (p2.length() > longest.length())
        {
            longest = p2;
        }
    }
    return longest;
}

// Funcion que imprime el palindromo mas largo encontrado en una cadena
void findAndPrintLongestPalindrome(const string &text, const string &title) {
    string longestPalindrome = longestPalindromicSubstring(text);
    size_t start = text.find(longestPalindrome);
    
    // Imprime el palindromo más largo y su posición segun el formato 
    cout << title << "\nmirrored code found, start at "
         << start << ", ended at "
         << start + longestPalindrome.length() << endl; 
}

// Funcion calcula la longitud de la subcadena comun mas larga (LCS)
int longestCommonSubstring(const string &A, const string &B)
{
    int m = A.length();
    int n = B.length();
    vector<vector<int>> M(m + 1, vector<int>(n + 1));
    int maximum = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                M[i][j] = 0;
            else if (A[i - 1] == B[j - 1])
            {
                M[i][j] = 1 + M[i - 1][j - 1];
                maximum = max(maximum, M[i][j]);
            }
            else
                M[i][j] = 0;
        }
    }
    return maximum;
}

// Funcion para leer el contenido de los archivos.
string read_file(const string &filename)
{
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    return content;
}


int main()
{
    
    // Carga de archivos de transmision, codigos maliciosos y ejecucion de las funciones
    string transmission1 = read_file("transmission1.txt");
    string transmission2 = read_file("transmission2.txt");
    string mcode1 = read_file("mcode1.txt");
    string mcode2 = read_file("mcode2.txt");
    string mcode3 = read_file("mcode3.txt");

    // Parte 1: Busqueda de codigos maliciosos en transmisiones
    cout << "transmission1.txt:" << endl;
    KMP_search(transmission1, mcode1, "mcode1.txt");
    KMP_search(transmission1, mcode2, "mcode2.txt");
    KMP_search(transmission1, mcode3, "mcode3.txt");
    cout << endl;

    cout << "transmission2.txt:" << endl;
    KMP_search(transmission2, mcode1, "mcode1.txt");
    KMP_search(transmission2, mcode2, "mcode2.txt");
    KMP_search(transmission2, mcode3, "mcode3.txt");
    cout << endl;

    // Parte 2: Busqueda de palindromos en las transmisiones
    findAndPrintLongestPalindrome(transmission1, "transmission1.txt:");
    cout << endl;
    findAndPrintLongestPalindrome(transmission2, "transmission2.txt:");
    cout << endl;

    // Parte 3: Longitud de la subcadena comun mas larga
    int lcsLength = longestCommonSubstring(transmission1, transmission2);
    cout << "The longest common substring between transmission1.txt and transmission2.txt is "
         << lcsLength << " characters long" << endl;

    return 0;
}
