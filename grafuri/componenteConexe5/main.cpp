#include <bits/stdc++.h>

using namespace std;

ifstream fin ("componenteconexe5.in");
ofstream fout ("componenteconexe5.out");

const int LIMN = 1000;

int N, M, G[LIMN][LIMN], q, nr, nrc = 0;
int viz[101];


void dfs (int root ) {
    viz[root] = nrc;
    for ( int i = 1; i <= N; ++ i ) {
        if ( !viz[i] && G[i][root] ) dfs(i);
    }
}

void solve (int nr) {
    int elem = 0;
    for ( int i = 1; i <= N; ++ i ) {
        if ( viz[i] == viz[nr] ) elem ++;
    }
    fout << elem << '\n';
}

int main () {
    fin >> N >> M;
    int x, y;
    for (int i = 1; i <= M; ++ i ) {
        fin >> x >> y;
        G[x][y] = 1;
        G[y][x] = 1;
    }
    fin >> q;
    for ( int i = 1; i <= N; ++ i ) {
        if ( !viz[i] ) {
            nrc++;
            dfs(i);
        }
    }
    while ( q -- ) {
        fin >> nr;
        solve(nr);
    }
    return 0;
}