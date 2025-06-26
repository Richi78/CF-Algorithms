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
    int n,m; cin >> n >> m;
    vector<string> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    vector<char> digits={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

    for(int i=0 ; i<m ; i++){
        string s; cin >> s;
        int sz=s.size();
        int cnt=0;
        vector<string> ans;
        for(int j=0 ; j<n ; j++){
            if(a[j].size() != sz) continue;
            bool ok=true;
            for(int k=0 ; k<a[j].size() ; k++){
                if( digits[a[j][k]-'a'] != s[k] ){
                    ok=false;
                    break;
                }
            }
            if(ok){
                cnt++; ans.push_back(a[j]);
            }
        }
        if(cnt){
            cout<< cnt <<" ";
            for(int j=0 ; j<ans.size() ; j++){
                cout<< ans[j];
                if(j!=ans.size()-1) cout<<" ";
            }
            cout<<"\n";
        }else{
            cout<< "0\n";
        }
    }
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}