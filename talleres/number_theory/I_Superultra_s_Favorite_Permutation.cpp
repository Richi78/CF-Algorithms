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

bool isPrime(int a){
    for(int i=2 ; i*i<=a ; i++){
        if(a%i == 0) return false;
    }
    return a>=2;
}

void solve(){
    int n; cin >> n;
    if(n <= 4){
        cout<<"-1\n"; return;
    }
    stack<int> s;
    for(int i=1; i<=n ; i+=2) s.push(i);

    int idx=-1;
    for(int i=2 ; i<=n ; i+=2){
        int tmp=s.top();
        if( !isPrime(tmp+i) ){
            idx=i; break;
        } 
    }
    for(int i=2 ; i<=n ; i+=2){
        if(i != idx) cout<< i <<" ";
    }
    cout<< idx<<" ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}