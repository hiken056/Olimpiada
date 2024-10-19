#include <bits/stdc++.h>

using namespace std;

ifstream fin ("darb.in");
ofstream fout ("darb.out");

const int MAXN = 1e5 + 5;

int N;
vector <int> G[MAXN];
int dist[MAXN];
int lungime, first, distMax;
queue <int> Q;

void bfs ( int root ) {
    Q.emplace(root);
    dist[root] = 0;
    while ( !Q.empty() ) {
        int node = Q.front();
        Q.pop();
        for ( auto vecin : G[node] ) {
            if ( dist[vecin] == -1 ) {
                dist[vecin] = dist[node] + 1;
                Q.emplace(vecin);
            }
        }
    }
}

 
int main () {
    fin >> N;
    int M = N - 1;
    while ( M -- ) {
        int x, y;
        fin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for ( int i = 1; i <= N; ++ i ) dist[i] = -1;
    bfs(1);
    for ( int i = 1; i <= N; ++ i ) {
        if ( dist[i]  > distMax ) {
            distMax = dist[i];
            first = i;
        }    
    }
    for ( int i = 1; i <= N; ++ i ) dist[i] = -1;
    bfs(first);
    distMax = 1;
    for ( int i = 1; i <= N; ++ i ) {
        if ( dist[i] > distMax ) distMax = dist[i];
    }
    fout << distMax + 1;
    return 0;
}