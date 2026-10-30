#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    long long n;
    cin >> n;
    int ans = INT_MAX;
    for (long long k = 1; k * k <= n; k++) {
        ans = min(ans, __builtin_popcountll(n ^ (k * k)));
        if (2 * k * k <= n) ans = min(ans, __builtin_popcountll(n ^ (2 * k * k)));
    }
    cout << ans << "\n";
    return 0;
}