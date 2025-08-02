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
// const int MOD=998244353;

template<typename T> bool uin(T &a, T b) {return a>b?(a=b,true):false;}
template<typename T> bool uax(T &a, T b) {return a<b?(a=b,true):false;}

void merge(vector<int> &a, int l, int r){
    int mid=l+(r-l)/2;
    vector<int> tmp;
    int i=l , j=mid+1;
    while(i<=mid && j<=r){
        if(a[i] <= a[j]){
            tmp.push_back(a[i]);
            i++;
        }else{
            tmp.push_back(a[j]);
            j++;
        }
    }
    while(i<=mid){
        tmp.push_back(a[i]); i++;
    }
    while(j<=r){
        tmp.push_back(a[j]); j++;
    }
    for(int i=l ; i<=r ; i++){
        a[i]=tmp[i-l];
    }
}

void mergeSort(vector<int> &a, int l, int r){
    if(l==r) return;
    int mid=l+(r-l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    merge(a, l, r);
}

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    } 

    mergeSort(a, 0 , n-1);

    for(auto x : a){
        cout<< x <<" ";
    }
    cout<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}