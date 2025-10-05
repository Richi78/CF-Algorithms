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
    int cur=0;
    map<int,int> freq;
    int dif=0;
    int mx_sz=r-l+1;
    for(int i=0 ; i<n ; i++){
        while(cur>l && right-1>left){
            right--;
            freq[a[right]]--;
            if(freq[a[right]] == 0){
                dif--;
            }
            cur--;
        }
        while(cur<l && right+1<n){
            right++;
            freq[a[right]]++;
            if(freq[a[right]] == 1){
                dif++;
            }
            cur++;
        }
        while(dif<k && right+1<n && cur<r){
            right++;
            freq[a[right]]++;
            if(freq[a[right]] == 1){
                dif++;
            }
            cur++;
        }
        while(dif>k && right-1>left && cur>l){
            right--;
            freq[a[right]]--;
            if(freq[a[right]] == 0){
                dif--;
            }
            cur--;
        }
        if(dif == k){
            // TODO formula to accumulate ans
            int tmp=min(n,left+mx_sz-1);
            ans+=(tmp-right+1);
        }else{

        }
        freq[a[left]]--;
        if(freq[a[left]] == 0){
            dif--;
        }
        cur--;
        left++;
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