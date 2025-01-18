#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int MAXN = 1e5;
int N, M;
vector<int> G[MAXN + 5], GT[MAXN + 5];
vector<vector<int>> CTC;
int viz[MAXN + 5];
stack<int> S;
vector<int> comp;

void dfs(int nod) {
  viz[nod] = 1;
  for (const int vecin : G[nod]) {
    if (!viz[vecin]) {
      dfs(vecin);
    }
  }
  S.push(nod);
}

void dfs2(int nod) {
  viz[nod] = 1;
  for (const int vecin : GT[nod]) {
    if (!viz[vecin]) {
      dfs2(vecin);
    }
  }
  comp.push_back(nod);
}

int main() {
  fin >> N >> M;
  while (M--) {
    int x, y;
    fin >> x >> y;
    G[x].push_back(y);
    GT[y].push_back(x);
  }
  for (int i = 1; i <= N; i++) {
    if (!viz[i])
      dfs(i);
  }

  for (int i = 0; i <= N; ++i) {
    viz[i] = 0;
  }
  while (!S.empty()) {
    int cur = S.top();
    S.pop();
    if (!viz[cur]) {
      comp = vector<int>();
      dfs2(cur);
      CTC.push_back(comp);
    }
  }
  fout << CTC.size() << '\n';
  for (const auto &comp : CTC) {
    for (const auto &nod : comp) {
      fout << nod << " ";
    }
    fout << '\n';
  }
  return 0;
}
