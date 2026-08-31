// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tempo_max;
    cin >> n >> tempo_max;
    vector<int> competidores(n);
    for(int &tempo_chegada : competidores) {
        cin >> tempo_chegada;
    }

    int onibus = 0;
    int tempo_inicial = 0;
    int aux;
    for(int i = 0; i < n ; i++) {
        if(competidores[i] <= tempo_inicial + tempo_max) {
            aux++;
        }
        if (aux > 0 && competidores[i] > tempo_inicial + tempo_max) {
            aux = 0;
            tempo_inicial += tempo_max;
            onibus++;
        }
    }
    cout << onibus;


    return 0;
}