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

void solve(){
    int n,m; cin >> n >> m;
    vector<int> pos , a(m+1);
    int left=0,right=0;
    int idx=-1 , cant=1, mx=-1;

    for(int i=0 ; i<n ; i++){
        int x; cin>>x;
        if(x==-1)left++;
        else if(x==-2)right++;
        else pos.push_back(x);
    }
    sort(all(pos));
    for(int i=0 ; i+1<pos.size() ; i++){
        if(abs(pos[i]-pos[i+1]) == 1){
            idx=i+1;
            cant++;            
        }else{
            if(uax(mx,cant)){
                idx=i+1;
            }
            cant=1;
        }        
    }
    int ini=idx-mx;
    debug1(ini)

    int l=1e9 , r=-1 , cnt=0;
    for(int i=ini ; i<=idx ; i++){
        if(a[pos[i]] == 0){
            a[pos[i]]=1; cnt++;
            uin(l,pos[i]);
            uax(r,pos[i]);
        }
    }

    vdebug(a)
    debug2(l,r)
    while(left && l-1>=1){
        if(cnt == 0){
            a[m]=1; cnt++; left--;
            l=m;
        }
        a[l-1];
    }

    // for(int i=0 ; i<n ; i++){
    //     int s=p[i];
    //     if(s == -1){
    //         if(cnt == 0){
    //             a[m]=1; l=m ; r=m;
    //             cnt++;
    //         }
    //         if(l == 1) continue;
    //         a[l-1]=1;
    //         l--; cnt++;

    //     }else if(s == -2){
    //         if(cnt == 0){
    //             a[1]=1; l=1; r=1;
    //             cnt++;
    //         }
    //         if(r == m) continue;
    //         a[r+1]=1;
    //         r++; cnt++;
    //     }else{ // >0
    //         if(a[s] == 1) continue;
    //         if(s<l) l=s;
    //         else if(s>r) r=s;
    //         a[s]=1;
    //         cnt++;
    //     }
    // }
    // vdebug(a)
    // cout<< cnt << endl;
}

signed main(){
    FIO;
    int tc;cin>>tc;
    while(tc--)solve();
}