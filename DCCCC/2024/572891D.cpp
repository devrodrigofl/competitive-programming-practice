// https://codeforces.com/group/xR6OpxQBMc/contest/572891/problem/D

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
int comp;

int find(int p){ return id[p] = (id[p] == p? p: find(id[p])); }

void une(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
    comp--;
}

int main(){ _ 
    int n, a; cin >> n;
    map<int,int> io;
    comp = n;
    id = vector<int>(n+1);
    sz = vector<int>(n+1, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 1; i <= n; i++) {
        cin >> a;
        io[i]++;
        io[a]--;
        une(i, a);
    }

    if(comp > 1) {cout << "No" << endl; return 0;}
    
    for(int i = 1; i <= n; i++) {
        if(io[i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}