#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool primo(ll n) {
    if(n%2 == 0 or n == 1) return false;
    for (ll i = 3 ; i*i <= n; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

int main(){ _ 
    ll n; cin >> n;
    while(true) {
        if (primo(++n)) {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}