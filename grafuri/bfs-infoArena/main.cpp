#include <bits/stdc++.h>

using namespace std;

ifstream fin ("bfs.in");
ofstream fout ("bfs.out");

const int MAXN = 1e5 + 5;
int N, M, X;
vector <int>G[MAXN];
queue <int> Q;
int rez[MAXN];

void bfs ( int root ) {
    Q.emplace(root);
    while ( !Q.empty() ) {
        int node = Q.front();
        Q.pop();
        for ( auto vecin : G[node] ) {
            if ( rez[vecin] == -1 ) {
                rez[vecin] = rez[node] + 1;
                Q.emplace(vecin);
            }
        }
    }
}

int main ( ) {
    fin >> N >> M >> X;
    while ( M -- ) {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 1; i <= N; ++ i ) {
        rez[i] = -1;
    }
    rez[X] = 0;
    bfs(X);    
    for ( int i = 1; i <= N; ++ i ) {
        fout << rez[i] << " ";
    }
    return 0;
}