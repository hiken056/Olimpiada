#include <bits/stdc++.h>
#include <fstream>

using namespace std;

ifstream fin("divk.in");
ofstream fout("divk.out");

const int MAXN = 5e5;
// calculam sumele partiale % k

int N, SP[MAXN + 5];
int A, B, K, k;

int main() {
  fin >> N >> K >> A >> B;
  for (int i = 1; i <= N; ++i) {
    int x;
    fin >> x;
    SP[i] = SP[i - 1] + x;
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      if (j - i + 1 >= A && j - i + 1 <= B) {
        if ((SP[j] - SP[i - 1]) % K == 0) {
          k++;
        }
      }
    }
  }
  fout << k;
  return 0;
}
