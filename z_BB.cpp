#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Construir la función de prefijo para KMP
vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// Usar KMP para encontrar todas las posiciones de "patron" en "texto"
vector<int> kmp_search(const string& texto, const string& patron) {
    vector<int> posiciones;
    string combinado = patron + '#' + texto;
    vector<int> pi = prefix_function(combinado);
    int p_len = patron.size();
    for (int i = p_len + 1; i < (int)pi.size(); ++i) {
        if (pi[i] == p_len)
            posiciones.push_back(i - 2 * p_len);
    }
    return posiciones;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    while (cin >> c) {
        cin.ignore();
        vector<string> ingredientes(c);
        for (int i = 0; i < c; ++i)
            getline(cin, ingredientes[i]);
        
        string receta;
        getline(cin, receta);

        for (int i = 0; i < c; ++i) {
            vector<int> pos = kmp_search(receta, ingredientes[i]);
            for (int j = 0; j < (int)pos.size(); ++j) {
                if (j > 0) cout << " ";
                cout << pos[j];
            }
            cout << "\n";
        }
    }

    return 0;
}
