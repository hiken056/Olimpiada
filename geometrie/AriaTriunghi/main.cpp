#include <bits/stdc++.h>

using namespace std;

ifstream fin("ariatriunghi.in");
ofstream fout("ariatriunghi.out");

struct Point{
    double x, y;
}a, b, c;

double delta ( Point a, Point b, Point c) {
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

int main() {
    fin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    fout  << fixed << setprecision(1) << fabs(delta(a, b, c)) / 2.0 << '\n';
}