// IA Genrated for educational purposes
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string X;
    cin >> X;

    int n = X.size();

    // Trabajamos de derecha a izquierda
    reverse(X.begin(), X.end());

    /*
        dp[carry][T] = mínimo T0 posible

        Después de procesar una posición conocemos:
            carry = carry que pasa a la siguiente posición
            T     = cantidad de billetes que llegan a esta posición

        En realidad T es pequeño, y los carries también.
    */

    const int C = 10;
    const int MAX_T = 100;

    vector<vector<ll>> dp(C + 1, vector<ll>(MAX_T + 1, INF));
    vector<vector<ll>> ndp(C + 1, vector<ll>(MAX_T + 1, INF));

    int d = X[0] - '0';

    // carry anterior = 0
    //
    // T0 = d + 10 * carry0
    //
    // T0 es la respuesta que queremos minimizar.
    for (int carry = 0; carry <= C; carry++) {
        int T = d + 10 * carry;

        if (T <= MAX_T)
            dp[carry][T] = T;
    }

    for (int i = 1; i < n; i++) {
        for (auto &row : ndp)
            fill(row.begin(), row.end(), INF);

        d = X[i] - '0';

        for (int prevCarry = 0; prevCarry <= C; prevCarry++) {
            for (int prevT = 0; prevT <= MAX_T; prevT++) {

                if (dp[prevCarry][prevT] == INF)
                    continue;

                for (int carry = 0; carry <= C; carry++) {

                    // En la última posición no puede quedar carry.
                    if (i == n - 1 && carry != 0)
                        continue;

                    /*
                        T_i + carry_{i-1}
                            = digit_i + 10 * carry_i

                        =>

                        T_i = digit_i + 10*carry_i - carry_{i-1}
                    */
                    int T = d + 10 * carry - prevCarry;

                    if (T < 0 || T > MAX_T)
                        continue;

                    /*
                        Los billetes que llegan a esta posición
                        deben ser <= los que llegaban a la posición
                        anterior.
                    */
                    if (T > prevT)
                        continue;

                    ndp[carry][T] =
                        min(ndp[carry][T], dp[prevCarry][prevT]);
                }
            }
        }

        dp.swap(ndp);
    }

    ll ans = INF;

    for (int carry = 0; carry <= C; carry++) {
        for (int T = 0; T <= MAX_T; T++) {
            ans = min(ans, dp[carry][T]);
        }
    }

    cout << ans << '\n';

    return 0;
}