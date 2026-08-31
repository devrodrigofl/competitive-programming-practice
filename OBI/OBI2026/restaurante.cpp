// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g1, g2, g3, g4;
    cin >> g1 >> g2 >> g3 >> g4;
    int min_mesas = 0;

    min_mesas += g4;

    min_mesas += g3;
    g1 -= g3;
    if (g1 < 0) g1 = 0;

    if(g2 % 2 == 0) {
        min_mesas += (g2/2);
    } else {
        min_mesas += (g2 - 1) / 2;
        g2 = 1;
        if(g1 <= 2) {
            min_mesas += g2;
        } else {
            min_mesas += g2;
            g1 -= 2;
        }
    }

    if (g1 % 4 >= 1) {
        min_mesas += 1 + g1/4;
    } else min_mesas += g1/4;

    cout << min_mesas;

    return 0;
}