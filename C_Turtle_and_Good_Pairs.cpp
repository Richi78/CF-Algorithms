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
    string s; cin >> s;
    vector<int> a(26);
    int cnt=0;
    for(int i=0 ; i<n ; i++) a[s[i]-'a']++; 
    int i=0 , j=0;
    while(n){
        if(a[i]>=1){
            s[j]=i+'a';
            a[i]--; n--;
            j++;
        }
        i=(i+1)%26;
    }
    cout<< s <<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

