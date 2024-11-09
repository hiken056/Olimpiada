#include <bits/stdc++.h>

using namespace std;

ifstream fin ("disjoint.in");
ofstream fout ("disjoint.out");

int N, M;
int query, x, y;
vector <int> tati, inaltime;

int rad(int nod) {
    if ( nod == tati[nod] ) {
        return nod;
    }
    int rnod = rad(tati[nod]);
    tati[nod] = rnod;
    return rnod;
}

void reuniune(int x, int y)  {
    int rx = rad(x);
    int ry = rad(y);
    if ( inaltime[rx] > inaltime[ry] ) {
        tati[ry] = rx;
    }
    else if ( inaltime[rx] < inaltime[ry]) {
        tati[rx] = ry;
    }
    else {
        tati[ry] = rx;
        inaltime[rx] ++;
    }
}

bool interogare(int x, int y) {
    return rad(x) == rad(y);
}


int main () {
    fin >> N >> M;
    tati.resize(N + 1);
    inaltime.resize(N+1);
    for ( int i = 1; i <= N; ++ i) {
        tati[i] = i;
    }
    while ( M -- ) {
        fin >> query >> x >> y;
        if ( query == 1 ) {
            reuniune(x, y);
        }
        else {
            (interogare(x, y) ? fout << "DA\n" : fout << "NU\n");   
        }
    }
    return 0;
}
