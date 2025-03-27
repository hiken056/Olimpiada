#include <bits/stdc++.h>

using namespace std;

ifstream fin("ceas.in");
ofstream fout("ceas.out");

int h, r, m;

double getAngle(int h, int m) {
    double H = 360 / 12;
    double M = 0.5; 
    //+ 90 pentru ca 0 imi e la 12
    double angle = 360 - (H * h + M * m - 90);
    if ( angle > 360 ) {
        angle -= 360;
    }
    return angle;
}

int main() {
    fin >> r >> h >> m;
    double angle = getAngle(h, m);
    //fout << angle << "\n";
    double x, y;
        x = r * cos(angle * M_PI / 180);
        y = r * sin(angle * M_PI / 180);
    fout << fixed << setprecision(3) << x << " " << y;
    return 0;
}