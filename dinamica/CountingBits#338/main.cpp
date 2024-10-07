#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, bit = 0, m = 0;
    cin >> n;
    int countBits[100005];
    for ( int i = 0; i <= n; ++ i ) {
        if ( bit <= m ) {
            countBits[i] = bit;
            bit ++;
        }
        else {
            countBits[i] = bit;
            bit = 1;
            m ++;
        }
        cout << countBits[i] << " ";
    }
    return 0;
}