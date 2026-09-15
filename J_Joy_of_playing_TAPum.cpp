#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int n=s.size();
    if(n%3 != 0){
        cout<<"N\n"; return 0;
    }

    while(s.size() > 0){
        int op=0;
        string new_s="";
        for(int i=0 ; i<s.size() ; i++){
            char x=s[i] , y , z;
            if(i+1<s.size()){
                y=s[i+1];
            } else{
                new_s+=x; 
                break;
            } 
            if(i+2<s.size()){
                z=s[i+2];
            } else{
                new_s+=x; new_s+=y; 
                break;
            }
            if( x!=y && y!=z && x!=z){
                op++; i+=2;
            }else{
                new_s+=x; 
            }
        }
        s=new_s;
        if(op == 0){
            cout<<"N\n"; return 0;
        }
    }

    cout<<"S\n";

    return 0;
}