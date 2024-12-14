#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int MAXN = 2e5;
int N, M, k;
int p2[MAXN + 5];
int ind[MAXN + 5];
pair<int, int> rmq[MAXN + 5][17];
pair<int, int> euler[MAXN + 5];
vector<int> V[MAXN + 5];

void dfs(int nod, int nivel) {
  ind[nod] = ++k;
  euler[k] = {nivel, nod};
  for (auto fiu : V[nod]) {
    dfs(fiu, nivel + 1);
    euler[++k] = {nivel, nod};
  }
}

void read() {
  fin >> N >> M;
  for (int i = 2; i <= N; ++i) {
    int x;
    fin >> x;
    V[x].push_back(i);
  }
}

void create_tables() {
  p2[1] = 0;
  for (int i = 2; i <= N; ++i) {
    p2[i] = p2[i - 1];
    if (1 << (p2[i - 1] + 1) <= i)
      p2[i]++;
  }

  for (int j = 0; (1 << j) <= k; ++j) {
    for (int i = 1; i <= k - (1 << j) + 1; ++i) {
      if (j == 0)
        rmq[i][j] = euler[i];
      else {
        rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}

void query(int x, int y) {
  x = min(ind[x], ind[y]);
  y = max(ind[x], ind[y]);
  int l = y - x + 1;
  fout << min(rmq[x][p2[l]], rmq[y - (1 << p2[l]) + 1][p2[l]]).second << '\n';
}

int main() {
  read();
  dfs(1, 0);
  create_tables();

  while (M--) {
    int x, y;
    fin >> x >> y;
    query(x, y);
  }
}
