#include <bits/stdc++.h>

using namespace std;

ifstream fin ("apm.in");
ofstream fout ("apm.out");

const int MAXN = 2e5;
const int oo = 1e7;


int N, M;
vector < pair < int, int > > G[MAXN];
vector < pair < int, int > > R;
set < pair < int, int > > S;

int x, y, c, ctot;
int dist[MAXN], vec[MAXN];
bool viz[MAXN];

int main () {
    fin >> N >> M;
    while ( M -- ) {
        fin >> x >> y >> c;
        G[x].push_back({y, c});
        G[y].push_back({x, c});
    }
    for ( int i = 1; i <= N; ++ i ) {
        dist[i] = oo;
    }
    dist[1] = 0;
    S.insert({0, 1});
    while ( !S.empty() ) {
        int nod = S.begin() -> second;
        int cost = S.begin() -> first;   
        viz[nod] = 1;
        S.erase(S.begin());
        ctot += cost;
        if (nod != 1) 
            R.push_back({nod, vec[nod]});
        for ( auto vecin : G[nod] ) {
           if (dist[vecin.first] > vecin.second && !viz[vecin.first]) {
                S.erase({dist[vecin.first], vecin.first});
                dist[vecin.first] = vecin.second;
                vec[vecin.first] = nod;
                S.insert({dist[vecin.first], vecin.first});
            }
        }
    }
    fout << ctot << '\n';
    fout << N - 1 << '\n';
    for ( auto n : R ) {
        fout << n.first << " " << n.second << '\n';
    }
    return 0;
}