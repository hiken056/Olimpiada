#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dfs.in");
ofstream fout ("dfs.out");

const int MAXN = 1e5 + 5;
int N, M, cont;
vector <int> G[MAXN];
bool viz[MAXN];

void dfs(int nod) {
    viz[nod] = 1;
    for ( auto it : G[nod] ) {
        if ( !viz[it] ) dfs(it);
    }
}

int main () {
    fin >> N >> M;
    int x, y;
    while ( M-- ) {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for ( int i = 1; i <= N; ++ i ) {
        if ( !viz[i] ) {
            cont  ++;
            dfs(i);
        }
    }
    fout << cont;
    return 0;
}
