
#include <bits/stdc++.h>

using namespace std;

ifstream fin("aspirator.in");
ofstream fout("aspirator.out");

int T, N;
char instructiune;
char nr[301];


const double pi = acos(-1);
//ratia ca sa transform gradele in radiani
const double c_unghi = pi / 180.0;

double x, y;
double xx, yy;
double unghi;

void solve() {
  fin >> N;
  int caz;
  //resetez pt fiecare caz
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
      //calculez coordonatele aspiratorului cu coordonate polare
      //unghi * raza
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
        //cand am cu unghi, retin coordonatele unde am ?
        caz = 2;
        xx = x;
        yy = y;
        continue;
      }
      double arg = (double)stoi(nr);
      //la stanga ma rotesc cu arg in sesn trigonometric
      unghi += arg;
    } else if (instructiune == 'r') {
      if (nr[0] == '?') {
        caz = 3;
        xx = x;
        yy = y;
        continue;
      }
      double arg = (double)stoi(nr);
      //la dreapta ma rotesc cu arg in sens orar
      unghi -= arg;
    }
  }
  if (caz == 1) {
    //in cazul in care merg fata sau spate, continui si calculez la final distanta
    fout << sqrt(x * x + y * y) << '\n';
  }
  if (caz != 1) {
    //daca am de calculat unghi, atunci trebuie il calculez din alte unghiuri
    double alpha1 = atan2(y - yy, x - xx);
    double alpha2 = atan2(-yy, -xx);
    double dif = (alpha2 - alpha1) / c_unghi;
    //unghiul trebuie sa ramana pozitiv
    if (dif < 0) {
      dif += 360;
    }
    //in cazul in care ma rotesc la dreapta (sens orar), eu tot rebuie sa zic unghiul in sesn trigonometric
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
