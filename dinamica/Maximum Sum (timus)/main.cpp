#include <bits/stdc++.h>

using namespace std;
#define LIMN 100
int dp[LIMN+5][LIMN+5]; //suma partiala pe matrici
int N, a;
int main() {
    cin >> N;
    for (int i = 1; i <= N; ++ i) {
        for ( int j = 1; j <= N; ++ j) {
            cin >> a;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a;
        }
    }
    int S = -1, Smax = -1e9;
    for ( int i = 1; i <= N; ++ i) {
        for ( int j = i; j <= N; ++ j) {
            S = 0;
            for ( int k = 1; k <= N; k ++ ) {
                if ( S < 0 ) {
                    S = dp[j][k] - dp[j][k-1] - dp[i-1][k] + dp[i-1][k-1];
                }
                else S += dp[j][k] - dp[j][k-1] - dp[i-1][k] + dp[i-1][k-1];
                if ( S > Smax ) Smax = S;
            }
        }
    }
    cout << Smax;
    return 0;
}