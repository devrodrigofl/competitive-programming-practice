#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// g++ -Wall -Wextra -Wshadow barras.cpp -o barras && ./barras

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int max_h = 0;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        max_h = max(max_h, x[i]);
    }
    
    for(int i = max_h; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            if(x[j] >= i) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }

    return 0;
}
