#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n; cin >> n;
    int sum=0;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(n == 1){
        cout<<a[0]<<endl;
    }else{
        while(a.size() != 1){
            int cnt=0;
            vector<int> tmp;
            for(int i=0; i+1<a.size(); i++){
                int x = a[i] - a[i+1];
                cnt+=x;
                tmp.push_back(x);
            }
            sum=max(sum, abs(cnt)); 
            a=tmp;
        } 
        cout<<sum<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}