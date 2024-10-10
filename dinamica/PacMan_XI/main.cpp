#include <bits/stdc++.h>

using namespace std;

ifstream fin ("pacman_xi.in");
ofstream fout ("pacman_xi.out");

const int MAXN = 45;

//dp[i][j] == nr de moduri prin care se poate ajunge acolo din (i-1, j-1) si (i, j-1);
//n, m si dp sunt long long pentru ca altfel iese din int ca pot sa fie nr mari
//la alta problema (Cladire1) foarte asemanatoare, se dadea modulo, unde se putea cu int

int main () {
    long long n, m, dp[MAXN][MAXN];
    fin >> n >> m;
    for ( int i = 1; i <= n; ++ i ) {
        for ( int j = 1; j <= m; ++ j ) {
            if ( i == 1 ) dp[i][j] = 1 ;
            else if ( j == 1 ) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
        }
    }
    // for ( int i = 1; i <= n; ++ i ) {
    //     for ( int j = 1; j <= m; ++ j ) {
    //         fout << dp[i][j] << " ";
    //     } 
    //     fout << '\n';
    // }
    fout << dp[n][m];
}