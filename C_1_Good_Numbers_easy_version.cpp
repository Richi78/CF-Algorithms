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

// ------------BINEXP---------------
int binexp(int a, int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a = (a*a); //% MOD; // si hay un MOD
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    vector<int> a;

    while(n){
        a.push_back(n%3);
        n/=3;
    }

    bool ok=false;
    
    for(int i=0 , k=a.size() ; i<k ; i++){
        if(a[i]==1 || a[i]==0) {
            ok=true;
            continue;
        }
        if(a[i]==2){
            ok=false;
            while(i+1 < a.size() && a[i+1])i++;
            if(i>=a.size()-1) break;
            for(int j=i ; j>=0 ; j--)a[j]=0;
            a[i+1]++;
            ok=true; 
          
        }
    }

    if(ok){
        int ans=0 , x=1;
        for(int i=0 ; i<a.size() ; i++){
            if(a[i]) ans+=x;
            x*=3;
        }
        cout<< ans <<endl;
    }else{
        cout<<binexp(3,a.size())<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}