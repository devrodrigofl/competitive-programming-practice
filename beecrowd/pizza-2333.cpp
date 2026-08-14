// https://judge.beecrowd.com/en/problems/view/2333

// g++ pizza-2333.cpp -o pizza && ./pizza

#include "../bits/stdc++.h"

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 

    int n;
    cin >> n;

    vector<int> pizza(n);

    for (int i = 0; i < n; i++) {
        cin >> pizza[i];
    }

    int max_global = 0;
    int max_atual = pizza[0];
    int min_global = 0;
    int min_atual = pizza[0];
    int total = pizza[0];

    for (int i = 1; i < n; i++) {
        total += pizza[i];

        max_atual = max(pizza[i], max_atual + pizza[i]);
        max_global = max(max_global, max_atual);

        min_atual = min(pizza[i], min_atual + pizza[i]);
        min_global = min(min_global, min_atual);
    }

    if (max_global < 0) cout << 0 << endl;
    else cout << max(max_global, total - min_global) << endl;

    return 0;
}