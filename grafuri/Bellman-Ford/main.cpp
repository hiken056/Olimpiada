#include <bits/stdc++.h>

using namespace std;

ifstream in ("bellmanford.in");
ofstream out ("bellmanford.out");

#define oo 1e9
#define MAXN 50005

int N, M;
vector < pair < int, int > > G[MAXN];
queue < int > Q;
bool ok = 1;
int viz[MAXN];
bool inQ[MAXN];
int dist[MAXN];

int main () {
    in >> N >> M;
    while ( M -- ) {
        int x, y, c;
        in >> x >> y >> c;
        G[x].push_back({y, c});
    }  
    dist[1] = 0;
    Q.push(1);
    inQ[1] = 1;

    while ( ! Q.empty( ) ) {
        
    }
    return 0;
}