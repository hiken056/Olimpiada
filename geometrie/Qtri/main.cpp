#include <bits/stdc++.h>

using namespace std;

ifstream fin("qtri.in");
ofstream fout("qtri.out");

int Q;

struct Point {
    int x, y;
};

double ariaTriunghi(Point a, Point b, Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

void solve() {
    Point puncte[5];
    for (int i = 1; i <= 4; ++i) {
        fin >> puncte[i].x >> puncte[i].y;
    }

    double ariaABC = ariaTriunghi(puncte[1], puncte[2], puncte[3]);
    
    double ariaABD = ariaTriunghi(puncte[1], puncte[2], puncte[4]);
    double ariaBCD = ariaTriunghi(puncte[2], puncte[3], puncte[4]);
    double ariaCAD = ariaTriunghi(puncte[1], puncte[3], puncte[4]);

    if (fabs(ariaABC - (ariaABD + ariaBCD + ariaCAD)) < 1e-9) {
        fout << "DA\n";
    } else {
        fout << "NU\n";
    }
}

int main() {
    fin >> Q;
    while (Q--) {
        solve();
    }
    return 0;
}
