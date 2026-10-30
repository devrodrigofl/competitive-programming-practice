#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll fatorial(ll n) {
    ll soma =1;
    while(n>=1) {
        soma *= n;
        n--;
    }
    return soma;
}

int main(){ _ 
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        n--;m--;x--;y--;
        cout << (fatorial(n+m)/(fatorial(n)*fatorial(m))) - (fatorial(x+y)/(fatorial(y)*fatorial(x)) * (fatorial((n-x)+(m-y))/(fatorial(n-x)*fatorial(m-y)))) << endl;
    }
    return 0;
}