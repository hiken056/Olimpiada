#include <bits/stdc++.h>

using namespace std;

ifstream fin ("conex.in");
ofstream fout ("conex.out");

int N, x, y;
bool viz[101], G[101][101];

void bfs ( int root ) {
    int q[101];
    viz[root] = 1;
    q[1] = root;
    int in = 1, sf = 1;
    while ( in <= sf ) {
        int x = q[in];
        for ( int i = 1; i <= N; ++ i ) {
            if ( viz[i] == 0 && G[i][x] ) {
                viz[i] = 1;
                q[++sf] = i;
            }
        }
        in ++;
    }
}

int main () {
    fin >> N;
    while ( fin >> x >> y ) {
        G[x][y] = 1;
        G[y][x] = 1;
    }
    bfs(1);
    for ( int i = 1; i <= N; ++ i ) {
        if ( viz[i] == 0 ) fout << "NU", exit(0);
    }
    fout << "DA";
    return 0;
}