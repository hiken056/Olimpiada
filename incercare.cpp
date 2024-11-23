#include <bits/stdc++.h>

using namespace std;

int n, v[101], b[101], m;

bool prim(int n) {
  if (n < 2)
    return 0;
  if (n % 2 == 0)
    return 0;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

void stergere(int poz) {
  for (int i = poz + 1; i <= n; ++i) {
    v[i - 1] = v[i];
  }
  n--;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (prim(v[i])) {
      b[++m] = v[i];
      stergere(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << v[i] << " ";
  }
  cout << '\n';
  for (int i = 1; i <= m; ++i) {
    cout << b[i] << " ";
  }
  cout << '\n';
  return 0;
}
