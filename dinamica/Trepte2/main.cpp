#include <bits/stdc++.h>

using namespace std;

const int mod = 9001;
const int MAXN = 1e5 + 5;
int n, k, dp[MAXN];

int main () {
    cin >> n >> k;
    dp[0] = 1;
    dp[1] = 1;
    for ( int i = 2; i <= n; ++ i ){
        for ( int j = 1; j<= k && j < i ; ++ j ) {
            dp[i] += dp[i-j];
            dp[i] = dp[i] % mod;
        }
    }
    cout << dp[n];
    return 0; 
}