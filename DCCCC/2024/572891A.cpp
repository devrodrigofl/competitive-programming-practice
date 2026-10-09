//https://codeforces.com/group/xR6OpxQBMc/contest/572891/problem/A

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        mp[a] += 1;
    }
    int m; cin >> m;
    vector<int> p(m);
    for(int& a : p) {
        cin >> a;
    }
    sort(p.begin(), p.end());

    int count = 0;

    for(int i = 0; i < m; i++) {
        if (mp[p[i]] > 0) {
            mp[p[i]]--;
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}