#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

int sqroot(long long n) {
    long long l = 0, r = n, ans = 0;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (mid * mid <= n) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

bool try_match(int u, vector<vector<int>>& adj, vector<int>& matchR, vector<bool>& vis) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        if (matchR[v] == -1 || try_match(matchR[v], adj, matchR, vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int pos = 1; pos <= n; pos++) {
            long long tmp = a[i] + pos;
            long long x = sqroot(tmp);
            if (x * x == tmp) {
                adj[i].push_back(pos);
            }
        }
    }

    vector<int> matchR(n + 1, -1);
    int matching = 0;

    for (int u = 1; u <= n; u++) {
        vector<bool> vis(n + 1, false);
        if (try_match(u, adj, matchR, vis)) {
            matching++;
        }
    }

    if (matching == n) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    FIO;
    solve();
}
