#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, d; cin >> n >> d;
    int contador = 0;
    ll anterior = 0;
    cin >> anterior;
    for(int i = 1; i < n; i++) {
        int x = 0;
        cin >> x;
        if(abs(x-anterior) > d) contador++;
        anterior = x;
    }
    cout << contador << endl;
    return 0;
}