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
    int n,q; cin >> n >> q;
    string s1,s2; cin >> s1 >> s2;


    for(int j=0 ; j<q ; j++){
        int l,r; cin >> l >> r;
        --l; --r;

        map<char,int> mp1 , mp2;
        vector<int> alf(26,0);
        for(int i=l ; i<=r ; i++){
            mp1[s1[i]]++; mp2[s2[i]]++;
            alf[s1[i]-'a']++; 
        }
        int cnt=0;
        for(int i=0 ; i<alf.size() ; i++){
            if(alf[i]){
                int a=mp1[i+'a'] , b=mp2[i+'a'];
                if(a > b) cnt+=a-b;
            }
        }
        cout<<cnt<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}

