// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, fichas;
    cin >> x;

    if(x % 10 == 0) {
        fichas += x/10;
        x = 0;
    } else {
        fichas = x/10;
        x = x % 10;
    }
    if(x % 5 == 0 && x != 0) {
        fichas += x / 5;
        x = 0;
    }
    else if(x % 5 != 0 && x != 0) {
        fichas += x/5;
        x = x % 5;
    }
    if(x % 2 == 0 && x != 0) {
        fichas += x/2;
        x = 0;
    }
    else if(x % 2 != 0 && x != 0) {
        fichas += x/2;
        x = x % 2;
    }
    fichas += x;

    cout << fichas;

    return 0;
}