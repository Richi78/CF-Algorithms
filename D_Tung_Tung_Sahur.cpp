#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    string p,s;cin>>p>>s;
    if(p[0]!=s[0]){no;return;}
    int i=0 , j=0;
    char lastP=p[0] , lastS=s[0];
    while(i<p.size() && j<s.size()){
        int cntP=0 , cntS=0;
        while(i<p.size()){
            char c=p[i];
            if(c!=lastP){
                lastP=c;
                break;
            } else{
                cntP++;
                i++;
            }
        }
        while(j<s.size()){
            char c=s[j];
            if(c!=lastS){
                lastS=c;
                if(cntS<cntP || cntS>2*cntP){no;return;}
                else{break;}
            }else{
                cntS++;
                j++;
                if(j==s.size() && (cntS<cntP || cntS>2*cntP) ){no;return;}
            }
        }
        // cout<<"P: "<<cntP<<" S: "<<cntS<<endl;
    }
    if(i==p.size() && j==s.size())yes;
    else no;
    
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}
