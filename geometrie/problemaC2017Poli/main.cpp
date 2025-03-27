#include <bits/stdc++.h>

using namespace std;

ifstream fin("C.in");
ofstream fout("C.out");

int N, cntMax, cnt;
struct Point {
    int x, y;
}puncte[105];

bool apartineDreptei(int x1, int y1, int x2, int y2, int xc, int yc) {
    double fx = xc * ( y2 - y1) + yc * ( x1 - x2) + y1 * x2 - x1 * y2;
    if ( fx == 0 ) {
        return true;
    }
    return false;
}

int main() {
    fin >> N;
    for (int i = 1; i <= N; ++ i ) {
        fin >> puncte[i].x >> puncte[i].y;
    }
    for ( int i = 1; i < N; ++ i ) {
        for ( int j = i + 1; j <= N; ++ j ) {
            cnt = 0;
            for ( int k = 1; k <= N; ++ k ) {
                if ( apartineDreptei(puncte[i].x, puncte[i].y, puncte[j].x, puncte[j].y, puncte[k].x, puncte[k].y)  == 1) {
           //         fout << puncte[k].x << ", " << puncte[k].y << " apartine dreptei:  " << puncte[i].x << ", " << puncte[i].y << " si " << puncte[j].x << ", " << puncte[j].y << endl;
                    cnt ++;
                }
            }
         //   fout << "cnt = " << cnt << endl;
            cntMax = max(cntMax, cnt);
        }
    }
    if ( N == 1 ) cntMax = 1;
    if ( N == 2 ) cntMax = 2;   
    fout << cntMax;
}