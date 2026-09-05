// https://codeforces.com/gym/101149/problem/L

// g++ 101149L.cpp -o 101149L && ./101149L

// #include <bits/stdc++.h>
#include "../bits/stdc++.h"

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// RESOLUÇÃO PARA GRAFO BIDIRECIONAL

// int main(){ _ 

//     int n, m, a, b;
//     cin >> n >> m >> a >> b;
//     vector<vector<int>> adj(n + 1);
    
//     for (int i = 0; i < m; i++) {
//         int x, y; cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
    
//     queue<int> fila;
//     vector<bool> seen(n+1, false);
//     vector<int> father(n+1, 0);
//     fila.push(0);
//     seen[0] = true;

//     int closer;
//     int dest;

//     while(!fila.empty()) {
//         int current_node = fila.front();
//         fila.pop();

//         if(current_node == a) {
//             closer = a;
//             dest = b;
//             break;
//         }
//         if(current_node == b) {
//             closer = b;
//             dest = a;
//             break;
//         }

//         for(auto& x : adj[current_node]) {
//             if(seen[x] == false) {
//                 fila.push(x);
//                 seen[x] = true;
//                 father[x] = current_node;
//             }
//         }
//     }

//     queue<int> fila2;
//     vector<bool> seen2(n+1, false);
//     vector<int> father2(n+1, 0);
//     fila2.push(closer);
//     seen2[closer] = true;

//     while(!fila2.empty()) {
//         int current_node = fila2.front();
//         fila2.pop();

//         if(current_node == dest) break;

//         for(auto& x : adj[current_node]) {
//             if(seen2[x] == false) {
//                 fila2.push(x);
//                 seen2[x] = true;
//                 father2[x] = current_node;
//             }
//         }
//     }

//     set<int> s;
//     s.insert(closer);
//     int son = closer;

//     while(true) {
//         s.insert(father[son]);
//         if (son == 0) break;
//         son = father[son];
//     }

//     s.insert(dest);
//     son = dest;
//     while(true) {
//         s.insert(father2[son]);
//         if (son == closer) break;
//         son = father2[son];
//     }

//     cout << s.size() - 1 << endl;

//     return 0;
// }

vector<int> bfs(int src, int n, vector<vector<int>>& adj) {
    vector<int> dist(n + 1, INF);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main(){ _

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n + 1), radj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }

    vector<int> d0 = bfs(0, n, adj);
    vector<int> da = bfs(a, n, radj);
    vector<int> db = bfs(b, n, radj);

    int ans = INF;
    for (int v = 0; v <= n; v++) {
        if (d0[v] < INF && da[v] < INF && db[v] < INF) {
            ans = min(ans, d0[v] + da[v] + db[v]);
        }
    }

    cout << ans << endl;
    return 0;
}