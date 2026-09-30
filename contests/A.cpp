#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

// dp[s1][s2]: true si es posible que el miembro 1 tenga suma s1 y el miembro 2 tenga suma s2
// Usamos bitset para que sea ultra rápido y ocupe casi nada de memoria
bitset<505> dp[505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int A, B, C;
    if (!(cin >> n >> A >> B >> C)) return 0;

    vector<int> x(n);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        total_sum += x[i];
    }

    // Caso base: al inicio ambos tienen suma 0
    dp[0][0] = true;

    // Procesamos cada problema como en una mochila 0/1
    for (int val : x) {
        // Opción 1: Dárselo al miembro 1 (recorremos en reversa para no reusar el mismo elemento)
        for (int s1 = total_sum - val; s1 >= 0; s1--) {
            dp[s1 + val] |= dp[s1];
        }
        // Opción 2: Dárselo al miembro 2 (desplazamos el bitset val posiciones)
        for (int s1 = 0; s1 <= total_sum; s1++) {
            dp[s1] |= (dp[s1] << val);
        }
        // Opción 3: Dárselo al miembro 3 (equivale a no cambiar ni s1 ni s2)
    }

    int ans = 1e9;

    // Probamos todos los pares (s1, s2) alcanzables
    for (int s1 = 0; s1 <= total_sum; s1++) {
        for (int s2 = 0; s1 + s2 <= total_sum; s2++) {
            if (dp[s1][s2]) {
                int s3 = total_sum - s1 - s2;

                // Tiempo redondeado hacia arriba para cada miembro:
                int time1 = (s1 + A - 1) / A;
                int time2 = (s2 + B - 1) / B;
                int time3 = (s3 + C - 1) / C;

                int current_time = max({time1, time2, time3});
                ans = min(ans, current_time);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}