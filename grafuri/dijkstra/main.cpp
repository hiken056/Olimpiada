#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout ("dijkstra.out");

const int MAXN = 5e4 + 5;

int N, M;
vector < pair <int, int> > G[MAXN];
set < pair < int, int > > s;
bool viz[MAXN];
int dist[MAXN];

int main () {
    fin >> N >> M;
    for ( int i = 1; i <= M; ++ i ) {
        int x, y, c;
        fin >> x >> y >> c;
        G[x].push_back({y, c});
    }
    dist[1] = 0;
    for ( int i = 2; i <= N; ++ i ) {
        dist[i] = 1e7;
    }
    s.insert(0, 1);

    return 0;
}