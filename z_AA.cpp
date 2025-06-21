#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;

struct Punto {
    int x, y;
    bool operator<(const Punto &o) const {
        return tie(x, y) < tie(o.x, o.y);
    }
};

struct Vec {
    int dx, dy;
};

double cross(const Vec& a, const Vec& b) {
    return a.dx * b.dy - a.dy * b.dx;
}

double dot(const Vec& a, const Vec& b) {
    return a.dx * b.dx + a.dy * b.dy;
}

double angle_between(const Vec& a, const Vec& b) {
    double dotp = dot(a, b);
    double crossp = cross(a, b);
    return atan2(abs(crossp), dotp); // always returns angle in [0, pi]
}

int main() {
    int n;
    cin >> n;
    map<Punto, vector<Vec>> conexiones;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Punto p1{x1, y1}, p2{x2, y2};
        Vec v1{x2 - x1, y2 - y1};
        Vec v2{x1 - x2, y1 - y2};
        conexiones[p1].push_back(v1);
        conexiones[p2].push_back(v2);
    }

    int angulos_convexos = 0;

    for (auto& [p, vectores] : conexiones) {
        int k = vectores.size();
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                double angulo = angle_between(vectores[i], vectores[j]);
                if (angulo > 0 && angulo < M_PI) {
                    angulos_convexos++;
                }
            }
        }
    }

    cout << angulos_convexos << endl;
}
