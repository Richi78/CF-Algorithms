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
    int n,x,k; cin >> n >> x >> k;
    string s; cin >>s;
    int cnt=0;
    bool reached=0;
    while(k){
        if(reached){
            int i=0 , moves=-1;
            while(k && i<n){
                k--;
                if(s[i] == 'L') x--;
                else x++;
                if(x == 0){
                    cnt++;
                    moves=i+1;
                    break;
                }
                i++;
            }
            if(moves > 0){
                int factor=k/moves;
                k-=factor*moves;
                cnt+=factor;
            }
            break;
        }else{
            int i=0;
            while(k && i<n){
                k--;
                if(s[i] == 'L') x--;
                else x++;
                if(x == 0){
                    cnt++;
                    reached=1;
                    break;
                }
                i++;
            }
            if(!reached) break;
        }
    }
    cout<<cnt<<endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}