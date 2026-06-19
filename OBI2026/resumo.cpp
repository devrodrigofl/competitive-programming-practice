#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// g++ -Wall -Wextra -Wshadow resumo.cpp -o resumo && ./resumo

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, novo_num;
    int resumo = 0;
    int tam = 0;
    int par = 0;
    int impar = 0;
    cin >> n;

    if (n > 99999999) tam = 9;
    else if (n > 9999999) tam = 8;
    else if (n > 999999) tam = 7;
    else if (n > 99999) tam = 6;
    else if (n > 9999) tam = 5;
    else if (n > 999) tam = 4;
    else if (n > 99) tam = 3;
    else if (n > 9) tam = 2;
    else tam = 1;

    vector<int> num(tam);
    int aux = 10;
    for (int i = 0; i < tam; i++) {
        num[i] = n % aux / (aux/10);
        aux *=10;
        if(num[i] % 2 == 0) {
            par++;
        } else impar++;
    }

    novo_num = (tam * 100) + (impar * 10) + par;
    if(novo_num == n) {
        cout << 0 << "\n";
        return 0;
    }

    int num_anterior = n;
    while(novo_num != num_anterior) {
        num[0] = tam;
        num[1] = impar;
        num[2] = par;

        tam = 3;
        impar = 0;
        par = 0;

        if(num[0] % 2 == 0) {
            par++;
        } else impar++;

        if(num[1] % 2 == 0) {
            par++;
        } else impar++;

        if(num[2] % 2 == 0) {
            par++;
        } else impar++;

        resumo++;
        novo_num = (tam * 100) + (impar * 10) + par;
        if (novo_num == num_anterior) {
            break;
        } else {
            num_anterior = (tam * 100) + (impar * 10) + par;
            novo_num = 0;
        }

    }

    cout << resumo << "\n";

    return 0;
}