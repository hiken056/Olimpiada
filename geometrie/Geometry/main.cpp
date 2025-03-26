#include <bits/stdc++.h>

using namespace std;

ifstream fin("geometry.in");
ofstream fout("geometry.out");

struct Segment{
    int x1, y1, x2, y2;
}segmente[505];

int N, cont;


int determinat(int x1, int y1, int x2, int y2, int x3, int y3 ) {
    return x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1;
}

bool apartine(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int d1 = determinat(x1, y1, x2, y2, x3, y3);
    int d2 = determinat(x1, y1, x2, y2, x4, y4);
    int d3 = determinat(x3, y3, x4, y4, x1, y1);
    int d4 = determinat(x3, y3, x4, y4, x2, y2);

    if ( d1 * d2 < 0 && d3 * d4 < 0 ) {
        return true;
    }

    if ( d1 == 0 ) {
        
    }
}

int main() {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> segmente[i].x1 >> segmente[i].y1 >> segmente[i].x2 >> segmente[i].y2;
    }


    return 0;
}