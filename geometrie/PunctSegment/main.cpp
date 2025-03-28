#include <bits/stdc++.h>

using namespace std;

ifstream fin("punctsegment.in");
ofstream fout("punctsegment.out");  

struct Point{
    int x, y;
}a, b, x;

bool delta (Point a, Point b, Point x) {
    return (a.x - x.x) * (b.y - x.y) - (a.y - x.y) * (b.x - x.x) == 0;
}

int main( ) {
    fin >> x.x >> x.y >> a.x >> a.y >> b.x >> b.y;
    if ( delta(a, b, x) ) {
        if ( x.x <= max(a.x, b.x) && x.x >= min(a.x, b.x) && x.y <= max(a.y, b.y) && x.y >= min(a.y, b.y) ) {
            fout << "DA";
        } else {
            fout << "NU";
        }
    }
    return 0;
}