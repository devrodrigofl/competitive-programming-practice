// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d1, d2, d3, d4, d5;
    cin >> d1 >> d2 >> d3 >> d4 >> d5;

    cout << (d1*16) + (d2*8) + (d3*4) + (d4*2) + (d5*1);

    return 0;
}