#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void solve(){
    int n,k,l,r; cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin >> a[i];
    
    int ans=0;
    int left=0,right=-1;
    int cur=1;
    map<int,int> freq;
    int dif=0;
    bool searching=true;
    while(true){
        if(searching){
            cur=right-left+1;
            if( cur>=l && cur<=r ){
                searching=false;
                continue;
            }
            right++;
            freq[a[right]]++;
            if(freq[a[right]] == 1){
                dif++;
            }
        }else{

            if(dif == k){
                ans++;
                int limit=min(n-1,left+r-l);
                ans+=(limit-(left-1))-cur;
                // move l
                freq[a[left]]--;
                if(freq[a[left]] == 0){
                    dif--;
                }
                left++;
                searching=true;
            }else{
                // another search operation
                right++
                freq[a[right]]++;
                if(freq[a[right]] == 1){
                    dif++;
                }
                
            }
        }

    }
    // falta detalles de implementacion :v
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}