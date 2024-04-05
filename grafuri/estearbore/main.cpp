#include <bits/stdc++.h>

using namespace std;

ifstream fin ("estearbore.in");
ofstream fout ("estearbore.out");

int N, M, x, y, G[101][101];
bool viz[101];

void bfs(int root) {
    queue <int> Q;
    viz[root] = 1;
    Q.emplace(root);
    while (!Q.empty() ) {
        for ( int i = 1; i <= N; ++ i ) {
            if ( viz[i] == 0 && G[i][Q.front()])
            viz[i] = 1;
            Q.emplace(i);   
        }
        Q.pop();
    }
} 

int main () {
    fin >> N;
    M = 0;
    while ( fin >> x >> y ) {
        G[x][y] = 1;
        G[y][x] = 1;
        M ++;
    }
    fout << M << '\n';
    bfs(1);
    for ( int i = 1; i <= N; ++ i ) {
        fout << viz[i] << " ";
    }
    return 0;
}