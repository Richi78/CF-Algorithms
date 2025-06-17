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

struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node *root;
    public:
    Trie(){
        root = new Node();
    }
    // tc -> O(len)
    void insert(string word){
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node()); 
            } 
            // moves to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    // tc -> O(len)
    bool search(string word){
        Node* node = root;
        for(int i=0 ; i<word.size() ; i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    // tc -> O(len)
    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0 ; i<prefix.size() ; i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

void solve(){
    string s1="asdf" , s2="asdf" , s3="asx";
    Trie t;
    t.insert(s1);

    bool x=t.search(s2);
    cout<<x<<"\n";

    bool y=t.startsWith(s3);
    cout<<y<<"\n";
}

signed main(){
    FIO;
    // int tc;cin>>tc;
    // while(tc--)solve();
    solve();
}