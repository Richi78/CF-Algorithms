#include <bits/stdc++.h>

using namespace std;
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

// Función que determina si se puede encontrar el índice `target` en un arreglo de tamaño `n` con exactamente `k` comparaciones
bool canFind(int n, int target, int k) {
    int left = 0, right = n - 1;
    int comparisons = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        comparisons++;
        if(comparisons > k) break;
        if (mid == target) break;
        else if (mid > target) right = mid - 1;
        else left = mid + 1;
    }
    return comparisons == k;
}

void solve(){
    int i, k; cin >> i >> k;
    vector<int> valid_sizes;
    for (int n = i + 1; n <= 10000; n++) {
        if (canFind(n, i, k)) {
            valid_sizes.push_back(n);
        }
    }

    if (valid_sizes.empty()) {
        cout << 0 << endl;
        return;
    }

    vdebug(valid_sizes)
    
    // Agrupar tamaños consecutivos en intervalos
    vector<pair<int, int>> ans;
    int start = valid_sizes[0], end = valid_sizes[0];
    for (int j = 1; j < valid_sizes.size(); ++j) {
        if (valid_sizes[j] == end + 1) {
            end = valid_sizes[j];
        } else {
            ans.push_back({start, end});
            start = valid_sizes[j];
            end = valid_sizes[j];
        }
    }
    ans.push_back({start, end});

    // Salida
    cout << ans.size() << endl;
    for (auto [x,y] : ans) {
        cout << x << " " << y << endl;
    }
    
}

int main() {
    int tc; cin >> tc;
    while (tc--) solve(); 
}
