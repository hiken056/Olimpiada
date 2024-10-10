#include <bits/stdc++.h>

using namespace std;

ifstream fin ("alice_xi.in");
ofstream fout ("alice_xi.out");

const int MAXN = 40;
long long n, dp[MAXN][MAXN], s;

int main () {
    fin >> n;
    for ( int i = 1; i <= n; ++ i ) {
        for ( int j = 1; j <= n; ++ j ) {
            if ( i >= j ) {
                if ( i == 1 && j == 1 ) dp[i][j] = 1;
                else {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                }
            }
            if ( i == n ) s += dp[i][j];
        }
    }

    // for ( int i = 1; i <= n; ++ i ) {
    //     for ( int j = 1;  j <= n; ++ j ) {
    //         fout << dp[i][j] << " ";
    //     }
    //     fout << '\n';
    // }
    fout << s;
    return 0;
}