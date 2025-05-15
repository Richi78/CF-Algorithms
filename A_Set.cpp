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
    int l,r,k;cin>>l>>r>>k;
    int ll=l , rr=r , ans=0;
    if(l*k>r){cout<<0<<endl;return;}
    else if(l*k==r){cout<<1<<endl;return;}
    else{
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(mid*k<=r){ans=mid;ll=mid+1;}
            else if(mid*k>r){rr=mid-1;}
            // else if(mid*k<r)break;
        }
        cout<<ans-l+1<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}