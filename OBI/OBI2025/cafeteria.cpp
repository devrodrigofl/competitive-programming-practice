#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// g++ -Wall -Wextra -Wshadow cafeteria.cpp -o cafeteria && ./cafeteria

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vol_minimo, vol_maximo, capacidade, tam_dose;
    cin >> vol_minimo >> vol_maximo >> capacidade >> tam_dose;

    int min_cafe = capacidade - vol_maximo;
    int max_cafe = capacidade - vol_minimo;
    int resto = max_cafe % tam_dose;

    if(resto == 0 || max_cafe - resto >= min_cafe) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }
    
    return 0;
}
