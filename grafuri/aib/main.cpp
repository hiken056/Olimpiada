#include <bits/stdc++.h>

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

const int MAXN = 1e5 + 5;
int N, M;
int x;
int a, b;
int aib[MAXN];

void update(int poz, int elem) {
  for (int j = poz; j <= N; j += (j & -j)) {
    aib[j] += elem;
    // j+=(j&-j) -> trecem prin numerele care il contin in suma pe elementul de
    // pe pozitia poz
  }
}

void create() {
  for (int i = 1; i <= N; ++i) {
    fin >> x;
    update(i, x);
  }
}

int operatie(int poz) {
  int s = 0;
  for (int j = poz; j >= 1; j -= (j & -j)) {
    s += aib[j];
    // j -= (j&-j) -> eliminam cel mai din dreapta bit de 1 la
    // fiecare pas, j&(-j) reprezinta cel mai din dreapta bit de 1,
    // putem sa il eliminam deoarece j contine exact suma a j&(-j)
    // elemente, deci cu exact atatea elemente mergem in spate
  }
  return s;
}

int cautareBinara(int x) {
  int st = 1;
  int dr = N;
  while (st < dr) {
    int mij = (st + dr) / 2;
    int s = operatie(mij);
    if (s >= x) {
      dr = mij;
    } else
      st = mij + 1;
  }
  if (operatie(st) != x)
    return -1;
  return st;
}

int main() {
  fin >> N >> M;
  create();
  int q;
  while (M--) {
    fin >> q;
    if (q == 0) {
      fin >> a >> b;
      update(a, b);
    }
    if (q == 1) {
      fin >> a >> b;
      fout << operatie(b) - operatie(a - 1) << '\n';
    }
    if (q == 2) {
      fin >> a;
      fout << cautareBinara(a) << '\n';
    }
  }
  return 0;
}
