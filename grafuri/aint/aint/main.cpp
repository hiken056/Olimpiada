#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("aint.in");
ofstream fout("aint.out");

#define ll long long

const int MAXN = 1e5;
int x, y, op;
int N, M;
int V[MAXN + 5];
ll aint[4 * MAXN + 5];
ll res;

void create_aint(int pos, int st, int dr) {
  if (st == dr) {
    aint[pos] = V[st];
    return;
  }
  int mij = (st + dr) / 2;
  create_aint(pos * 2, st, mij);
  create_aint(pos * 2 + 1, mij + 1, dr);
  aint[pos] = min(aint[pos * 2], aint[pos * 2 + 1]);
}

void update(int pos, int st, int dr) {
  if (x < st || x > dr) { // x nu se aflta in interval
    return;
  }
  if (st == dr) {
    aint[pos] -= V[x];
    V[x] = y;
    aint[pos] += V[x];
    return;
  }
  int mij = (st + dr) / 2;
  update(pos * 2, st, mij);
  update(pos * 2 + 1, mij + 1, dr);
  aint[pos] = min(aint[pos * 2], aint[pos * 2 + 1]);
}

void query(int pos, int st, int dr) {
  // 1. tot intervalul ii inclus
  if (st >= x && y >= dr) {
    res = min(res, aint[pos]);
    return;
  }
  // 2. intervalul este complet inafara
  if (dr < x || st > y) {
    return;
  }
  // rezultatul ii partial in interval si returnam recursiv pana ajungem la un
  // caz de baza ca mai sus
  int mij = (st + dr) / 2;
  query(pos * 2, st, mij);
  query(pos * 2 + 1, mij + 1, dr);
}

int main() {
  fin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    fin >> V[i];
  }
  create_aint(1, 1, N);
  for (int i = 1; i <= M; ++i) {
    fin >> op >> x >> y;
    if (op == 1)
      update(1, 1, N);
    else {
      res = INT_MAX;
      query(1, 1, N);
      fout << res << '\n';
    }
  }
  return 0;
}
