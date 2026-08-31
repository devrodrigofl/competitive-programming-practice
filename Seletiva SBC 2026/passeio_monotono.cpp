// https://codeforces.com/group/xR6OpxQBMc/contest/708429/problem/B

// g++ passeio_monotono.cpp -o passeio_monotono && ./passeio_monotono

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
    vector<string> grid(n);
    queue<pair<int, int>> fila;
    vector<vector<bool>> i_was_here_before(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        string linha;
        cin >> linha;
        grid[i] = linha;
    }

    fila.push({0, 0});
    i_was_here_before[0][0] = true;
    int dx[2] = {1, 0}, dy[2] = {0, 1};

    while(!fila.empty()) {
        pair<int,int> current_cell = fila.front();
        fila.pop();

        for (int i = 0; i < 2; i ++) {
            int x = current_cell.first + dy[i];
            int y = current_cell.second + dx[i];
            if (x >= n or x < 0 or y >= m or y < 0) continue;
            if (grid[x][y] == '#' and i_was_here_before[x][y] == false) {
                fila.push({x, y});
                i_was_here_before[x][y] = true;
                break;
            }
        }
    }

    if(!i_was_here_before[n-1][m-1]) {
        cout << "Impossivel" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#' and !i_was_here_before[i][j]) {
                cout << "Impossivel" << endl;
                return 0;
            }
        }
    }

    cout << "Possivel" << endl;

    return 0;
}