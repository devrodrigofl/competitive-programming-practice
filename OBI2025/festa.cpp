#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// g++ -Wall -Wextra -Wshadow festa.cpp -o festa && ./festa

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e, s, l;
    cin >> e >> s >> l;

    if(e < s && e < l) {
        if(s < l) cout << 2 * (l - e) << endl;
        else cout << 2 * (s - e) << endl;
    } else if (l < e && e < s) {
        cout << (2 * (s - e)) + (2 * (e - l)) << endl;
    } else if (s < e && e < l) {
        cout << (2 * (l - e)) + (2 * (e - s)) << endl;
    } else if(s < e && l < e) {
        if(s < l) cout << 2 * (e - s) << endl;
        else cout << 2 * (e - l) << endl;
    }
    return 0;
}
