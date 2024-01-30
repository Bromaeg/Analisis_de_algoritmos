/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Harumi Cristal Manzano Yañez - A01751568 - ITESM
Evidencia 2: Actividad Integradora 2
30/01/24

Problema 1 (Cobertura Maxima): Algoritmo de Kruskal para el arbol de expansión minima.
Problema 2 (Publicidad y Contratacion): Travelling Salesman Problem utilizando Branch & Bound.
Problema 3 (Maximo Servicio Que Se Puede Ofrecer): Algoritmo de Flujo Maximo utilizando Dinitz.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

// Estructura para representar arista.
struct Edge
{
    int source, destination, weight;

    // Sobrecarga del operador para ordenar las aristas por peso.
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

/*
Funcion para encontrar el conjunto representante de un elemento.
Complejidad: O(log n) en el caso promedio.
*/
int findSet(int i, vector<int> &parent)
{
    if (i != parent[i])
    {
        parent[i] = findSet(parent[i], parent);
    }
    return parent[i];
}

/*
Funcion para unir dos conjuntos.
Complejidad: O(log n) debido a la operacion findSet.
*/
void unionSet(int x, int y, vector<int> &parent, vector<int> &rank)
{
    x = findSet(x, parent);
    y = findSet(y, parent);
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
}

// Funcion recursiva para el TSP utilizando Branch & Bound
void tsp(int current, int n, vector<vector<int>> &adj, vector<bool> &visited, int count, int cost, int &ans, vector<int> &path, vector<int> &best_path)
{
    if (count == n && adj[current][0] > 0)
    {
        ans = min(ans, cost + adj[current][0]);
        if (ans == cost + adj[current][0])
        {

            // Añadir el inicio al final para completar el ciclo
            best_path = path;
            best_path.push_back(0);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && adj[current][i] > 0)
        {
            visited[i] = true;
            path.push_back(i);
            tsp(i, n, adj, visited, count + 1, cost + adj[current][i], ans, path, best_path);
            visited[i] = false;
            path.pop_back();
        }
    }
}

// Funcion para llamar al TSP
void problema2(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);

    // Empezar en el nodo 0
    visited[0] = true;
    int ans = INT_MAX;
    vector<int> path, best_path;
    path.push_back(0);

    tsp(0, n, adj, visited, 1, 0, ans, path, best_path);

    cout << "-------------------------------------" << endl;
    cout << "Problem 2" << endl;
    if (ans == INT_MAX)
    {
        cout << "There is no possible route." << endl;
    }
    else
    {
        cout << "Minimum cost: " << ans << endl;
        cout << "Path: ";
        for (int node : best_path)
        {
            cout << node << " ";
        }
        cout << endl;
    }
}

// Función DFS para el algoritmo de Dinitz
int dfs(int u, int flow, int end, vector<int> &ptr, vector<vector<int>> &flowMatrix, vector<int> &level, vector<vector<int>> &capacity)
{
    if (u == end)
    {
        return flow;
    }
    for (int &i = ptr[u]; i < capacity[u].size(); ++i)
    {
        int v = i;
        if (level[u] + 1 == level[v] && capacity[u][v] - flowMatrix[u][v] > 0)
        {
            int minFlow = min(flow, capacity[u][v] - flowMatrix[u][v]);
            int result = dfs(v, minFlow, end, ptr, flowMatrix, level, capacity);
            if (result > 0)
            {
                flowMatrix[u][v] += result;
                flowMatrix[v][u] -= result;
                return result;
            }
        }
    }
    return 0;
}

// Funcion para el algoritmo de Dinitz
int dinitz(int start, int end, vector<vector<int>> &capacity)
{
    int n = capacity.size();
    vector<vector<int>> flow(n, vector<int>(n, 0));
    int maxFlow = 0;

    while (true)
    {
        vector<int> level(n, -1);
        level[start] = 0;
        queue<int> q;
        q.push(start);

        // BFS para construir el nivel de grafo
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v)
            {
                if (level[v] < 0 && capacity[u][v] - flow[u][v] > 0)
                {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        if (level[end] < 0)
        {
            break;
        }

        vector<int> ptr(n, 0);
        while (int pushed = dfs(start, INT_MAX, end, ptr, flow, level, capacity))
        {
            maxFlow += pushed;
        }
    }

    return maxFlow;
}

int main()
{
    int n, start, end;
    cin >> n >> start >> end;
    vector<vector<int>> adj(n, vector<int>(n));
    vector<Edge> edges;

    /*
    Leer la matriz de adyacencia y crear aristas.
    Complejidad: O(n^2) donde n es el número de vertices.
    */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
            if (adj[i][j] != -1 && i < j)
            {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }

    /*
    Implementacion del algoritmo de Kruskal para el arbol de expansion minima.
    Complejidad: O(E log E) donde E es el numero de aristas.
    */
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);
    iota(parent.begin(), parent.end(), 0);

    cout << "-------------------------------------" << endl;
    cout << "Problem 1" << endl;
    for (const auto &edge : edges)
    {
        int x = findSet(edge.source, parent);
        int y = findSet(edge.destination, parent);
        if (x != y)
        {
            cout << "(" << edge.source << ", " << edge.destination << ")" << endl;
            unionSet(x, y, parent, rank);
        }
    }

    // Problema 2
    problema2(adj);

    // Problema 3
    vector<vector<int>> capacity;

    // Leer la matriz de capacidades
    capacity.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> capacity[i][j];
        }
    }

    int maxFlow = dinitz(start, end, capacity);
    cout << "-------------------------------------" << endl;
    cout << "Problem 3" << endl;
    cout << "Maximum flow from " << start << " to " << end << " is " << maxFlow << endl;
    cout << "-------------------------------------" << endl;

    return 0;
}