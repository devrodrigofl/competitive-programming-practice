// https://cses.fi/problemset/task/1667

// g++ message_route.cpp -o message_route && ./message_route

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matriz_adj(n+1);
    vector<bool> i_was_here_before(n+1, false);
    vector<int> father(n+1);
    vector<int> print;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        matriz_adj[a].push_back(b);
        matriz_adj[b].push_back(a);
    }
    
    queue<int> fila;
    fila.push(1);
    i_was_here_before[1] = true;
    father[1] = 0;

    while (!fila.empty()) {
        int current_node = fila.front();
        fila.pop();
        if (current_node == n) break;
        
        for (auto& x : matriz_adj[current_node]) {
            if (i_was_here_before[x] == true) continue;
            fila.push(x);
            i_was_here_before[x] = true;
            father[x] = current_node;
        }
    }

    if (i_was_here_before[n] == false) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    print.push_back(n);

    while (true) {
        print.push_back(father[n]);
        n = father[n];
        if (father[n] == 0) {
            break;
        }
    }

    cout << print.size() << endl;
    reverse(print.begin(), print.end());

    for (int i = 0; i < print.size(); i++) {
        cout << print[i];
        if (i != print.size() - 1) cout << " ";
        else cout << endl;
    }

    return 0;
}