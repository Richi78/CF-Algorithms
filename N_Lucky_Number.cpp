#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> cnt(5);
    for(int i=0 ; i<n ; i++){
        int x; cin >> x; cnt[x%5]++;
    }
    int ans=cnt[0];
    // 4-1 3-2 3-1 2-1 1-1 
    { // 4-1  // siempre conviene 1 de 4 y 1 de 1
        int mn=0;
        while(cnt[4]>=1 && cnt[1]>=1){
            mn++; cnt[4]--; cnt[1]--;
        }
        ans+=mn;
    }
    { // 3-2   // esto para acabar con todos los 3
        int mn=0;
        while(cnt[3]>=1 && cnt[2]>=1){
            mn++; cnt[3]--; cnt[2]--;
        }
        ans+=mn;
    }
    { //3-1
        int mn=0;
        while(cnt[3]>=1 && cnt[1]>=2){
            mn++; cnt[3]--; cnt[1]-=2;
        }
        ans+=mn;
    }
    { // 2-1 (take 2 de 2 y 1 de 1)
        int mn=0;
        while(cnt[2]>=2 && cnt[1]>=1){
            mn++; cnt[2]-=2; cnt[1]--;
        }
        ans+=mn;
    }
    { // 2-1 (take 1 de 2 y 3 de 1)
        int mn=0;
        while(cnt[2]>=1 && cnt[1]>=3){
            mn++; cnt[2]--; cnt[1]-=3;
        }
        ans+=mn;
    }
    { // 1-1
        int mn=0;
        while(cnt[1]>=5){
            mn++; cnt[1]-=5;
        }
        ans+=mn;
    }

    cout<< ans <<"\n";
    return 0;
}