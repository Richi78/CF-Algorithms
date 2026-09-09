#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> p(n);

    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    ll ans = 0;

    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            for (int c = b + 1; c < n; c++) {
                for (int d = c + 1; d < n; d++) {

                    bool valid = true;

                    if (cross(p[a], p[b], p[c]) == 0)
                        valid = false;

                    if (cross(p[a], p[b], p[d]) == 0)
                        valid = false;

                    if (cross(p[a], p[c], p[d]) == 0)
                        valid = false;

                    if (cross(p[b], p[c], p[d]) == 0)
                        valid = false;

                    if (valid)
                        ans++;
                }
            }
        }
    }

    cout << ans << '\n';
}