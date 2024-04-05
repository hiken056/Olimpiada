#include <fstream>

using namespace std;

ifstream fin ("sumtri.in");
ofstream fout ("sumtri.out");

int dp[101][101];
int n, x;

int main()
{
    fin >> n;
    for ( int i = 1; i <= n; i ++ ) {
        for ( int j = 1; j <= i; j++ ) {
            fin >> x;
            dp[i][j] = max(dp[i-1][j] + x, dp[i-1][j-1] + x);
        }
    }
    x = 0;
    for ( int i = 1; i <= n; i ++ ) {
        if ( dp[n][i] > x ) {
            x = dp[n][i];
        }
    }
    fout << x;
    return 0;
}