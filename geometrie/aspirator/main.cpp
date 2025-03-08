
#include <bits/stdc++.h>

using namespace std;

ifstream fin("aspirator.in");
ofstream fout("aspirator.out");

int T, N;
char instructiune;
char nr[301];

const double pi = acos(-1);
const double c_unghi = pi / 180.0;

double x, y;
double xx, yy;
double unghi;

void solve() {
  fin >> N;
  int caz;
  x = 0, y = 0, xx = 0, yy = 0, unghi = 0;
  for (int i = 1; i <= N; ++i) {
    fin >> instructiune;
    fin >> nr;
    if (instructiune == 'f') {
      if (nr[0] == '?') {
        caz = 1;
        continue;
      }
      double arg = (double)stoi(nr);
      x += cos(unghi * c_unghi) * arg;
      y += sin(unghi * c_unghi) * arg;
    } else if (instructiune == 'b') {
      if (nr[0] == '?') {
        caz = 1;
        continue;
      }
      double arg = (double)stoi(nr);
      x -= cos(unghi * c_unghi) * arg;
      y -= sin(unghi * c_unghi) * arg;
    } else if (instructiune == 'l') {
      if (nr[0] == '?') {
        caz = 2;
        xx = x;
        yy = y;
        continue;
      }
      double arg = (double)stoi(nr);
      unghi += arg;
    } else if (instructiune == 'r') {
      if (nr[0] == '?') {
        caz = 3;
        xx = x;
        yy = y;
        continue;
      }
      double arg = (double)stoi(nr);
      unghi -= arg;
    }
  }
  if (caz == 1) {
    fout << sqrt(x * x + y * y) << '\n';
  }
  if (caz != 1) {
    double alpha1 = atan2(y - yy, x - xx);
    double alpha2 = atan2(-yy, -xx);
    double dif = (alpha2 - alpha1) / c_unghi;
    if (dif < 0) {
      dif += 360;
    }
    if (caz == 3) {
      dif = 360 - dif;
    }
    fout << dif << '\n';
  }
}

int main() {
  fin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
