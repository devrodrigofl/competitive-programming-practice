#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// int main(){ _ 
//     int n, maior; cin >> n;
//     maior = 1;
//     vector<int> contadores(n, 1);
//     vector<int> vetor(n);
//     for(int i = 0; i < n; i++) cin >> vetor[i];
//     for(int i = n-2; i >=0; i--){
//         if(n - vetor[i] < vetor[i]) continue;
//         for(int j = i+1; j < n; j++){
//             if(vetor[j] % vetor[i] == 0){
//                 contadores[i] = max(contadores[i], contadores[j]+1);
//                 maior = max(maior, contadores[i]);
//             } 
//         }
//     }
//     cout << maior << endl;
//     return 0;
// }

int main(){ _
    int n; cin >> n;
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pos[x] = i;
    }
    vector<int> dp(n + 1, 1);
    int maior = 1;
    for(int v = n; v >= 1; v--){
        for(int m = 2 * v; m <= n; m += v){
            if(pos[m] > pos[v]) dp[v] = max(dp[v], dp[m] + 1);
        }
        maior = max(maior, dp[v]);
    }
    cout << maior << endl;
    return 0;
}