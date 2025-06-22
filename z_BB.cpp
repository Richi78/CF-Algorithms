#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> prefix(const string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i=1 ; i<n ; i++) {
        int j = pi[i-1];
        while (j>0 && s[i]!=s[j])
            j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string& text, const string& pat) {
    vector<int> pos;
    string s = pat + "#" + text;
    vector<int> pi = prefix(s);
    int n = pat.size();
    for (int i=n+1 ; i<pi.size() ; i++) {
        if (pi[i] == n) {
            pos.push_back(i - 2*n);
        }
    }
    return pos;
}

void solve(vector<string> &a, string r){
    for (auto &x : a) {
        vector<int> pos = kmp(r, x);
        if (!pos.empty()) {
            for (size_t j = 0; j < pos.size(); ++j) {
                if (j > 0) cout << " ";
                cout << pos[j];
            }
        }
        cout << "\n";
    }
}

signed main() {
    // cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        int n;
        stringstream ss(line);
        ss >> n;

        vector<string> a(n);
        for (int i = 0; i<n; ++i) {
            getline(cin, a[i]);
        }

        string r;
        getline(cin, r);

        solve(a,r);
    }
}
