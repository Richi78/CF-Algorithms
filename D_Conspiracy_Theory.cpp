#include <bits/stdc++.h>

using namespace std;

#define int long long 

template<typename T> bool uax(T &a, T b){return b > a ? (a=b,true) : false; }

const int N=2e6+20;
int dp[N]={0};

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

signed main(){
    int n;cin>>n;
    set<int> s;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x; cin>>x; 
        s.insert(x);
        if(mp[x]==0)mp[x]=i+1;
    }

    auto it1=s.begin();

    cout<<"set"<<endl;
    for(auto x:s){
        cout<<x<<" ";
    }
    cout<<endl;

    int sini=*s.begin();
    
    if(sini == 1){
        dp[*(++s.begin())]=1;
        it1=++(++s.begin());
    }else {
        dp[*s.begin()]=1;
        it1=++s.begin();
    }

    auto itref=it1;
    int val=0 , cant=0;
    vector<int> ans;
    for( it1; it1!=s.end(); it1++){
        // auto it2=next(it1);
        cout<<"it1: "<<*it1<<endl;
        auto tmpit=it1;
        while(tmpit!=s.begin()){
            int x=*(--tmpit), y=*it1;
            cout<<"x: "<<x<<endl;
            if(gcd(x,y)>1){
                dp[y]=dp[x]+1;
                val=max(val,y);
                cant++;
                // if(uax(val,y)){
                    
                // }
                itref=it1;
                break;
            }else{
                dp[y]=1;
            }
        }
    }

    cout<<"dp:"<<endl;
    for(int i=0;i<15;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    cout<<val<< " " <<cant<<endl;
    cout<<*itref<<endl;

    for(auto it=itref; ; it--){
        int x=*it;
        if(x == cant){
            cout<<mp[x]<<" ";
        }

        if(it==s.begin()){

        }
    }

    auto itm1=itref , itm2=prev(itref);
    while(1){
        int x=*itm1 , y=*itm2;
        if(gcd(x,y)>1){
            cout<<x<<" ";
            itm1=itm2;
        }
        itm2--;
        
        if(itm2==s.begin()){
            y=*itm2;
            if(gcd(x,y)>1){
                cout<<x<<" "<<y<<endl;
                return 0;
            }
        }
    }

    cout<<cant<<endl;
}