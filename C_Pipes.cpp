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
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
    vector<string> pipes={s1,s2};
    bool up=1 , curved=0;
    // if(s1[0]=='1')
    // debug2(s1,s2)
    int row=0 , col=0;
    while(col<n){
        if(pipes[row][col]-'0' <= 2){
            curved=0;
            // up=1;
            col++;
        }else{
            curved=1;
            up=!up;
            row=!row;
            // int tmp1=pipes[row][col]-'0';
            // debug1(tmp1)
            if(pipes[row][col]-'0' <= 2){
                // int tmp2=pipes[row][col]-'0';
                // debug1(tmp2)
                cout<<"NO"<<endl;
                return;
            }else{
                col++;
                // up=!up;
            }
        }
    }
    if(up) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}