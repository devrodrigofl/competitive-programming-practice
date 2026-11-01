#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n, m; cin >> n;
    unordered_map<string, bool> nomes;
    for(ll i = 0; i < n; i++) {
        string s; cin >> s;
        nomes[s] = true;
    }
    cin >> m;
    vector<string> candidatos;
    for(ll i = 0; i < m; i++) {
        string s; cin >> s;
        int tam = s.length();
        if(tam > 5 and s[tam-1] == 'n' and s[tam-2] == 'o' and s[tam-3] == 's' and s[tam-4] == 'l' and s[tam-5] == 'i'){
            if(nomes.count(s) == 0) candidatos.push_back(s);
        }
    }
    cout << candidatos.size() << endl;
    for(auto c:candidatos) cout << c << endl;
    return 0;
}