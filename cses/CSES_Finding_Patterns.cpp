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

const int MOD=998244353;
int A=31;
vector<int> h,p;

int getHash(int l, int r){
    int ans=(h[r] - (h[l-1]*p[r-l+1])%MOD)%MOD;
    return (ans+MOD)%MOD;
}

void solve(){
    string s; cin >> s;
    int n=(int)s.size();

    h.resize(n+1); p.resize(n+1,1);
    for(int i=1 ; i<=n ; i++){
        h[i]=((h[i-1]*A)%MOD + s[i-1])%MOD;
        p[i]=(p[i-1]*A)%MOD;
    }

    unordered_set<int> st;

    for(int j=1 ; j<=n ; j++){
        for(int i=1 ; i+j<=n ; i++){
            st.insert(getHash(i,i+j));
        }

    }
    
    int queries; cin >> queries;
    for(int i=0 ; i<queries ; i++){
        cin >> s;
        int tmp=0;
        for(int j=0 ; j<(int)s.size() ; j++){
            tmp = ((tmp*A)%MOD + s[j])%MOD;
        }
        if(st.count(tmp)) cout<< "YES\n";
        else cout<< "NO\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

