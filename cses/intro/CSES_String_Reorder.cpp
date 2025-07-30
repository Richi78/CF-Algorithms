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
    string s; cin >> s;
    int n=(int)s.size();
    vector<int> freq(26);
    for(int i=0 ; i<n ; i++){
        freq[s[i]-'A']++;
    }

    string ans="";
    while((int)ans.size() < n){
        bool finish=false;
        for(int i=0 ; i<26 ; i++){
            if( freq[i] && (ans.empty() || ans.back()!=i+'A') ){
                ans.push_back(i+'A');
                freq[i]--;
                int rest = n - (int)ans.size();
                bool gonext=false;
                for(int j=0 ; j<26 ; j++){
                    if(i!=j){
                        if(freq[j] > (rest+1)/2){
                            gonext=true;
                            break;
                        }
                    }else{
                        if(freq[j] > rest/2){
                            gonext=true;
                            break;
                        }
                    }
                }
                if(gonext){
                    freq[i]++;
                    ans.pop_back();
                }else{
                    finish=true;
                    break;
                }
            }
        }
        if(!finish) break;
    }
    if(ans.empty()) cout<<"-1\n";
    else cout<< ans <<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}