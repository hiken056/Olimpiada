#include <bits/stdc++.h>

using namespace std;

ifstream in ("lanterna.in");
ofstream out ("lanterna.out");

#define MAXN 55
#define oo 1e7

int N, M, K;
bool baza[MAXN];
int timp[MAXN];
int lant;
int path[MAXN];

vector < pair < pair < int, int > , int > > G[MAXN];
set < pair < int, int > > S;

int main () {
    in >> N >> K;   
    for ( int i = 1; i <= N; ++ i ) {
        in >> baza[i];
    }
    while ( M -- ) {
        int x, y, t, w;
        in >> x >> y >> t >> w;
        G[x].push_back({{y, t}, w});
        G[y].push_back({{x, t}, w});
    }
    for ( int i = 2; i <= N; ++ i ) {
        timp[i] = oo;
    }
    path[1] = 1;
    S.insert({0, 1});
    while ( !S.empty() ) {
        int nod = S.begin()->second;
        S.erase(S.begin());
        for (auto vecin : G[nod] ) {
            cout << vecin.first.second << " ";
            if ( timp[vecin.first.first] > timp[nod] + vecin.first.second ) {
                S.erase({timp[vecin.first.first], vecin.first.first});
                timp[vecin.first.first] = timp[nod] + vecin.first.second;
                S.insert({timp[vecin.first.first], vecin.first.first});
                path[vecin.first.first] = path[nod]; 
            }
        }
    }
    
    for ( int i = 1; i<= N; ++ i ) {
        out << path[i] << " ";
    }

    return 0;
}
