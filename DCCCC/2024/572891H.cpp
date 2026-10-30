#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int>opcoes;
int n;

bool conseguiu = false;
void brute(int atual, int restante) {
    if(restante % 1440 == 0) {conseguiu = true; return;}
    if(atual == 2*n) return;
    brute(atual+1, restante-opcoes[atual]);
    brute(atual+1, restante); 
}

int main(){ _ 
    int hora; cin >> n >> hora;
    hora = 1440 - hora;
    vector<int> botoes(n); 
    for(int&x : botoes) cin >> x;
    opcoes = vector<int>(2*n);
    for(int i = 0; i < 2*n; i++) opcoes[i] = botoes[i%n];
    if(hora == 1440) {
        cout << "YES" << endl;
        return 0;
    }
    brute(0, hora);
    if(conseguiu) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}