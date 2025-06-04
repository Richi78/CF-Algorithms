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

void solve(vector<int> &fib){
    int n,m; cin >> n >> m;
    string ans=""; 
    for(int i=0 ; i<m ; i++){
        int w,l,h; cin >> w >> l >> h;
        int mn=min(w, min(l,h)) , mx=max(w, max(l,h));
        int mid=w+l+h-mn-mx;
        array<int,2> a={fib[n-1],fib[n-2]};
        bool ok=true;
        for(int j=0 ; j<2 ; j++){
            if(a[j] > mn){
                ok=false; break;
            }else{
                int tmp=mx-a[j] , tmp2=mn , tmp3=mid;
                mn=min(tmp, min(tmp2,tmp3)) , mx=max(tmp, max(tmp2,tmp3));
                mid=tmp+tmp2+tmp3-mn-mx;
            }
        }
        if(ok) ans.push_back('1');
        else ans.push_back('0');
    }
    cout<< ans <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    vector<int> fib(10);
    fib[0]=1; fib[1]=2;
    for(int i=2 ; i<10 ; i++) fib[i]=fib[i-1]+fib[i-2];
    while(tc--)solve(fib);
}