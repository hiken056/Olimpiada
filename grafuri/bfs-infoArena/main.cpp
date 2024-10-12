#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bfs.in");
ofstream fout ("bfs.out");

const int MAXN  = 1e6 + 5;
int N, M, X;
vector <int> G[MAXN];
queue <int> Q;
bool viz[MAXN];
vector<int> path;

void bfs (int root ) {
    Q.emplace(root);
    while ( !Q.empty() ) {
        int node = Q.front();
        Q.pop();
        if ( viz[node] ) continue;
        viz[node] = 1;
        for ( const auto& vecin : G[node] ) {
            if ( !viz[vecin] ) {
                Q.emplace(vecin);
                path[vecin] = path[node] + 1;
            }
        }
    }
}

int main () {
    fin >> N >> M >> X;
    int x, y;
    while ( M -- ) {
        fin >> x >> y;
        G[x].push_back(y);
    }
    bfs(X);
    for ( int i = 1; i <= N; ++ i) {
        if ( path[i] == 0 ) {
            fout << -1 << " ";   
        }
        else fout << path[i] << " ";
    }
    return 0;
}