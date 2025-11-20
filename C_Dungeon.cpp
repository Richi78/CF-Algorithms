#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,m; cin >> n >> m;
    multiset<int> a;
    vector<int> b(m) , c(m);

    for(int i=0 ; i<n ; i++){
        int x; cin >> x; 
        a.insert(x);
    }
    for(int i=0 ; i<m ; i++) cin >> b[i];
    for(int i=0 ; i<m ; i++) cin >> c[i];

    vector<int> m_0;
    multiset<pair<int,int>> m_1;

    for(int i=0 ; i<m ; i++){
        if(c[i] > 0) m_1.insert({b[i],c[i]});
        else m_0.push_back(b[i]);
    }

    int ans=0;

    auto x=a.begin();
    auto itt=m_1.begin();
    while(itt != m_1.end() && x!=a.end()){
        int b=itt->first , c=itt->second;
        if(*x >= b){ 
            itt=m_1.erase(itt);
            int mx=max(*x,c);
            if(mx > *x){
                a.erase(x);
                a.insert(mx);
                x=a.begin();
            }
            ans++;
        }else{
            x++;
        }
    }

    sort(all(m_0));

    auto it1=a.rbegin();
    int j=m_0.size()-1;
    while(it1!=a.rend() && j>=0){
        int x=*it1;
        if(x >= m_0[j]){
            ans++;
            it1++;
            j--;
        }else{
            j--;
        }
    }
    
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}