#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    auto mx = max_element(all(a));
    auto mn = min_element(all(a));
    if(*mx == *mn) {
        cout<<"NO"<<endl;
    }else{
        vector<int> ans=a;
        for(int i=0 ; i<n ; i++){
            if(a[i] == *mx) ans[i]=1;
            else ans[i]=2;
        }
        cout<<"YES"<<endl;
        for(int i=0 ; i<n ; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}