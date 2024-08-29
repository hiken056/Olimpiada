#include <bits/stdc++.h>

using namespace std;

int N;
long long dp[47]; //fibo * 2


int main () {
    cin >> N;
    dp[1] = 2;
    dp[2] = 2;
    for ( int i = 3; i <= N; ++ i ) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N] << '\n';
    return 0;
}
