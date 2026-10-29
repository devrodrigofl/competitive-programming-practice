#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> lam(n);
    for (int& x : lam) cin >> x;
    for (int i = 1; i < n-1; i++) {
        if (lam[i-1]) continue;
        lam[i-1] = (lam[i-1] == 1 ? 0 : 1);
        lam[i] = (lam[i] == 1 ? 0 : 1);
        lam[i+1] = (lam[i+1] == 1 ? 0 : 1);
    }
    if(lam[n-2] & lam[n-1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}