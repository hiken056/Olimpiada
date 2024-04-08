#include <bits/stdc++.h>

using namespace std;

ifstream fin ("nrcompconexe.in");
ofstream fout ("nrcompconexe.out");

int N, M, viz[101], nrComp = 0;
vector <int> G[101];
queue <int> Q;


void bfs (int root) {
    Q.emplace(root);
    while ( !Q.empty() ) {
        int node = Q.front();
        Q.pop();
        if ( viz[node] ) continue;
        viz[node] = nrComp;
        for (  const auto& vecin: G[node]) {
            if ( !viz[vecin]) {
                Q.emplace(vecin);
            } 
        }
    }
}

int main () {
    fin >> N >> M;
    int x, y;
    for ( int i = 1; i <= M; ++ i) {
        fin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    } 
    for ( int i = 1; i <= N; ++ i ) {
        if ( viz[i] == 0 ) {
            nrComp += 1;
            bfs(i);
        }
    }
    fout << nrComp;
    return 0;
}