#include <bits/stdc++.h>

using namespace std;

ifstream fin ("royfloyd.in");
ofstream fout ("royfloyd.out");

const int MAXN = 105;
int N;
int dist[MAXN][MAXN];

void RoyFloyd () {
    for ( int k = 1; k <= N; ++ k ) {
        for ( int i = 1; i <= N; ++i ) {
            for ( int j = 1; j <= N; ++ j ) {
                //incercam fieacre i, j cu un nod auxiliar k
                if ( i == j ) continue;
                dist[i][j] = min ( dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void afisare() {
    for ( int i = 1; i <= N; ++ i ) {
        for ( int j = 1; j <= N; ++ j ) {
            if ( dist[i][j] == 1e5 ) fout << 0 << " ";
            else fout << dist[i][j] << " ";
 
        }
        fout << '\n';
    }
}

int main () {
    fin >> N;
    for ( int i = 1; i <= N; ++ i) {
        for ( int j = 1; j <= N; ++ j ) {
            fin >> dist[i][j];
            if ( dist[i][j] == 0 ) dist[i][j] = 1e5;
        }
    }
    RoyFloyd();
    afisare();
    return 0;
}