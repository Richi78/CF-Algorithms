#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

string encode(vector<int> &a){
    string s="";
    for(auto x : a){
        s.push_back((x-1)+'a');
    }
    return s;
}

vector<int> decode(string &s){
    vector<int> a;
    for(auto c : s){
        a.push_back((c-'a')+1);
    }
    return a;
}

void solve(){
    string s; cin >> s;
    if(s[0] == 'f'){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        cout<< encode(a) <<"\n";
    }else{
        string f; cin >> f;
        vector<int> a=decode(f);
        cout<< a.size() <<"\n";
        for(auto x : a) cout << x <<" ";
        cout<<"\n";
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