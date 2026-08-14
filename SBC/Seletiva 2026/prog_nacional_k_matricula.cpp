#include <bits/stdc++.h>

using namespace std; 

#define endl "\n" 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, a, x;
    cin >> m >> a;
    
    vector<int> vagas;
    vector<vector<int>> alunos;
    vector<vector<int>> matriculas;
    
    for (int i = 0; i < m; i++) {
        cin >> x;
        vagas.push_back(x);
    }
    
    for (int i = 0; i < a; i++) {
        cin >> x;
        alunos[i].push_back(x);
        cin >> x;
        alunos[i].push_back(x);
        for (int j = 0; j < alunos[i][1]; j++) {
            cin >> x;
            alunos[i].push_back(x);
        }
    }
    
    bool ok = true;
    
    for (int i = 0; i < a; i++) {
        for (int j = 2; j < sizeof(alunos[i]); j++) {
            for (int k = 2; k < sizeof(alunos[i]); k++) {
                if(vagas[alunos[i][k]] > 0) {
                    ok = true;
                    continue;
                } else {
                    ok = false;
                    break;
                }    
            }
            if(ok == true) {
                matriculas[alunos[i][j]].push_back(alunos[i][0]);
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << m << " ";
        for (int j = 0; j < sizeof(matriculas[i]); j++) {
            cout << matriculas[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
