#include <bits/stdc++.h>

using namespace std;

ifstream in ("catun.in");
ofstream out ("catun.out");

#define oo 1e9
#define MAXN 36005 

int N, M, K;
vector < pair < int, int > > G[MAXN];
set < pair < int, int > > S;
int fortarete[MAXN];
int dist[MAXN];

int main () {
    in >> N >> M >> K;
    for ( int i = 1; i <= N; ++ i ) {
        dist[i] = oo;
    }
    for ( int i = 1; i <= K; ++ i ) {
        int frt;
        in >> frt;
        dist[frt] = 0;
        fortarete[frt] = frt;
        S.insert({0, frt});
        //inseram frt si distanta in set
    }
    while ( M -- ) {
        int x, y, c;
        in >> x >> y >> c;
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }
    //facem dijkstra de la fortarete
    while ( !S.empty() ) {
        int nod = S.begin() -> second;
        S.erase(S.begin());
        for (  auto vecin : G[nod] ) {
            if ( dist[vecin.first] > dist[nod] + vecin.second ) {
                S.erase({dist[vecin.first], vecin.first});
                //scoatem din set distanta veche
                dist[vecin.first] = dist[nod] + vecin.second;
                //actualizam distanta
                fortarete[vecin.first] = fortarete[nod];
                //actualizam fortareata mai apropiata
                S.insert({dist[vecin.first], vecin.first});
                //bagam in set inapoi distanta actualizata
            } 
            else if ( dist[vecin.first] == dist[nod] + vecin.second ) {
                fortarete[vecin.first] = min ( fortarete[nod], fortarete[vecin.first]);
                //daca distantele is egale, atunci luam fortareata cea mai mica lexicografic
            }
        }
    }

    for ( int i = 1; i <= N; ++ i ) {
        if ( fortarete[i] == i ) out << 0 << " ";
        else out << fortarete[i] << " ";
    }
    return 0;
}