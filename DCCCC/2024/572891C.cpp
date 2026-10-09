// https://codeforces.com/group/xR6OpxQBMc/contest/572891/problem/C

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<string> f(n), f2(n);
    for(int i = 0; i < n; i++) cin >> f[i];
    for(int i = 0; i < n; i++) cin >> f2[i];
    int count = 0;
    for(int i = 0; i < n; i++) {
        int a = f2[i].size() - f[i].size();
        if(a != 0) count += a/2;
    }
    cout << count << endl;
    return 0;
}