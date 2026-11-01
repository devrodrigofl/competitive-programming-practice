#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
int cont;

int find(int x) {return id[x] = (id[x] == x ? x : id[x]);}

void une(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    id[x] = y; sz[y] += sz[x]; 
}

int main(){ _ 
    int n, m; cin >> n >> m;
    id = vector<int>(n+1);
    sz = vector<int>(n+1, 1);
    vector<vector<int>> matriz(n+1);
    iota(id.begin(), id.end(), 0);
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        une(x, y);
        matriz[x].push_back(y);
        matriz[y].push_back(x);
    }
    
    return 0;
}