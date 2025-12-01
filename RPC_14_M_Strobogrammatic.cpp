#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

map<char,char> rot={
    {'3','E'} , {'6','9'} ,{'E','3'},{'9','6'}
};

map<char,int> match={
    {'0',1},{'1',1},{'2',1},{'5',1},{'8',1}
};

map<char,int> no={
    {'4',1},{'7',1},{'A',1},{'b',1},{'C',1},{'d',1},{'F',1}
};

void solve(){
    string s; cin >> s;

    int i=0 , j=s.size()-1 , ans=0;
    while(i<=j){
        char a=s[i] , b=s[j];
        if(i == j){
            if(rot[a] || no[a]) ans++; 
        }else{
            if(a == rot[b] || b == rot[a]) ans=ans;
            else if(rot[a] && !rot[b] || rot[b] && !rot[a]) ans++;
            else if(no[a] && no[b]) ans+=2;
            else if(match[a] && !match[b] || match[b] && !match[a] || (match[a]&&match[b]&&a!=b)) ans++;
        }
        i++; j--;
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