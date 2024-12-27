#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int MAXN = 1e5;
int N, M, k, x, y, n1, n2;
int p2[2 * MAXN + 5];
int ind[MAXN + 5];
pair<int, int> rmq[2 * MAXN + 5][18];
pair<int, int> euler[2 * MAXN + 5];
vector<int> V[MAXN + 5];

void dfs(int nod, int niv) {
  ind[nod] = ++k;
  euler[k] = {niv, nod};
  for (auto nxt : V[nod]) {
    dfs(nxt, niv + 1);
    euler[++k] = {niv, nod};
  }
}

void read() {
  fin >> N >> M;
  int x;
  for (int i = 2; i <= N; i++) {
    fin >> x;
    V[x].push_back(i);
  }
  p2[1] = 0;
  for (int i = 2; i <= 2 * N; i++) {
    p2[i] = p2[i - 1];
    if ((1 << (p2[i] + 1)) <= i) {
      p2[i]++;
    }
  }
}

void create() {
  for (int j = 0; (1 << j) <= k; j++) {
    for (int i = 1; i <= k - (1 << j) + 1; i++) {
      if (j == 0) {
        rmq[i][j] = euler[i];
      } else {
        rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
}

void query() {
  x = min(ind[n1], ind[n2]);
  y = max(ind[n1], ind[n2]);
  int l = (y - x + 1);
  fout << min(rmq[x][p2[l]], rmq[y - (1 << p2[l]) + 1][p2[l]]).second << '\n';
}

int main() {
  read();
  dfs(1, 0);
  create();
  for (int t = 1; t <= M; t++) {
    fin >> n1 >> n2;
    query();
  }
  return 0;
}
