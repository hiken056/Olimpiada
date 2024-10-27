#include <bits/stdc++.h>

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout ("dijkstra.out");

#define in fin
#define out fout 
#define oo 1e9
#define ll long long
#define MAXN 50005

int N, M;
vector <pair <int , int> > G[MAXN];
int dist[MAXN];
set <pair <ll, int> > s; //retinem distanta si nodul si in s.begin() avem dist minima



int main () {
    in >> N >> M;
    while ( M -- ) {
        int x, y, c;
        in >> x >> y >> c;
        G[x].push_back({y, c});
    }
    dist[1] = 0;
    for ( int i = 2; i <= N; ++ i ) {
        dist[i] = oo;
    }
    s.insert({0, 1});
    while ( !s.empty() ) {
        int nod = s.begin()->second;
        s.erase(s.begin());
        for ( auto vecin : G[nod] ) {
            if ( dist[vecin.first] > dist[nod] + vecin.second ) {
                //vecin.first este nodul vecin
                //vecin.second este costul muchiei intre nod si vecin
                //dist[nod] = distanta de la root la nod
                s.erase({dist[vecin.first], vecin.first});
                //stergi din set dist si nodul
                dist[vecin.first] = dist[nod] + vecin.second;
                //actualizezi distanta care este mai mica 
                s.insert({dist[vecin.first], vecin.first});
                //inserezi distanta noua in set fiind ordonat
            }
        }
    }

    for ( int i = 2; i <= N; ++ i ) {
        if ( dist[i] == oo ) out << 0 << " ";
        else out << dist[i] << " ";
    }
    return 0;
}