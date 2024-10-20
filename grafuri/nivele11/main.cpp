#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nivele11.in");
ofstream fout ("nivele11.out");

const int MAXN = 105;
int N, root, nrNiv;
vector < int > G[MAXN];
set < int > lvls[MAXN];
bool viz[MAXN];

void dfs ( int node, int lvl ) {
    viz[node] = 1;
    nrNiv = max( lvl, nrNiv);
    lvls[lvl].insert(node);
    for ( auto vecin : G[node] ) {
        if ( !viz[vecin] ) {
            dfs(vecin, lvl + 1);
        }
    }
}

int main () {
    fin >> N;
    for ( int i = 1; i <= N; ++ i ) {
        int x;
        fin >> x;
        if ( x == 0 ) root = i;
        else {
            G[x].push_back(i);
            G[i].push_back(x);
        }
    }
    dfs(root, 0);
    for ( int i = 0; i <= nrNiv; ++ i ) {
        for ( auto it : lvls[i] ) {
            fout << it << " ";
        }
        fout << '\n';
    }
    return 0;
}