#include <bits/stdc++.h>

using namespace std;

ifstream fin ("apm.in");
ofstream fout ("apm.out");

const int MAXN = 2e5;

int N, M;
vector < pair < int , pair < int, int > > > G;
//{cost, {x, y}}
vector < int > tati, inaltime;
vector < pair < int, int> > res;
int x, y, c, ctot;

int radacina ( int x ) {
    if ( tati[x] == x ) return x;
    else {
        int rx = radacina(tati[x]);
        tati[x] = rx;
        return rx;
    }
}

bool aceeasiMultime( int x, int y ){
    return radacina(x) == radacina(y);
}

void reuniune ( int x, int y ) {
    int rx = radacina(x);
    int ry = radacina(y);
    if ( inaltime[rx] > inaltime[ry] ) {
        tati[ry] = rx;
    }
    else if ( inaltime[rx] < inaltime[ry] ) {
        tati[ry] = rx;
    }
    else {
        tati[ry] = rx;
        inaltime[rx] ++;
    }
}

int main () {
    int N, M;
    fin >> N >> M;
    tati.resize(N + 1);
    inaltime.resize(N + 1);
    for ( int i = 1; i <= N; ++ i ) {
        tati[i] = i;
    }
    while ( M -- ) {
        fin >> x >> y >> c;
        G.push_back({c, {x,y}});
    }
    sort(G.begin(), G.end() );
    for ( auto vecin : G ) {
        x = vecin.second.first;
        y = vecin.second.second;
        if ( !aceeasiMultime(x, y) ) {
            reuniune(x, y);
            ctot += vecin.first;
            res.push_back({x, y});
        }
    }
    fout << ctot << '\n';
    fout << N - 1 << '\n';
    for ( auto n : res ) {
        fout << n.first << " " << n.second << '\n';
    }
    return 0;
}