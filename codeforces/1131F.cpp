#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id;

int find(int x) {return id[x] = (id[x] == x ? x : find(id[x]));}

int main(){ _ 

    int n; cin >> n;
    id = vector<int>(n+1);
    iota(id.begin(), id.end(), 0);
    vector<int> head(n+1), tail(n+1), nxt(n+1, 0);
    for (int i = 1; i <= n; i++) head[i] = tail[i] = i;

    int x, y, a, b;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        a = find(x), b = find(y);
        nxt[tail[a]] = head[b];
        tail[a] = tail[b];
        id[b] = a;
    }

    for (int cur = head[find(1)]; cur != 0; cur = nxt[cur]) cout << cur << " ";
    cout << endl;

    return 0;
}