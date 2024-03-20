#include <bits/stdc++.h>

using namespace std;

ifstream fin ("vladut.in");
ofstream fout ("vladut.out");

int N, T, e[101][101], o[101][101];
int dp[101][101];
int t;

void test() {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = 1; j <= N; ++ j ) {
            fin >> o[i][j];
        }
    }
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = 1;j <= N; ++ j ) {
            fin >> e[i][j];
        }
    }
    for ( int i = 1; i <= N; ++ i) {
        for ( int j = 1; j <= N; ++ j ) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + o[i][j] - e[i][j];
        }
    }
    int S = -1, Smax = -1e9;
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = i; j <= N; ++ j ) {
            S = 0;
            for ( int k = 1; k <= N; ++ k ) {
                if ( S < 0 ) {
                    S = dp[j][k] - dp[j][k-1] - dp[i-1][k] + dp[i-1][k-1];
                }
                else S += dp[j][k] - dp[j][k-1] - dp[i-1][k] + dp[i-1][k-1];
                if ( S > Smax ) Smax = S;
            }
        }
    }
    fout << ++t << ":" << Smax << '\n';
}

int main()
{
    fin >> T;
    while ( T -- ) {
        test();
    }
    return 0;
}