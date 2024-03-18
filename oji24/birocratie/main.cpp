#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
const int ND = 4;
const int INF = 1 << 30;

int a[N+2][N+2], dp[N+2][N+2][ND+1];

int main()
{
    ifstream in("birocratie.in");
    ofstream out("birocratie.out");
    int n;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++)
    {
        for (int k = 0; k <= ND; k++)
        {
            dp[i][0][k] = dp[i][n+1][k] = -INF;
        }
    }
    for (int j = 0; j <= n + 1; j++)
    {
        for (int k = 0; k <= ND; k++)
        {
            dp[0][j][k] = dp[n+1][j][k] = -INF;
        }
    }
    dp[1][1][ND] = a[1][1];
    for (int s = 3; s <= 2 * n; s++)
    {
        int i0, j0;
        if (s <= n + 1)
        {
            i0 = 1;
            j0 = s - 1;
        }
        else
        {
            j0 = n;
            i0 = s - n;
        }

        for (int i = i0, j = j0; i <= n && j >= 1; i++, j--)
        {
            dp[i][j][0] = dp[i-1][j][ND] + a[i][j];
            dp[i][j][1] = dp[i][j-1][ND] + a[i][j];
            dp[i][j][2] = dp[i-1][j+1][ND] + a[i][j];
            dp[i][j][ND] = max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2]));
        }
        if (s <= n + 1)
        {
            i0 = s - 1;
            j0 = 1;
        }
        else
        {
            i0 = n;
            j0 = s - n;
        }
        for (int i = i0, j = j0; i >= 1 && j <= n; i--, j++)
        {
            dp[i][j][3] = max(dp[i+1][j-1][0], max(dp[i+1][j-1][1], dp[i+1][j-1][3])) + a[i][j];
            dp[i][j][ND] = max(dp[i][j][ND], dp[i][j][3]);
        }
    }
    out << dp[n][n][ND] << "\n";
    in.close();
    out.close();
    return 0;
}