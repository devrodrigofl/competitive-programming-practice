// https://judge.beecrowd.com/pt/problems/view/2463

// g++ corredor-2463.cpp -o corredor-2463 && ./corredor-2463

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
    vector<int> corredor(n);

    for (int i = 0; i < n; i ++) {
        cin >> corredor[i];
    }

    int max_global = 0;
    int max_atual = corredor[0];

    for (int i = 1; i < n; i ++) {
        max_atual = max(corredor[i], max_atual + corredor[i]);
        max_global = max(max_global, max_atual);
    }

    cout << max_global << endl;

    return 0;
}