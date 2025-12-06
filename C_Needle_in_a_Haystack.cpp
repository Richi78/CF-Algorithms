#include <bits/stdc++.h>

using namespace std;

#define debug1(x) cout << #x << " = " << x << "\n";
#define debug2(x,y) cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
// const int MOD=998244353;

void solve(){
    string pat,alp; cin >> pat >> alp;

    vector<int> freq_pat(26);
    vector<int> freq_alp(26);
    for(int i=0 ; i<pat.size() ; i++){
        freq_pat[pat[i]-'a']++;
    }
    for(int i=0 ; i<alp.size() ; i++){
        freq_alp[alp[i]-'a']++;
    }
    for(int i=0 ; i<26 ; i++){
        if(freq_alp[i] < freq_pat[i]){
            cout<<"Impossible\n"; return;
        }
    }

    vector<string> blocks;
    {
        int i=0;
        while(i<pat.size()){
            char ini=pat[i];
            string s="";
            s+=ini;
            while(i+1<pat.size() && pat[i+1]<=ini){
                i++;
                s+=pat[i];
            }
            blocks.push_back(s);
            i++;
        }
    }

    for(int i=0 ; i<26 ; i++){
        freq_alp[i]-=freq_pat[i];
    }

    string ans="";
    int j=0; // ptr blocks
    for(int i=0 ; i<26 ; i++){
        if(freq_pat[i] && freq_alp[i] == 0){
            if(j<blocks.size() && i==blocks[j][0]-'a'){
                ans+=blocks[j];
                j++;
            } 
        }
        while(freq_alp[i]){
            if(j<blocks.size()){
                char c=blocks[j][0];
                if(i == c-'a'){
                    ans+=blocks[j];
                    j++;
                }else{
                    ans+=(i+'a');
                    freq_alp[i]--;
                }
            }else{
                ans+=(i+'a');
                freq_alp[i]--;
            }
        }
    }
    cout<< ans <<"\n";
}

signed main(){
    FIO;
    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);
    int tc;cin>>tc;
    while(tc--)solve();
}