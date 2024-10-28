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
    for ( int i = 1; i <= N; ++ i ) {
        dist[i] = oo;
    }
    dist[1] = 0;
    Q.push(1);
    inQ[1] = 1;
    
    while ( ! Q.empty() && ok == 1 ) {
        int nod = Q.front();
        Q.pop();
        inQ[nod] = 0;
        viz[nod] ++;
        if ( viz[nod] >= N ) {
            ok = 0;
            break;
        }
        for ( auto vecin : G[nod] ) {
            if ( dist[vecin.first] > dist[nod] + vecin.second )  {
                dist[vecin.first] = dist[nod] + vecin.second;
                if ( inQ[vecin.first] == 0 ) {
                    Q.push(vecin.first);
                    inQ[vecin.first] = 1;
                }
            }
        }
    }

    if ( ok == 0 ) out << "Ciclu negativ!";
    else {
        for ( int i = 2; i <= N; ++ i ) {
            out << dist[i] << " ";
        }
    }
    return 0;
}