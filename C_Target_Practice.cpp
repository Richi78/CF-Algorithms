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

vector<vector<int>> init(){
    int cnt=1;
    vector<vector<int>> a(10,vector<int>(10));
    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(i==j) a[i][j]=cnt+i;
            if(j>i && j<10-i) a[i][j]=a[i][j-1];
            if(j<i) a[i][j]=cnt+j; 
            if(j>=10-i) a[i][j]=10-j;
        }
    }
    
    cnt=1;
    for(int i=5 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            a[i][j]=a[i-cnt][j];
        }
        cnt+=2;
    }
    return a;
}

void solve(vector<vector<int>> &b){
    vector<string> a(10);
    int cnt=0;
    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++){
            char c; cin >> c;
            if(c=='X')cnt+=b[i][j];
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    FIO;
    vector< vector<int> > b = init();
    // for(auto x: b){
    //     vdebug(x)
    // }
    int tc;cin>>tc;
    while(tc--)solve(b);
}