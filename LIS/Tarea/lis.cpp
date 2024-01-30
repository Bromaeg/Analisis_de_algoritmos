/*
Miguel Angel Tena Garcia - A01709653 - ITESM
Algoritmo LDS Longest Decreasing Subsequence
Problema B: Testing the CATCHER
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Usamos en vez de Longest Increasing Subsequence (LIS) el Longest Decreasing Subsequence (LDS) que busca 
una subsecuencia donde cada elemento es menor o igual que el anterior ya que el CATCHER no puede 
interceptar un misil que esté a mayor altura que el último interceptado.
*/

int LIS(const vector<int>& missiles) {
    int n = missiles.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (missiles[j] >= missiles[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int height, test = 1;
    vector<int> missiles;

    while (true) {
        cin >> height;
        if (height == -1) {
            if (missiles.empty()) {
                break; // Final del input total
            } else {
                int result = LIS(missiles);
                if (test > 1) {
                    cout << "\n"; // Salto de línea entre los tests
                }
                cout << "Test #" << test++ << ":\n";
                cout << "  maximum possible interceptions: " << result << "\n";
                missiles.clear();
            }
        } else {
            missiles.push_back(height);
        }
    }
    return 0;
}
