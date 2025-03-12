#include <bits/stdc++.h>

using namespace std;

ifstream fin ("triang.in");
ofstream fout ("triang.out");

int N, rez;
struct punct {
    double x;
    double y;
} puncte[1505];

double distance ( punct a, punct b) {
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

int main() {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        double x, y;
        fin >> x >> y;
        puncte[i].x = x;
        puncte[i].y = y;
    }
    for ( int i = 1; i < N -1; ++ i ) {
        for ( int j = 2; j < N; ++ j ) {
            double d1 = distance(puncte[i], puncte[j]);
            for ( int k = 3; k <= N; ++ k ) {
                double d2 = distance(puncte[i], puncte[k]);
                double d3 = distance(puncte[j], puncte[k]);
                if ( d1 == d2 && d1 == d3 && d2 == d3 ) rez ++;
            }
        }
    }
    fout << rez;
}