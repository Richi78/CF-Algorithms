#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> freq(n+1);
    long long ans=1;
    for(int i=0 ; i<n ; i++){
        if(i>0 && a[i]!=a[i-1]){
            ans+= i-freq[a[i]];
        }
        freq[a[i]]++;
    }
    cout<< ans <<"\n";
}