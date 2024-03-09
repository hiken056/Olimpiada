#include <bits/stdc++.h>

using namespace std;

ifstream fin("xidartros.in");
ofstream fout("xidartros.out");

void testCase() {
  int n, b, k;
  fin >> n >> b >> k;
    
  vector<int> p(n + 1);

  for (int i = 1; i <= n; ++i) {
    p[i] = i;
  }
    
  int64_t pw = 1;
    
  bool flag = true;

  vector<int64_t> sol(n + 1);
    
  for (int itr = 0; itr < k; ++itr) {
    int dig = 0, last = 0;

    for (int i = 1; i <= n; ++i) {
      int x;
      fin >> x;

      if (p[x] < last) {
        dig += 1;
          
       	if (dig == b) {
      	  flag = false;
    	}
      }

      sol[x] += pw * dig;

      last = p[x];
      p[x] = i;
    }

    pw *= b;
  }

  if (flag) {
    for (int i = 1; i <= n; ++i) {
      fout << sol[i] << ' ';
    }
  } else {
    fout << "-1";
  }

  fout << '\n';
}

int main() {
  int tests;
  fin >> tests;

  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }

  fin.close();
  fout.close();

  return 0;
}
