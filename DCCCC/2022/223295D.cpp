#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll divisor(ll n) {
    if (n % 2 == 0) return n/2;
    for (ll i = 3; i*i < n; i+=2) {
        if (n % i == 0) return n/i;
    }
    return 1;
}

int main(){ _ 
    ll n, m; cin >> n >> m;
    while (n != 1 && m != 1) {
        n = divisor(n);
        m = divisor(m);
    }

    cout << (n == 1 ? "mich" : "np") << endl;
    return 0;
}