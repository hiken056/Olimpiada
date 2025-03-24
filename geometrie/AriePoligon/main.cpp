//aria poligonului o putem afla prin triangularizarea acestuia
// iar apoi facem suma ariilor
// luam arbitrat punctul P(0, 0) cu care formam triunghiuri (P Ai Ai+1) (consideram si ca A1 = An+1)
// aria unui triunghi o sa fie 1/2(xi*yi+1 - yi*xi+1 )

//mai usor asa fara sa retin un vector de puncte
//ultimul triunghi cu PAnA1
//first ii An
// fixed << setprecision(6) = precizie de pana la 10^-5
// fabs = valoarea in modul

#include <bits/stdc++.h>

using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

int N;
#define double long double

struct Point{
    double x, y;
};

double ariaTriunghi( Point A, Point B) {
    return ( A.x * B.y - A.y * B.x);
}

double aria = 0;

int main() {
    fin >> N;
    Point first, ext;
    fin >> ext.x >> ext.y;
    first = ext;
    for ( int i = 1; i < N; ++ i ) {
        Point second;
        fin >> second.x >> second.y;
        aria += ariaTriunghi(ext, second);
        //fout << "fac aria intre: (" << ext.x << ", " << ext.y << ") si (" << second.x << ", " << second.y << ")" << endl;
        ext = second;
    }

    //MARE ATENTIE LA ORDINEA IN CARE FAC ARIA, PENTRU CA EU NU IAU ARIA IN MODUL, EU MA FOLOSESC CA ARIA POATE SA FIE SI NEGATIVA
    //SI AM NEVOIE DE SEMNUL CORECT AL ARIEI
    aria += ariaTriunghi(ext, first);
    aria /= 2.0;
    fout << fixed << setprecision(6) << fabs(aria);
}

