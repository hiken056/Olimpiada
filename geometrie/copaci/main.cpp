#include <bits/stdc++.h>

using namespace std;

fstream fin("copaci.in");
ofstream fout("copaci.out");

//pentru a afla punctele interioare ne folosim de teorema lui pick
// aria = a + b/2 - 1 unde a = nr de puncte interioare, iar b este nr de puncte de pe poligon
//calculam aria cu triunghiuri si dupa aflam a ul 

//pentru a afla b ul avem nevoie sa stim toate punctele care apartin poligonului
//pentru a afla nr de puncte intregi de pe un segment, putem face cmmmdc( abs(x1-x2), abs(y1 - y2))

int N, b;
long long aria;
int nrPuncte;

struct Point {
    long long x, y;
};

double ariaTriunghi ( Point A, Point B ) {
    return (A.x * B.y - A.y * B.x);
}

long long cmmdc ( long long a, long long b ) {
    while (b){
        long long r=a%b;
        a=b;
        b=r;
    }
    return a;
} 


int main() {
    fin >> N;
    Point first, ext;
    fin >> ext.x >> ext.y;
    first = ext;
    for ( int i = 1; i < N; ++ i ) {
        Point second;
        fin >> second.x >> second.y;
        b += cmmdc(abs(ext.x - second.x), abs(ext.y - second.y));
        aria += ariaTriunghi(ext, second);
        ext = second;
    }
    //calculam pentru ultima dreapta
    aria += ariaTriunghi(ext, first);
    b += cmmdc( fabs(ext.x - first.x), fabs(ext.y - first.y));
    aria /= 2;
    aria = fabs(aria);
    fout << aria - b/2 + 1;
}