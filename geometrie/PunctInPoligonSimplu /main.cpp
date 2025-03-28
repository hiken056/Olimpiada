#include <bits/stdc++.h>
using namespace std;

ifstream fin("punctinpoligonsimplu.in");
ofstream fout("punctinpoligonsimplu.out");

const int MAXN = 105;

struct Point {
    int x, y;
} poligon[MAXN], puncte[MAXN];

int N, M;

double angle(Point A, Point B, Point P) {
    double PAx = A.x - P.x;
    double PAy = A.y - P.y;
    double PBx = B.x - P.x;
    double PBy = B.y - P.y;

    double produsVectorial = PAx * PBy - PAy * PBx;
    double produsScalar = PAx * PBx + PAy * PBy;
    
    return atan2(produsVectorial, produsScalar);
}

bool onSegment(Point A, Point B, Point P) {
    if ((B.x - A.x) * (P.y - A.y) != (B.y - A.y) * (P.x - A.x))
        return false;
    return (P.x >= min(A.x, B.x)) && (P.x <= max(A.x, B.x)) &&
           (P.y >= min(A.y, B.y)) && (P.y <= max(A.y, B.y));
}

bool apartinePoligonului(Point P) {
    double totalAngle = 0;
    for (int i = 1; i <= N; ++i) {
        Point A = poligon[i];
        //verific sa imi fie intre 1 si N
        Point B = poligon[(i == N) ? 1 : i + 1]; 

        if (onSegment(A, B, P))
            return true;

        double currentAngle = angle(A, B, P);
        //  unghi în [-pi, pi]
        if (currentAngle > M_PI) currentAngle -= 2 * M_PI;
        if (currentAngle < -M_PI) currentAngle += 2 * M_PI;
        totalAngle += currentAngle;
    }
    // Verificare winding number (aproximativ 2pi sau -2pi)
    return fabs(fabs(totalAngle) - 2 * M_PI) < 1e-9;
}

int main() {
    fin >> N >> M;
    for (int i = 1; i <= N; ++i)
        fin >> poligon[i].x >> poligon[i].y;
    for (int i = 1; i <= M; ++i)
        fin >> puncte[i].x >> puncte[i].y;
    for (int i = 1; i <= M; ++i)
        fout << (apartinePoligonului(puncte[i]) ? "DA" : "NU") << "\n";
    return 0;
}