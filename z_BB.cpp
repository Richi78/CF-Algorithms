#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e17;
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    // Padding a potencia de 2
    int N = 1; while(N < n) N <<= 1;
    int M = 1; while(M < m) M <<= 1;

    vector<vector<int>> st(2*N, vector<int>(2*M, -INF));

    // Hojas
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            st[N+i][M+j] = a[i][j];

    // Construir columnas (Y)
    for(int i = 0; i < 2*N; i++)
        for(int j = M-1; j > 0; j--)
            st[i][j] = max(st[i][2*j], st[i][2*j+1]);

    // Construir filas (X)
    for(int i = N-1; i > 0; i--)
        for(int j = 1; j < 2*M; j++)
            st[i][j] = max(st[2*i][j], st[2*i+1][j]);
            
    for(auto x : st){
        vdebug(x)
    }

    // Ejemplo: query en submatriz (x1,y1)-(x2,y2)
    auto query = [&](int x1,int y1,int x2,int y2) {
        int res = -INF;
        for(x1 += N, x2 += N; x1 <= x2; x1 /= 2, x2 /= 2) {
            int l = y1+M, r = y2+M;
            if(x1 % 2 == 1) {
                int L = l, R = r;
                while(L <= R) {
                    if(L % 2 == 1) res = max(res, st[x1][L++]);
                    if(R % 2 == 0) res = max(res, st[x1][R--]);
                    L /= 2; R /= 2;
                }
                x1++;
            }
            if(x2 % 2 == 0) {
                int L = l, R = r;
                while(L <= R) {
                    if(L % 2 == 1) res = max(res, st[x2][L++]);
                    if(R % 2 == 0) res = max(res, st[x2][R--]);
                    L /= 2; R /= 2;
                }
                x2--;
            }
        }
        return res;
    };

    // Ejemplo de uso
    int x1, y1, x2, y2;
    // cin >> x1 >> y1 >> x2 >> y2;
    cout << query(1, 1, 3, 3) << "\n";
}
