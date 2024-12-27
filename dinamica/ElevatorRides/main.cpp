#include <bits/stdc++.h>

using namespace std;

int N, W;
int v[21];

// dp[msk].first = nr minim de calatorii cu msk
// dp[msk].second = greutatea totala a ultimei curse pentru msk

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  vector<pair<int, int>> dp(1 << N);

  dp[0].first = 1; // pentru multimea cu 0 elem avem 1 drum
  for (int msk = 1; msk < (1 << N); ++msk) {
    dp[msk].first =
        N + 1; // un nr destul de mare incat sa arate ca nu am gasit solutia
  }

  for (int msk = 0; msk < (1 << N); ++msk) {
    for (int j = 0; j < N; ++j) {
      if (msk & (1 << j)) // daca am luat deja persoana aia
        continue;
      if (dp[msk].second + v[j] <= W) {
        dp[msk + (1 << j)] =
            min(dp[msk + (1 << j)], {dp[msk].first, dp[msk].second + v[j]});
        // daca greutatea persoanei intra in tura asta
      } else {
        dp[msk + (1 << j)] = min(dp[msk + (1 << j)], {dp[msk].first + 1, v[j]});
        // daca greutatea persoanei nu intra in tura si facem alta, unde avem
        // doar v[j]
      }
    }
  }

  cout << dp[(1 << N) - 1].first << '\n';

  return 0;
}
