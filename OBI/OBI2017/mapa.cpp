// https://olimpiada.ic.unicamp.br/pratique/p2/2017/f2/mapa/

// g++ mapa.cpp -o mapa && ./mapa

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
    vector<string> mapa(line);
    queue<pair<int, int>> fila;
    vector<vector<bool>> i_was_here_before(line, vector<bool>(column, false));

    for (int i = 0; i < line; i++) {
        string x;
        cin >> x;
        mapa[i] = x;
        for (int j = 0; j < column; j++) {
            if (mapa[i][j] == 'o') {
                fila.push({i, j});
                i_was_here_before[i][j] = true;
            }
        }
    }

    int dx[4] = {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};

    while (!fila.empty()) {
        pair<int, int> current_cell = fila.front();
        fila.pop();

        for (int i = 0; i < 4; i++) {
            int x = current_cell.first + dy[i];
            int y = current_cell.second + dx[i];
            if (x >= line or x < 0 or y >= column or y < 0) continue;
            if (mapa[x][y] == 'H' and i_was_here_before[x][y] == false) {
                fila.push({x, y});
                i_was_here_before[x][y] = true;
            }
        }

        if(fila.empty()) cout << current_cell.first + 1 << " " << current_cell.second + 1 << endl;
    }

    return 0;
}