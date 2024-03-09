#include <bits/stdc++.h>
#define MOD 30011

using namespace std;

ifstream fin ("iepuri1.in");
ofstream fout ("iepuri1.out");

vector < int > Tree[101];
int dp[101][101], sum[101][102], K, sol;
bool T[101];

void DFS (int x) {
  int N = Tree[x].size();
    
  for (int i = 0; i < N; i ++)
    DFS(Tree[x][i]);
    
  for (int i = 1; i <= K; i ++) {
    dp[x][i] = 1;
    for (int j = 0; j < N; j ++) {
      dp[x][i] = (dp[x][i] * sum[Tree[x][j]][i + 1]) % MOD;
    }
  }
  
  for (int i = K; i > 0; --i) {
    sum[x][i] = (sum[x][i + 1] + dp[x][i]) % MOD;
  }
}

int main () {
	int N, x, y;
	fin >> N >> K;
	for (int i = 1; i < N; i ++) {
        fin >> x >> y;
        Tree[x].emplace_back (y);
        T[y] = 1;
	}
	int R = 1;
	while (T[R++]);
	R --;
	DFS (R);
	for (int i = 1; i <= K; i ++)
    sol = (sol + dp[R][i]) % MOD;
    fout << sol << '\n';
	return 0;
}
