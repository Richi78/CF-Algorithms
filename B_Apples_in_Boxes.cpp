#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>


template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];

    int mx = *max_element(all(a)) , mn = *min_element(all(a));
    int cnt=count(all(a),mx);
    // cout<<"mx: "<<mx<<" mn: "<<mn<<endl;
    if( cnt > 1 ){
        if((mn+k) < (mx)){
            cout<<"Jerry"<<endl;
            
        }else{
            int sum=0;
            for(int i=0 ; i<n ; i++) sum+=a[i];
            if(sum&1) cout<<"Tom"<<endl;
            else cout<<"Jerry"<<endl;
        }
    }else{  // == 1
        if((mn+k) < (mx-1)){
            cout<<"Jerry"<<endl;
            return;
        }
        // sort(all(a), greater<int>());
        // bool turn=true; // 1t , 0 j
        // for(int i=0 ; i<n ; i++){
            // if(a[i]&1){
                // turn=!turn;
            // }else{
                // si es par el turno no cambia
            // }
        // }
        // if(turn) cout<<"Jerry"<<endl;
        // else cout<<"Tom"<<endl;
        int sum=0;
        for(int i=0 ; i<n ; i++) sum+=a[i];
        if(sum&1) cout<<"Tom"<<endl;
        else cout<<"Jerry"<<endl;
    }
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}