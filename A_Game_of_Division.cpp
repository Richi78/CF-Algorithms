#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define sz(a) (a).size()
#define input(x) cin >> x
#define printv(v) for(int i=0;i<sz(v);i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n) , freq[k]; 
    int idx=-1;
    for(int i=0; i<n ; i++){
        int x; cin >> x;
        freq[x%k].push_back(i+1);
    }
    for(int i=0; i<k ; i++){
        if(freq[i].size() == 1){
            cout<<"YES\n"<<freq[i][0]<<endl;
            return;
        }
    } 
    cout<<"NO"<<endl;
}

signed main(){
    int tc;cin>>tc;
    while(tc--)solve();
}