#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i=0;i<n;i++)
#define print(x) cout << x << " "
#define printl(x) cout << x << endl
#define input(x) cin >> x
#define printv(v) for(int i=0;i<v.size();i++) print(v[i]); cout << "\n";
#define vi vector<int>
#define vii vector<pair<int,int>>
#define F first 
#define S second
#define pii pair<int,int>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ilz(x) 64-__builtin__clzll(x)-1   //usar -1 para shifts, solo index quitar -1


vi segmentTree(vi &a){
    int n=a.size();
    vi b(2*n);
    for(int i=0;i<n;i++)b[n+i]=a[i];
    for(int i=n-1; i>0; i--){
        b[i]=min(b[2*i],b[2*i+1]);
    }
    return b; 
}

vi update(int i, int v, vi &a){
    int n=(a.size()/2);
    i+=n;
    a[i]+=v;
    while(i>1){
        i/=2;
        int mn=min(a[2*i],a[2*i+1]);
        if(a[i]!=mn)a[i]=mn;
        else {
            return a;
        }
    }
    return a;
}


int minQ(int f, int t, vi &a){
    int n=a.size()>>1;
    f+=n; t+=n; int mn=1e8;
    while(f<t){
        if(f&1){
            mn=min(mn,a[f++]);
            // f++;
        }
        if(t&1){
            // t--;
            mn=min(mn,a[--t]);
        }
        f>>=2; t>>=2;
    }
    return mn;
}

signed main() {
    FIO;
    int n;cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)cin >> a[i];

    vi st = segmentTree(a);
    // cout<<"initial"<<endl;
    // printv(st);

    int m;cin>>m;
    cin.ignore();
    for (int i=0;i<m;i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        
        vector<int> b;
        int x;
        while (iss >> x) {
            b.push_back(x);
        }
        int ini=b[0], fin=b[1], h;
     
        if(b.size()==3){
            h=b[2];
            if (ini <= fin) {
                for(int i=ini;i<=fin;i++){
                    st=update(i,h,st);
                }
            } else {
                for(int i=ini;i<n;i++){
                    st=update(i,h,st);
                }
                for(int i=0;i<=fin;i++){
                    st=update(i,h,st);
                }
              
            }
        }else{
            int mn;
            if (ini <= fin) {
                mn=minQ(ini,fin,st);
            } else {
                int mn1=minQ(ini,n,st);
                int mn2=minQ(0,fin,st);
                mn=min(mn1,mn2);
            }
            cout<<mn<<endl;
        } 
    }
}