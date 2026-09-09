#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout<<#x<<": "<<x<<"\n";
#define debug2(x,y) cout<<#x<<": "<< x <<" , "<< #y <<": "<< y <<"\n";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    vector<int> candy(n) , emp;
    for(int i=0 ; i<n ; i++) cin >> candy[i];
    for(int i=0 ; i<m ; i++) {
        int x; cin >> x;
        if(emp.empty()) emp.push_back(x);
        if(x < emp.back()) emp.push_back(x);
    }

    // for(auto x : emp) cout<<x <<" "; cout<<"\n";

    vector<int> ans(n);
    for(int i=0 ; i<n ; i++){
        int x=candy[i];
        while(true){
            int l=-1 , r=emp.size();
            while(r-l>1){
                int mid=l+(r-l)/2;
                if(emp[mid] <= x) r=mid;
                else if(emp[mid] > x) l=mid; 
            }
            if(r != emp.size()){
                // debug2(r,emp[r])
                x%=emp[r]; 
            }else {break;}
        }
        ans[i] = x;
    }
    for(auto x : ans) cout<< x <<" "; 
    cout<<"\n";
}