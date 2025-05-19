#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,q; cin >> n >> q;
    string s1,s2; cin >> s1 >> s2;

    vector< vector<int> > pref1(n+1, vector<int>(26));
    vector< vector<int> > pref2(n+1, vector<int>(26));

    for(int i=1 ; i<=n ; i++){
        char c=s1[i-1];
        pref1[i][c-'a']++;
        for(int j=0 ; j<26 ; j++){
            pref1[i][j] += pref1[i-1][j];
        }
    }

    for(int i=1 ; i<=n ; i++){
        char c=s2[i-1];
        pref2[i][c-'a']++;
        for(int j=0 ; j<26 ; j++){
            pref2[i][j] += pref2[i-1][j];
        }
    }

    for(int j=0 ; j<q ; j++){
        int l,r; cin >> l >> r;

        int cnt=0;
        for(int i=0 ; i<26 ; i++){
            int v1=pref1[r][i] - pref1[l-1][i];
            int v2=pref2[r][i] - pref2[l-1][i]; 
            cnt+=abs(v1-v2);
        }
        cout<<cnt/2<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

