#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isSubsetSum(const vector<int>& set, int sum) {
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(vector<int>& set) {
    int sum = 0;
    for (int num : set) {
        sum += num;
    }

    if (sum % 2 != 0) return false;

    return isSubsetSum(set, sum / 2);
}

int main() {
    int m;
    cin >> m;

    while (m--) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        vector<int> set;
        int weight;
        int n;
        iss >> n; // Leer el número de maletas

        // Leer todos los pesos en la línea
        for (int i = 0; i < n; i++) {
            iss >> weight;
            set.push_back(weight);
        }

        if (set.empty()) {
            cout << "NO" << endl; // Cambio para ajustar a la salida esperada
            continue;
        }

        // El primer elemento es el número de maletas, por lo que lo eliminamos
        set.erase(set.begin());

        // Llamada a la función canPartition y resultado
        if (canPartition(set)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
