// https://olimpiada.ic.unicamp.br/pratique/p2/2017/f2/mapa/

// mapa.cpp -o mapa && ./mapa

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 

    int line, column;
    cin >> line >> column;
    vector<vector<char>> mapa(line);
    queue<pair<int, int>> fila;
    vector<vector<bool>> i_was_here_before(line, vector<bool>(column, false));

    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++) {
            char x;
            cin >> x;
            mapa[i].push_back(x);
            if (x == 'c') {
                fila.push({i, j});
                i_was_here_before[i][j] = true;
            }
        }        
    }

    bool is_movable = true;

    while (!fila.empty()) {
        pair<int, int> current_cell = fila.front();
        fila.pop();

        for (int i = 0; i < line; i++) {
            for (int j = 0; j < column; j++) {
                if (i_was_here_before[i][j] == true) continue;

            }
        }
    }

    
    return 0;
}


// HHHH
// H...
// o.HH