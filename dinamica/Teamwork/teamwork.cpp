#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

const int MAXN = 18;
int dp[MAXN][1 << MAXN];
int e[MAXN][MAXN];

// 1 << k  = 2^k
// mask & ( 1 << k ) = daca bitul k de pe mask este 1/0

int n;

int main() {
  fin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      fin >> e[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    dp[0][1 << k] = e[0][k];
  }

  for (int i = 1; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      int dpMax = 0;
      for (int mask = 1; mask < (1 << n); ++mask) {
        if ((mask & (1 << k)) == 0)
          continue;
        dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << k)] + e[i][k]);
      }
    }
  }

  fout << dp[n - 1][(1 << n) - 1];
  return 0;
}
