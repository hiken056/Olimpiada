#include <bits/stdc++.h>

using namespace std;

const int LIMN = 6e5;
int N, dp[LIMN + 5]; //nr minim de p.p scazute din N pt a ajunge la i

int main ( ) {
    cin >> N;

    for ( int s = N-1; s >= 0; --s ) {
        dp[s] = 1e9;
        for (  int p = 1; p * p + s <= N; ++ p) {
            
            dp[s] = min(dp[s + p * p] + 1, dp[s]);
        }
    }
    cout << dp[0];
    return 0;
}