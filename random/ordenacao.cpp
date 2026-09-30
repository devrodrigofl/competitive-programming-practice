// g++ ordenacao.cpp -o ordenacao && ./ordenacao

// #include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define Troca(A, B) {int c = A; A = B; B = c;}

void bolha(int *v, int n) {
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n - i; j++)
            if (v[j] < v[j-1])
                Troca(v[j-1], v[j]);
        cout << "Passada " << i+1 << ": "; 
        for(k = 0; k < n; k++) 
            cout << v[k] << " ";
        cout << endl;
    }
}

void selecao(int *v, int n) {
    int i, j, Min, k;
    for (i = 0; i < n - 1; i++) {
        Min = i;
        for (j = i + 1; j < n; j++)
        if (v[j] < v[Min])
            Min = j;
        Troca(v[i], v[Min]);
        cout << "Passada " << i+1 << ": "; 
        for(k = 0; k < n; k++) 
            cout << v[k] << " ";
        cout << endl;
    }
}

int main(){ _ 

    int v[6] = {5, 2, 4, 6, 1, 3};
    int n = 6;
    
    cout << endl << "Bolha" << endl << endl;

    cout << "Original:  ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    bolha(v, n);
    
    cout << "Resultado: ";
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;

    int v2[6] = {5, 2, 4, 6, 1, 3};

    cout << endl << "Seleção" << endl << endl;

    cout << "Original:  ";
    for(int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    selecao(v2, n);

    cout << "Resultado: ";
    for(int i = 0; i < n; i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    return 0;
}