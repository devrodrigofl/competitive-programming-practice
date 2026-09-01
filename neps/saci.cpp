// https://neps.academy/br/exercise/57

// g++ saci.cpp -o saci && ./saci

// #include <bits/stdc++.h>
#include "../bits/stdc++.h"

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    queue<pair<int, int>> fila;
    vector<vector<pair<int, int>>> father(n, vector<pair<int, int>>(m));
    vector<vector<bool>> i_was_here_before(n, vector<bool>(m, false));
    pair<int, int> exit;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int aux;
            cin >> aux;
            grid[i].push_back(aux);
            if (aux == 2) {
                fila.push({i, j});
                i_was_here_before[i][j] = true;
                father[i][j] = {-1, -1};
            }
            if (aux == 3) exit = {i, j};
        }
    }
    
    int dx[4] = {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};

    while (!fila.empty()) {
        pair<int, int> current_cell = fila.front();
        fila.pop();

        if (grid[current_cell.first][current_cell.second] == 3) break;

        for (int i = 0; i < 4; i++) {
            int x = current_cell.first + dy[i];
            int y = current_cell.second + dx[i];
            if (x >= n or x < 0 or y >= m or y < 0) continue;
            if ((grid[x][y] == 1 or grid[x][y] == 3) and i_was_here_before[x][y] == false) {
                fila.push({x, y});
                i_was_here_before[x][y] = true;
                father[x][y] = {current_cell.first, current_cell.second};
            }
        }
    }

    vector<pair<int, int>> path;
    
    while (true) {
        path.push_back(father[exit.first][exit.second]);
        exit = father[exit.first][exit.second];
        if (father[exit.first][exit.second] == pair<int, int>{-1, -1}) {
            break;
        }
    }

    cout << path.size() + 1 << endl;
    
    // // visualização da matriz de celulas pais
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << father[i][j].first << "," << father[i][j].second << "   ";
    //     }
    //     cout << endl;
    // }


    return 0;
}