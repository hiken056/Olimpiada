#include <bits/stdc++.h>

using namespace std;

ifstream fin ("estearbore.in");
ofstream fout ("estearbore.out");

int N, G[101][101];
int viz[101];


void bfs (int root ) {
    int q[101];
    int in = 1, sf = 1;
    viz[root] = 1;
    q[1] = root;
    while ( in <= sf ) {
        int x = q[in];
        for ( int i = 1; i <= N; ++ i ){
            if ( viz[i] == 0 && G[i][x]) {
                viz[i] = 1;
                q[++sf] = i;
            }
        }
        in ++;
    }
}

int main () {
    fin >> N;
    int x, y;
    int M = 0;
    while ( fin >> x >> y ) {
        G[x][y] = 1;
        G[y][x] = 1;
        M += 1;
    }
    if ( N + 1 != M ){
        fout << "NU", exit(0);
    }
    bfs(1);

    for ( int i = 1; i <= N; ++ i ) {
        if ( viz[i] == 0 ) 
            fout << "NU", exit(0);
    }
    fout << "DA";
    return 0;
}