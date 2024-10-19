#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nivele11.in");
ofstream fout ("nivele11.out");

const int MAXN = 1e2 + 5;

int N, nr;
int tati[MAXN];
vector <int> G[MAXN];

int main () {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        fin >> tati[i];
        if ( tati[i] > nr ) nr = tati[i];
    }
    for ( int i = 0; i <= nr; ++i ) {
        for ( int j = 1; j <= N; ++ j ) {
            if ( tati[j] == i ) fout << j << " ";
        }
        fout << '\n';
    }
    return 0;
}