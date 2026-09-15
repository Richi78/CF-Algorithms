#include <bits/stdc++.h>

using namespace std;

int n;

int solve(int row, int col, vector<string> &a){
    int ans=0; //[row][col] is 'B'
    // UR
    if(row-1>=0 && col+1<n && a[row-1][col+1]=='P'){
        if(row-2>=0 && col+2<n && a[row-2][col+2]=='.'){
            a[row][col]='.'; a[row-1][col+1]='.'; a[row-2][col+2]='B';
            int tmp=1+solve(row-2,col+2,a);
            a[row][col]='B'; a[row-1][col+1]='P'; a[row-2][col+2]='.';
            ans=max(ans,tmp);
        }
    }
    // UL
    if(row-1>=0 && col-1>=0 && a[row-1][col-1]=='P'){
        if(row-2>=0 && col-2>=0 && a[row-2][col-2]=='.'){
            a[row][col]='.'; a[row-1][col-1]='.'; a[row-2][col-2]='B';
            int tmp=1+solve(row-2,col-2,a);
            a[row][col]='B'; a[row-1][col-1]='P'; a[row-2][col-2]='.';
            ans=max(ans,tmp);
        }
    }
    // DR
    if(row+1<n && col+1<n && a[row+1][col+1]=='P'){
        if(row+2<n && col+2<n && a[row+2][col+2]=='.'){
            a[row][col]='.'; a[row+1][col+1]='.'; a[row+2][col+2]='B';
            int tmp=1+solve(row+2,col+2,a);
            a[row][col]='B'; a[row+1][col+1]='P'; a[row+2][col+2]='.';
            ans=max(ans,tmp);
        }
    }
    // DL
    if(row+1<n && col-1>=0 && a[row+1][col-1]=='P'){
        if(row+2<n && col-2>=0 && a[row+2][col-2]=='.'){
            a[row][col]='.'; a[row+1][col-1]='.'; a[row+2][col-2]='B';
            int tmp=1+solve(row+2,col-2,a);
            a[row][col]='B'; a[row+1][col-1]='P'; a[row+2][col-2]='.';
            ans=max(ans,tmp);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >>n;
    vector<string> a(n);
    for(auto &x : a) cin >> x;

    int ans=0;
    for(int row=0 ; row<n ; row++){
        for(int col=0 ; col<n ; col++){
            if(a[row][col] == 'B'){
                int tmp=solve(row,col,a);
                ans=max(ans,tmp);
            }
        }
    }
    cout<< ans <<"\n";

    return 0;
}