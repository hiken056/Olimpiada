#include <bits/stdc++.h>

using namespace std;

//dp = nr de nr de i cifre cu suma j 

long long S;
long long dp[10][82];  

int main( ) {
    cin >> S;
    for ( int i = 1; i <= 9; ++ i ) {
        dp[1][i] = 1;
    }
    for ( int i = 2; i <= 9; ++ i ) {
        for ( int j = 1; j <= S; ++ j ) {
            for ( int k = 0; k <= 9; ++ k) {
                dp[i][j] += dp[i-1][j-k];
            }    
        }
    }
    long long s = 0;
    for ( int i = 1; i <= 9; ++ i ) {
        s += dp[i][S];
    }
    if ( S == 1 ) ++s;
    cout << s;
    return 0;
 }