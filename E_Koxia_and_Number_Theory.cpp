#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; ++i) cin>>a[i];
    sort(all(a));

    for(int i=1 ; i<n ; i++){
        if(a[i] == a[i-1]){cout<<"NO"<<endl; return;}
    }
    
    vector<int> primes;
    int x = n / 2;
    for(int i=2; i<=x ; i++){
        bool isP=true;
        for(int j = 2; j*j<=i; j++){
            if(i%j==0){
                isP=false;
                break;
            }
        }
        if(isP)primes.push_back(i);
    }

    for(int i=0 ; i<primes.size() ; i++){
        int prime = primes[i];
        vector<int> modulo(prime);

        for(int j=0 ; j<n ; j++){
            modulo[a[j]%prime]++;
        }

        if(*min_element(all(modulo)) >= 2){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}