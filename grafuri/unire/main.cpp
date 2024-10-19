#include <bits/stdc++.h>

using namespace std;

ifstream fin ("unire.in");
ofstream fout ("unire.out");

const int MAXN = 1e5 + 5;
int N, M, c, cont;
long long s;
vector <int> G[MAXN];
bool viz[MAXN];

void dfs(int nod) {
    viz[nod] = 1;
    for ( auto it : G[nod] ) {
        if ( !viz[it] ) dfs(it);
    }
}

void solve ( ) {
    if ( c == 1 ) fout << cont - 1;
    if ( c == 2 ) fout << s;
}

int main () {
    fin >> N >> M >> c;
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

            if ( i > 1) {
                s = s + i + 1;
            }
        }
    }
    solve();
    return 0;
}
