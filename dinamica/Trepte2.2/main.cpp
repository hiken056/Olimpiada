#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int mod = 9001;

int n, k, dp[MAXN], sp = 1;

//se foloseste sume partiale pentru a intra in timp

int main () {
    cin >> n >> k;
    dp[1] = 1;
    for ( int i = 2; i <= n; ++ i ) {
        dp[i] = sp;
        sp += dp[i];
        if ( i >= k ) sp-= dp[i-k];
        if ( sp < 0 ) sp += mod;
        if ( sp >= mod ) sp-= mod; 
    }
    cout << dp[n];

    return 0;
}