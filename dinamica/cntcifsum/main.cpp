#include <bits/stdc++.h>

using namespace std;

const int MOD = 666013;
const int MAXN = 1000;
const int MAXK = 9000;

//
int N, K;
int dp[MAXN + 5][MAXK + 5 ]; //nr de numere cu i cifre care au suma j

int main () {
    cin >> N >> K;
    for ( int i = 1; i <= 9; ++ i  ) {
        dp[i][i] = 1;
    }
    return 0;
}
