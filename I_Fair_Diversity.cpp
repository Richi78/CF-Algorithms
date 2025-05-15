#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=2005;
int cnt[N]={0};
void solve(){

}

signed main(){
    int n,d;cin>>n>>d;
    for(int i=0;i<d;i++){
        int x,y; cin>>x>>y;
        cnt[x]++; cnt[y]++;
    } 
    int mx=*max_element(cnt, cnt+N);
    // cout<<mx<<endl;
    int sum=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int delta=mx-cnt[i];
        mp[i]=delta;
    }
    if(n&1){
        for(int i=1;i<=n;i++){
            sum+=mx-cnt[i];
        }
        if(sum&1){
            cout<<mx+1<<endl; 
        }else{
            cout<<mx<<endl; 
        }
    }else cout<<mx<<endl;
}