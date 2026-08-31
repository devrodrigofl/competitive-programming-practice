// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> andares(N);
    for(int &andar : andares) cin >> andar;

    int tempo = 0;

    for(int i = 1; i < N; i++) {
        if (andares[i - 1] < andares[i]) {
            tempo += andares[i] - andares[i - 1];
        } else tempo += andares[i - 1] - andares[i];
    }

    cout << tempo << endl;

    return 0;
}