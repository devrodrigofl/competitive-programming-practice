#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll fatorial(ll n) {
    ll soma = 1;
    while (n >= 1) {
        soma *= n;
        n--;
    }
    return soma;
}

int main(){ _ 
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= k; i++) ans += (fatorial(n + i - 1)/(fatorial(i)*fatorial(n - 1)));
    cout << ans << endl;
    return 0;
}