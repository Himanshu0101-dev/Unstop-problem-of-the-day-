#include <bits/stdc++.h>
using namespace std;

int shortestGrab(string belt, unordered_map<char,int>& need) {
    int n = belt.size();
    
    // Check if belt has enough of each required type
    unordered_map<char,int> total;
    for(char c : belt) total[c]++;
    for(auto &p : need) {
        if(total[p.first] < p.second) return -1;
    }
    
    unordered_map<char,int> have;
    int satisfied = 0, required = need.size();
    int res = INT_MAX;
    
    int left = 0;
    for(int right = 0; right < n; right++) {
        char c = belt[right];
        if(need.count(c)) {
            have[c]++;
            if(have[c] == need[c]) satisfied++;
        }
        
        while(satisfied == required) {
            res = min(res, right - left + 1);
            char lc = belt[left];
            if(need.count(lc)) {
                if(have[lc] == need[lc]) satisfied--;
                have[lc]--;
            }
            left++;
        }
    }
    return (res == INT_MAX ? -1 : res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string belt;
    cin >> belt;
    
    unordered_map<char,int> need;
    for(int i=0; i<m; i++) {
        char comp; int cnt;
        cin >> comp >> cnt;
        need[comp] = cnt;
    }
    
    cout << shortestGrab(belt, need) << "\n";
    return 0;
}
