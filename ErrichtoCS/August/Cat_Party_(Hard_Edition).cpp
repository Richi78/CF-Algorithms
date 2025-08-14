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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

const int N=1e5+10;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    vector<int> freq(N);
    map<int,int> ffreq;
    int ans=1;
    for(int i=0 ; i<n ; i++){
        int x=a[i];
        if(freq[x] != 0 && --ffreq[freq[x]] == 0){
            ffreq.erase(freq[x]);
        }
        ffreq[++freq[x]]++;
        int sz=(int)ffreq.size();
        if(sz == 1){
            if(ffreq.begin()->F == 1 || ffreq.begin()->S == 1) ans=i+1;
        }else if(sz == 2){
            auto f=ffreq.begin() , s=--ffreq.end();
            if(f->S==1 && f->F==1 || s->F==1 && s->S==1 
                || f->S==1 && f->F==s->F+1
                || s->S==1 && s->F==f->F+1)
                ans=i+1;
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

