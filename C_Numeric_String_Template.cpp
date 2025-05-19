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
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int m; cin >> m;
    for(int j=0 ; j<m ; j++){
        string s; cin >> s;
        int lens=s.size();
        if(n != lens){
            cout<<"NO"<<endl;
            continue;
        }else{
            map<int,char> mp1;
            map<char,int> mp2;
            bool bad=false;
            for(int i=0 ; i<lens ; i++){
                int x=a[i]; char c=s[i];

                if(!mp1.count(x)) mp1[x]=c;
                if(!mp2.count(c)) mp2[c]=x;

                if(mp1[x] != c || mp2[c] != x) {
                    bad=true; 
                    break;
                }
            }
            if(bad)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}


