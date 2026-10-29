#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> pessoas(n+1);
    for(int i = 1; i < n+1; i++) cin >> pessoas[i];
    
    vector<vector<int>> matriz(n+1);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        matriz[x].push_back(y);
        matriz[y].push_back(x);
    }

    queue<int> q;
    vector<bool> v(n+1, false);
    vector<int> d(n+1, 0);

    q.push(1);
    v[1] = true;

    while(!q.empty()) {
        int primeiro = q.front();
        q.pop();
        for(int x : matriz[primeiro]) {
            if(v[x] == true) continue;  
            q.push(x);
            v[x] = true;
            d[x] = d[primeiro] + 1;
        }
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; i++) pq.push({d[i], i});

    vector<int> acumulados;

    while(!pq.empty()) {
        auto[prof, idx] = pq.top();
        pq.pop();
        for(int x : matriz[idx]) {
            if(prof <= d[x]) continue;
            acumulados.push_back(pessoas[idx]);
            pessoas[x] += pessoas[idx];
        }
    }

    sort(acumulados.begin(), acumulados.end());

    for(int& x : acumulados) cout << x << " ";
    cout << endl;
    
    return 0;
}