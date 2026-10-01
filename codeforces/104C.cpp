// https://codeforces.com/problemset/problem/104/C

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> adj;

bool dfs() {
    
}

int main(){ _

    int n, m, a, b;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    



    return 0;
}