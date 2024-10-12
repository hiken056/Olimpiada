#include <bits/stdc++.h>

using namespace std;

ifstream fin ("graf.in");
ofstream fout ("graf.out");

int N, M, X, Y;
const int MAXN = 7505;
vector <int> G[MAXN];
bool viz[MAXN];
queue <int> Q;

void bfs (int root) {
    Q.emplace(root);
    while ( !Q.empty()) {
        int node = Q.front();
        Q.pop();
        if ( viz[node] ) continue;
        viz[node] = 1;
        for ( const auto& vecin : G[node] ) {
            if ( !viz[node] ) Q.emplace(vecin);
        }
    }
}

int main () {
    fin >> N >> M;
    int x, y;
    while ( M -- ) {
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    } 

    return 0;
}