
#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    vector<vector<int>> a(3,vector<int>(6));
    for(int rep=0 ; rep<3 ; rep++){
        for(int i=0 ; i<6 ; i++){
            cin >> a[rep][i];
        }
    }

    set<int> st;

    double total=36.0;
    for(int rep=0 ; rep<3 ; rep++){
        bool ok=true;
        for(int opp=0 ; opp<3 ; opp++){
            if(opp == rep) continue;
            int fav=0;
            int tie=0;
            for(int i=0 ; i<6 ; i++){
                for(int j=0 ; j<6 ; j++){
                    if(a[rep][i] > a[opp][j]){
                        fav++;
                    }else if(a[rep][i] == a[opp][j]){
                        tie++;
                    }
                }
            }
            double prob=(1.0*fav)/(total-tie);
            if(prob>=0.5) ok&=true; 
            else ok&=false;
        }
        if(ok) st.insert(rep+1);
    }
    if(st.empty()) cout<<"No dice\n";
    else cout<< *st.begin() <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}
