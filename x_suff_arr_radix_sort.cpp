
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

void count_sort(vector<int> &p, vector<int> &c){
    int n=p.size();
    vector<int> cnt(n);
    for(auto x : c){
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1 ; i<n ; i++){
        pos[i]=pos[i-1]+cnt[i-1];
    }
    for(auto x : p){
        int i=c[x];
        p_new[pos[i]]=x;
        pos[i]++;
    }
    p=p_new;
}

void solve(){
    string s; cin >> s;
    s+='$';
    int n=s.size();
    vector<int> p(n) , c(n); // p is the suffarr

    //k=0
    {
        vector<pair<int,int>> tmp(n);
        for(int i=0 ; i<n ; i++){
            tmp[i]={s[i],i};
        }
        sort(all(tmp));
        for(int i=0 ; i<n ; i++){
            p[i]=tmp[i].S;
        }
        c[p[0]]=0;
        for(int i=1 ; i<n ; i++){
            if(tmp[i].F == tmp[i-1].F){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }
    }

    int k=0;
    while((1<<k) < n){
        // k -> k+1
        for(int i=0; i<n ; i++){
            p[i]=(p[i]-(1<<k) + n)%n;
        }
        
        count_sort(p,c);

        vector<int> c_new(n);
        c_new[p[0]]=0;
        for(int i=1 ; i<n ; i++){
            pair<int,int> prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int> now={c[p[i]],c[(p[i]+(1<<k))%n]};
            if(now == prev){
                c_new[p[i]]=c_new[p[i-1]];
            }else{
                c_new[p[i]]=c_new[p[i-1]]+1;
            }
        }
        c=c_new;
        k++;
    }   

    vdebug(p)
    for(int i=0 ; i<n ; i++){
        cout<< p[i] <<" "<< s.substr(p[i], n-p[i]) <<"\n";
    }
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}

