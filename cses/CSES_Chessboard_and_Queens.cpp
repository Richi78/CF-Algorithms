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

bool isValid(int row, int col, vector<vector<int>> &a){
    // UL
    for(int i=0 ; row-i>=0 && col-i>=0 ; i++){
        if(a[row-i][col-i] == 1) return false;
    }
    //UR
    for(int i=0 ; row-i>=0 && col+i<=7 ; i++){
        if(a[row-i][col+i] == 1) return false;
    }
    //UP
    for(int i=0 ; row-i>=0 ; i++){
        if(a[row-i][col] == 1) return false;
    }
    return true;
}

void f(int row, vector<vector<int>> &a, int &ans){
    if(row == 8){
        ans++; return;
    }

    for(int j=0 ; j<8 ; j++){
        if(a[row][j] == 2) continue;
        if(isValid(row,j,a)){
            a[row][j]=1; 
            f(row+1, a, ans);
            a[row][j]=0;
        }
    }
}

void solve(){
    vector<vector<int>> a(8, vector<int>(8,0));
    for(int i=0 ; i<8 ; i++){
        for(int j=0 ; j<8 ; j++){
            char c; cin >> c;
            if(c == '*') a[i][j]=2;
        }
    }

    int ans=0;
    f(0 , a , ans);

    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}