// ========================
// Compilador online da OBI
// ========================

#include <bits/stdc++.h>
using namespace std;

int main() {
    // comandos para agilizar entrada/saída
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> num(4);
    cin >> n;
    vector<int> torre;
    torre.push_back(n);

    if(n < 10) {
        num[0]=(n % 10);
        num[1]=0;
        num[2]=0;
        num[3]=0;
    } else if (n < 100) {
        num[0]=(n % 10);
        num[1]=((n % 100) / 10);
        num[2]=0;
        num[3]=0;
    } else if (n < 1000) {
        num[0]=(n % 10);
        num[1]=((n % 100) / 10);
        num[2]=((n % 1000) / 100);
        num[3]=0;
    } else {
        num[0]=(n % 10);
        num[1]=((n % 100) / 10);
        num[2]=((n % 1000) / 100);
        num[3]=((n % 10000) / 1000);
    }
    

    while(true) {

        sort(num.begin(), num.end());

        int x2 = (num[3] * 1000) + (num[2] * 100) + (num[1] * 10) + num[0];
        int x1 = (num[0] * 1000) + (num[1] * 100) + (num[2] * 10) + num[3];
        if(x2 / 100 == 0) x2 *= 10;
        if(x1 / 100 == 0) x1 *= 10;

        int x = x2 - x1;

        if(find(torre.begin(), torre.end(), x) == torre.end()) {
            torre.push_back(x);
            n = x;
            if(n < 10) {
                num[0]=(n % 10);
                num[1]=0;
                num[2]=0;
                num[3]=0;
            } else if (n < 100) {
                num[0]=(n % 10);
                num[1]=((n % 100) / 10);
                num[2]=0;
                num[3]=0;
            } else if (n < 1000) {
                num[0]=(n % 10);
                num[1]=((n % 100) / 10);
                num[2]=((n % 1000) / 100);
                num[3]=0;
            } else {
                num[0]=(n % 10);
                num[1]=((n % 100) / 10);
                num[2]=((n % 1000) / 100);
                num[3]=((n % 10000) / 1000);
            }
            
        } else {
            for(int number : torre) {
                cout << number << endl;
            }
            break;
        }
    }


    return 0;
}