#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

#define ll long long

int N, M;
int x, y, op;
ll res;
ll aint[4 * MAXN + 5];
ll V[MAXN + 5];

void create_aint(int pos, int st, int dr) {
  if (st == dr) {
    aint[pos] = V[st];
    return;
  }
  int mij = (st + dr) / 2;
  create_aint(2 * pos, st, mij);
  create_aint(pos * 2 + 1, mij + 1, dr);
  aint[pos] = aint[2 * pos] +
              aint[2 * pos + 1]; // schimbi operatia in functie de ce cerinta ai
}

void update(int pos, int st, int dr) {
  if (x < st || x > dr) { // x nu este in interval
    return;
  }
  if (st == dr) {
    aint[pos] -= V[x];
    V[x] = y;
    aint[pos] += V[x];
    return;
  }
  int mij = (st + dr) / 2;
  update(2 * pos, st, mij);
  update(2 * pos + 1, mij + 1, dr);
  aint[pos] = aint[2 * pos] + aint[2 * pos + 1];
}

void query(int pos, int st, int dr) {
  // suntem la [st, dr] - avem nevoie de rezultatul pe [x, y]
  // caz 1 - intervalul [st, dr] complet in afara lui [x, y] => returnam un
  // element neutru
  if (y < st || x > dr) {
    return;
  }

  // caz 2 - intervalul [st, dr] complet inclus in [x, y] => returnam rezultatul
  if (x <= st && dr <= y) {
    res += aint[pos];
    return;
  }
  // caz 3 - intervalul [st, dr] partial inclus in [x, y] => returnam rezultatul
  // din apelurile recursive
  int mij = (st + dr) / 2;
  query(pos * 2, st, mij);
  query(pos * 2 + 1, mij + 1, dr);
}

int main() {
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> V[i];
  }
  create_aint(1, 1, N);
  for (int i = 1; i <= M; ++i) {
    cin >> op >> x >> y;
    if (op == 1)
      update(1, 1, N);
    if (op == 2) {
      res = 0;
      query(1, 1, N);
      cout << res << '\n';
    }
  }
  return 0;
}
