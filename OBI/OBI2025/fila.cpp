#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// g++ -Wall -Wextra -Wshadow fila.cpp -o fila && ./fila

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num_alunos;
    cin >> num_alunos;
    vector<int> fila(num_alunos);
    for(int &aluno : fila) cin >> aluno;

    int max_altura = 0;
    int num_escondidos = 0;

    for(int i = num_alunos - 1; i >= 0; i--) {
        if(fila[i] <= max_altura) num_escondidos++;
        else max_altura = fila[i];
    }

    cout << num_escondidos << endl;

    return 0;
}
