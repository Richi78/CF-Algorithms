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
    string s; cin >> s;
    vector<int> a(26);
    for(int i=0 ; i<(int)s.size() ; i++){
        a[s[i]-'A']++;
    }
    int cnt=0;
    for(int i=0 ; i<26 ; i++){
        if(a[i]&1) cnt++;
    }
    if(cnt > 1){
        cout<< "NO SOLUTION\n"; return;
    }

    char c='#';
    int j=0 , sz=s.size();
    for(int i=0 ; i<26 ; i++){
        while(a[i] > 1){
            s[j]=i+'A';
            s[sz-1-j]=i+'A';
            j++;
            a[i]-=2;
        }
        if(a[i]&1) c=i+'A';
    }

    if(c != '#'){
        s[sz/2]=c;
    }

    cout<< s <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}