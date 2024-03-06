#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dfs.in");
ofstream fout ("dfs.out");

const int MAXN = 100;

vector <int>G[MAXN + 5];
int N, M, X;
bool viz[MAXN + 5];

void dfs ( int node) {
    viz[node] = 1; 
    fout << node << " ";
    for ( const auto& vecin: G[node]) {
        if (!viz[vecin]) {
            dfs(vecin);
        }
    }
}

int main () {

    fin >> N >> M >> X;
    int x, y;
    for ( int i = 1; i <= M; ++ i ) {
        fin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for ( int i = 1; i <= N; ++ i) {
        sort(G[i].begin(), G[i].end());
    }
    dfs(X);

    fin.close();
    fout.close();
    return 0;
}