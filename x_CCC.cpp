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

void solve(string &s1, string &s2){
    int l1=s1.size() , l2=s2.size();
    vector<int> a(26), b(26);
    for(int i=0 ; i<l1 ; i++){
        char x=s1[i]; 
        a[x-'a']++;
    }
    for(int i=0 ; i<l2 ; i++){
        char x=s2[i];
        b[x-'a']++;
    }
    string ans="";
    for(int i=0 ; i<26 ; i++){
        int x=a[i] , y=b[i];
        for(int j=0 ; j<min(x,y) ; j++){
            ans.push_back(i+'a');
        }
    }
    cout<< ans <<endl;
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    string s1,s2;
    while(getline(cin,s1)){
        getline(cin,s2);
        solve(s1,s2);
    }
}