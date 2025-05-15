#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
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
    map<int,int> mp;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        mp[a[i]]++;
    } 
    
    int cnt=0 , l=0 , r=0 , ansl=-1 , ansr=-1, mx=-1;
    for(int i=0 ; i<n ; i++){
        if(mp[a[i]] == 1){
            cnt++;
            r=i;
            if(cnt > mx){
                mx = cnt;
                ansl=l;
                ansr=r;
            }
        }else{
            l = i + 1;
            cnt = 0;
        }
    }
    if(mx == -1) cout<<0<<endl;
    else cout<< ++ansl << " " << ++ansr << endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}