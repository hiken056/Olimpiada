#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[20][20]; //nr de numere de i cifre cu ultima cif j

int main () {
    cin >> N >> K;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i ++ ){
        for ( int j = 0; j < K; j ++ ) {
            if ( j == 0 ) {
                for ( int k =  1; k < K; ++ k) {
                    dp[i][j] += dp[i-1][k];
                }
            }
            else {
                for ( int k = 0; k < K; ++ k ) {
                    dp[i][j] += dp[i-1][k];
                }
             }
        }
    }
    int S = 0;
    for ( int i = 0; i < K; i ++ ) {
        S += dp[N][i];
    }
    cout << S;
    return 0;
}