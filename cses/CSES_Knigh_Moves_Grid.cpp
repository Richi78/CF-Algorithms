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

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n,1e8));

    vector<pair<int,int>> moves;

    for(int rep=0 ; rep<2 ; rep++){
        for(int i=-2 ; i<=2 ; i+=4){
            for(int k=-1 ; k<=1 ; k+=2){
                if(rep&1)
                    moves.emplace_back(i,k);
                else
                    moves.emplace_back(k,i);
            }
        }
    }

    set<array<int,3>> st;
    a[0][0]=0;
    st.insert({0,0,0});
    while(!st.empty()){
        auto it=*st.begin();
        st.erase(st.begin());
        int row=it[0] , col=it[1] , m=it[2];
        for(auto [x,y] : moves){
            int nrow=row+x , ncol=col+y;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                if(m+1 < a[nrow][ncol]){
                    if(a[nrow][ncol] != 1e8){
                        st.erase({nrow,ncol,a[nrow][ncol]});
                    }
                    a[nrow][ncol]=m+1;
                    st.insert({nrow,ncol,a[nrow][ncol]});
                }
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}