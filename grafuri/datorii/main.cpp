#include <cmath>
#include <fstream>

using namespace std;

ifstream fin("datorii.in");
ofstream fout("datorii.out");

const int MAXN = 15005;

int aint[4 * MAXN];
int V[MAXN];
int N, M;
int x, y, q;

void build(int pos, int left, int right) {
  if (left == right) {
    aint[pos] = V[left];
  } else {
    int mij = (left + right) / 2;
    build(pos * 2, left, mij);
    build(pos * 2 + 1, mij + 1, right);
    aint[pos] = aint[pos * 2] + aint[pos * 2 + 1];
  }
}

void update(int pos, int left, int right) {
  if (left == right) {
    aint[x] -= y;
  } else {
    int mij = (left + right) / 2;
    if (x <= mij)
      update(2 * pos, left, mij);
    else
      update(2 * pos + 1, mij + 1, right);
    aint[pos] = aint[pos * 2] + aint[pos * 2 + 1];
  }
}

int query(int pos, int left, int right) {
  if (x >= left && right <= y)
    return aint[pos];
  else {
    int mij = (left + right) / 2;
    if (y <= mij) {
      return query(pos * 2, left, mij);
    }
    if (x >= mij + 1)
      return query(pos * 2 + 1, mij + 1, right);
    return query(pos * 2, left, mij) + query(pos * 2 + 1, mij + 1, right);
  }
}

void solve() {
  while (M--) {
    fin >> q;
    if (q == 0) {
      fin >> x >> y;
      update(1, x, y);
    } else if (q == 1) {
      fin >> x >> y;
      fout << query(1, x, y) << '\n';
    }
  }
}

int main() {
  fin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    fin >> V[i];
  }
  build(1, 1, N);
  solve();
  return 0;
}
