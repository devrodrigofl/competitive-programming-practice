// https://codeforces.com/problemset/problem/104/C

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> adj;
vector<int> father;
vector<bool> visited;
int cont = 0;

void dfs(int u, int f) {
    cout << u << endl;
    visited[u] = true;
    for(auto& x : adj[u]) {
        if(u == 9) cout << "x " << x << endl;
        if(visited[x] && x != f) {
            cont++;
            cout << "x: " << x << endl;
            cout << "u: " << u << endl;
        }

        if(!visited[x]) {
            dfs(x, u);}
    }
}

int main(){ _

    int n, m, a, b;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    father = vector<int>(n+1, 0);
    visited = vector<bool>(n+1, false);

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    if(cont == 1) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;

    return 0;
}