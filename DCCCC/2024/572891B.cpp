#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> fila;
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 0);
    vector<bool> star(n+1, false);
    int contador = 0;
    unordered_map<int, bool> niveis;

    fila.push(1);
    visited[1] = true;
    int current_node;

    while(!fila.empty()) {
        current_node = fila.front();
        fila.pop();
        for(int x : adj[current_node]) {
            if (visited[x] == true) continue;
            dist[x] = dist[current_node] + 1;
            niveis[dist[x]] = true;
            visited[x] = true;
            fila.push(x);
        }
    }

    fila.push(1);
    vector<int> visited2(n+1, false);
    visited2[1] = true;
    niveis[0] = true;
    while(!fila.empty()) {
        current_node = fila.front();
        fila.pop();
        if(star[current_node] == false and niveis[dist[current_node]] == true) {
            niveis[dist[current_node]] = false;
            contador++;
            star[current_node] = true;
            for(int x : adj[current_node]) {
                if (visited2[x] == true) continue;
                visited2[x] = true;
                fila.push(x);
                star[x] = true;
            }
        }
        else{
            for(int x : adj[current_node]) {
                if (visited2[x] == true) continue;
                visited2[x] = true;
                fila.push(x);
            }
        }

    }

    cout << contador << endl;
    
    return 0;
}