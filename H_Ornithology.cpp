#include <bits/stdc++.h>

using namespace std;

int BASE=1;
vector<int> st;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;    

    while(BASE < n) BASE <<= 1;
    st.resize(2*BASE);

    long long ans=0;
    for(int rep=0 ; rep<n ; rep++){
        int p; cin >> p;
        stack<int> xd;
        for(int j=0 ; j<p ; j++){
            int x; cin >> x; 
            xd.push(x);
            for(int i=x+BASE ; i>=1 ; i>>=1){
                if(i%2 == 0){
                    ans+=st[i+1];
                }
            }
        }
        while(!xd.empty()){
            int x=xd.top(); xd.pop();
            for(int i=x+BASE ; i>=1 ; i>>=1){
                st[i]+=1;
            }
        }
    }
    cout << ans <<"\n";
}