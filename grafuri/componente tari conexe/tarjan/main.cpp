#include <fstream>
#include <stack>
#include <vector>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int MAXN = 1e5;

int N, M;
vector<int> G[MAXN + 5];
bool viz[MAXN + 5];
bool inStack[MAXN + 5];
stack<int> S;
int cid = 1;
int id[MAXN + 5];
int low[MAXN + 5];

vector<vector<int>> CTC;

void tarjan(int nod) {
  viz[nod] = 1;
  id[nod] = cid;
  cid++;
  low[nod] = id[nod];
  S.push(nod);
  inStack[nod] = 1;
  for (const auto &vecin : G[nod]) {
    if (!viz[vecin]) {
      tarjan(vecin);
      low[nod] = min(low[nod], low[vecin]);
    } else if (inStack[vecin]) {
      low[nod] = min(low[nod], id[vecin]);
    }
  }
  if (id[nod] == low[nod]) {
    vector<int> comp;
    while (S.top() != nod) {
      int cur = S.top();
      S.pop();
      inStack[cur] = 0;
      comp.push_back(cur);
    }
    comp.push_back(S.top());
    S.pop();
    inStack[nod] = 0;
    CTC.push_back(comp);
  }
}

int main() {
  fin >> N >> M;
  while (M--) {
    int x, y;
    fin >> x >> y;
    G[x].push_back(y);
  }
  for (int i = 1; i <= N; ++i) {
    if (!viz[i]) {
      tarjan(i);
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
