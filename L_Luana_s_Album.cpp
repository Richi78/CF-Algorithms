// #include <bits/stdc++.h>

// using namespace std;

// vector<int> LIS(vector<int> &a){
//     int n=a.size();
//     vector<int> dp;
//     vector<int> pos(n);
//     vector<int> parent(n, -1);

//     for(int i=0 ; i<n ; i++){
//         int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
//         if(idx == dp.size()) dp.push_back(a[i]);
//         else dp[idx]=a[i];
//         if(idx > 0)
//             parent[i] = pos[idx-1];
//         pos[idx] = i;
//     }

//     vector<int> lis;
//     int cur = pos[dp.size()-1];
//     while(cur != -1){
//         lis.push_back(a[cur]);
//         cur = parent[cur];
//     }
//     reverse(lis.begin(), lis.end());
//     return lis;
// }


// vector<int> LIS2(vector<int> &a, int limit){
//     if(a.size() == 0) return {};
//     int n=a.size();
//     vector<int> dp;
//     vector<int> pos(n);
//     vector<int> parent(n, -1);

//     for(int i=0 ; i<n ; i++){
//         if(a[i] <= limit) continue;
//         int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
//         if(idx == dp.size()) dp.push_back(a[i]);
//         else dp[idx]=a[i];
//         if(idx > 0)
//             parent[i] = pos[idx-1];
//         pos[idx] = i;
//     }

    
//     vector<int> lis;
//     if(dp.size() == 0) return lis;
//     int cur = pos[dp.size()-1];
//     while(cur != -1){
//         lis.push_back(a[cur]);
//         cur = parent[cur];
//     }
//     reverse(lis.begin(), lis.end());
//     return lis;
// }

// int main(){
//     int n,m; cin >> n >> m;
//     vector<int> a(n);
//     for(int &x : a) cin >> x;

//     vector<int> copy_a(a.rbegin(), a.rend());

//     pair<int,int> ans1;
//     {
//         vector<int> lis = LIS(a);
    
//         vector<int> lis2 = LIS2(copy_a, lis.back());


//         ans1.first=lis.size(), ans1.second=1;
//         if(lis2.size() > 0){
//             ans1.first+=lis2.size(), ans1.second=2;
//         }
//     }

//     pair<int,int> ans2;
//     {
//         vector<int> lis = LIS(copy_a);
    
//         vector<int> lis2 = LIS2(a, lis.back());


//         ans2.first=lis.size(), ans2.second=1;
//         if(lis2.size() > 0){
//             ans2.first+=lis2.size(), ans2.second=2;
//         }
//     }

//     pair<int,int> ans;

//     if(ans1.first > ans2.first){
//         ans=ans1;
//     }else if( ans1.first < ans2.first){
//         ans=ans2;
//     }else if(ans1.second <= ans2.second){
//         ans=ans1;
//     }else{
//         ans=ans2;
//     }
//     cout<< ans.first <<" "<<ans.second<<"\n";
// }

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i], a[i]--;
    auto b = a;
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    std::cout << b.size() << " ";
    std::vector<std::vector<int>> o1(m), o2(m);
    for (int i = 0; i < n; i++) o1[a[i]].push_back(i);
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) o2[a[i]].push_back(i);
    int ans = 0;
    for (int i = 0; i < b.size(); ) {
        int max = 0;
        {
            for (int j = i, p = 0; j < b.size(); j++) {
                auto it = std::lower_bound(o1[b[j]].begin(), o1[b[j]].end(), p);
                if (it == o1[b[j]].end()) break;
                max = std::max(max, j - i + 1);
                p = *it + 1;
            }
        }
        {
            for (int j = i, p = 0; j < b.size(); j++) {
                auto it = std::lower_bound(o2[b[j]].begin(), o2[b[j]].end(), p);
                if (it == o2[b[j]].end()) break;
                max = std::max(max, j - i + 1);
                p = *it + 1;
            }
        }
        i += max;
        ans++;
    }
    std::cout << ans;
}