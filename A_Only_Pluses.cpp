#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int a,b,c; cin >> a >> b >> c;
    int sum=a+b+c;
    int k=5;
    int mn=min(a,min(b,c)) , mx=max(a,max(b,c)) , md=sum-mn-mx;
    if(md - mn >= 5){
        mn+=k;
    }else{
        k-=md-mn;
        mn+=md-mn;
        bool turn=1;
        while(k){
            if(mx >= md){
                if(turn) mn+=1;
                else md+=1;
                turn=!turn;
                k--;
            }else{
                mx+=1;
                k--;
            }
        }
    }

    cout<< mn * md * mx << endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}



