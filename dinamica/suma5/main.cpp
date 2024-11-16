#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define min(a, b, ...) min(a, min(b, ...))

ifstream fin ("suma5.in");
ofstream fout ("suma5.out");

const int MAXN = 63365 + 5;

int N;
int V[MAXN];
int dp[MAXN]; //drumu minim pana la camera i

int main () {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> V[i];
    }
    dp[1] = V[1];
    int niv = 2;
    for ( int i = 2; i <= N; ++ i ) {
        dp[i] = min (dp[i-1] + V[i] + niv * niv + 1, dp[i-1] + V[i] + niv*niv + niv);
    }
    return 0;
}
