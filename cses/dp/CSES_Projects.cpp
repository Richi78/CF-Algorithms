#include <bits/stdc++.h>

using namespace std;

const int START=0;
const int END=1;

struct Event{
    int pos;
    long long val;
    int type; // START | END
    int id;
    bool operator<(const Event &other) const {
        return make_pair(pos,type) < make_pair(other.pos,other.type);
    }
};

int main(){
    int n; cin >> n;
    vector<Event> a;
    for(int i=0 ; i<n ; i++){
        int u,v,w; cin >> u >> v >> w;
        a.push_back({u,w,START,i});
        a.push_back({v,w,END,i});
    }

    sort(a.begin(), a.end());

    int m=a.size();
    vector<long long> at_end(m);
    long long mx=0; 
    for(int i=0 ; i<m ; i++){
        if(a[i].type == START){
            at_end[a[i].id] = mx + a[i].val;
        }else{
            mx=max(mx,at_end[a[i].id]);
        }
    }

    cout<< mx <<"\n";

    return 0;
}