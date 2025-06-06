#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define F first 
#define S second

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

bool intersect( const vector< pair< float, pair<float, float> > > &v, int i, int j) {

    float dx = v[i].S.F - v[j].S.F;
    float dy = v[i].S.S - v[j].S.S;
    float distance = sqrt(dx*dx + dy*dy);
    double sum = v[i].F + v[j].F;
    double diff = abs(v[i].F - v[j].F);
    return ((distance <= sum) && (distance >= diff));
}

signed main(){

    string line;
    getline(cin, line);
    istringstream ss(line);

    int n;
    ss >> n;
    while (n != -1) {
        vector< pair<float, pair<float, float> > > v(n);
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            ss.clear();
            ss.str(line);
            ss >> v[i].S.F >> v[i].S.S >> v[i].F;
        }

        vector<int> p(n);
        for (int i = 0; i < n; ++i) p[i] = i;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (p[i] != p[j] && intersect(v, i, j)) {
                    int old = max(p[i], p[j]);
                    int neu = min(p[i], p[j]);
                    for (int k = 0; k < n; ++k)
                        if (p[k] == old) p[k] = neu;
                }
            }
        }

        vector<int> c(n);
        int max = 0;
        for (int i = 0; i < n; ++i) {
            c[p[i]]++;
            if (c[p[i]] > max) max = c[p[i]];
        }

        cout << "The largest component contains " << max << " ring";
        cout << (max == 1 ? "":"s") << "." << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        ss >> n;
    }
}