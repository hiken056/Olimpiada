#include <bits/stdc++.h>

using namespace std;

ifstream fin ("urgenta.in");
ofstream fout ("urgenta.out");

int N, M, K;
int x, y, c, ctot, cc;
vector < pair < int, pair < int, int > > > G;
// {cost, {x, y}}
vector < pair < int , int > > res;
vector <int> tati, inaltime;

int radacina ( int x ) {
    if ( tati[x] == x ) return x;
    else {
        int rx = radacina(tati[x]);
        tati[x] = rx;
        return rx;
    }
}

bool aceeasi_multime ( int x, int y) {
    return radacina(x) == radacina(y);
}

void unire_multime ( int x, int y)  {
    int rx = radacina(x);
    int ry = radacina(y);
    if ( inaltime[rx] > inaltime[ry] ) {
        tati[ry] = rx; 
    }
    else if ( inaltime[rx] < inaltime[ry] ) {
        tati[rx] = ry;
    }
    else {
        tati[ry] = rx;
        inaltime[rx] ++;
    }
}

int main () {
    fin >> N >> M >> K;
    tati.resize(N + 1);
    inaltime.resize(N + 1);
    while ( M -- ) {
        fin >> x >> y >> c;
        G.push_back({c, {x, y}});
    }
    for ( int i = 1; i<= N; ++ i ) {
        tati[i] = i; 
    }
    sort(G.begin(), G.end() );
    cc = N;
    for ( auto nod : G ) {
        x = nod.second.first;
        y = nod.second.second;
        if ( cc > K && !aceeasi_multime(x, y) ) {
            unire_multime(x, y);
            cc --;
        } 
        else {
            res.push_back({x, y});
            ctot += nod.first;
        }
    }

    fout << ctot << '\n';
    fout << res.size() << '\n';
    for ( auto v : res ) {
        fout << v.first << " " << v.second << '\n';
    }
    return 0;
}