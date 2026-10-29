#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> num(n);
    vector<int> pref(n);
    for (int& x : num) cin >> x;
    pref[0] = num[0];
    unordered_map<int,int> um;
    um[num[0]] = 0;
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] xor num[i];
        if(pref[i] == 0) {
            cout << 1 << " " << i+1 << endl; 
            return 0;
        }
        if(um.count(pref[i]) > 0) {
            cout << um[pref[i]] + 2 << " " << i+1 << endl; 
            return 0;
        }
        um[pref[i]] = i;
    }
    cout << -1 << endl;
    return 0;
}