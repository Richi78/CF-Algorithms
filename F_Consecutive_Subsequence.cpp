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

}

signed main(){
    FIO;
    int n;cin>>n;
    map<int,int> dp;
    vector<int> a(n+1);
    int key_idx=0 , cant=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[a[i]]=dp[a[i]-1]+1;
        if(cant<dp[a[i]]){
            key_idx=i;
            cant=dp[a[i]];
        }
    }
    cout<<cant<<endl;
    stack<int> s;
    int tmp=a[key_idx];
    for(int i=key_idx;i>=0 && cant>0;i--){
        if( a[i]==tmp){ // dp[a[i]]==cant
            s.push(i);
            cant--;
            tmp--;
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}