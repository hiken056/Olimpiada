#include <bits/stdc++.h>

using namespace std;

ifstream fin("cladire.in");
ofstream fout("cladire.out");

const int mod = 9901;
const int MAXN = 1005;

//dp[i][j] = nr de moduri prin care poti ajunge in camera (i,j) 
//in camera (i,j) poti ajunge prin (i-1, j) si prin (i,j-1)
//=>> dp[i][j] = dp[i-1][j] + dp[i][j-1] cand i si j != 1 ( ca sa existe camera)

int main()
{
    int n, m, k, dp[MAXN][MAXN], a[MAXN][MAXN];
    int x, y;
    fin >> n >> m;
    fin >> k;
    for (int i = 1; i <= k; ++i)
    {
        fin >> x >> y;
        a[x][y] = 1;
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ( i == 1 && j == 1 ) dp[i][j] = 1;
            if ( i == 1 && j != 1 && a[i][j] == 0 ) dp[i][j] = dp[i][j-1]; 
            if ( i != 1 && j == 1 && a[i][j] == 0 ) dp[i][j] = dp[i-1][j];
            if ( a[i][j] == 0 && i != 1 && j != 1 ) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         fout << a[i][j] << " ";
    //     }
    //     fout << '\n';
    // }
    // fout << '\n';
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= m; ++j)
    //     {
    //         fout << dp[i][j] << " ";
    //     }
    //     fout << '\n';
    // }

    fout << dp[n][m] % mod;
    return 0;
}