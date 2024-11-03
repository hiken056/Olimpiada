#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int N;
vector <int> G[MAXN];
int dist[MAXN];
int pos[MAXN];
int el[MAXN];
int lastPos[MAXN];
bool viz[MAXN];
queue <int> Q;
vector < pair <int, int> > unsortedNodes, sortedNodes;

int main () {
    cin >> N;
    for ( int i = 1; i < N; ++ i ) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for ( int i = 1; i <= N; ++ i ) {
        cin >> el[i];
        pos[el[i]] = i;
    }

    if ( el[1] != 1 ) {
        cout << "No";
        return 0;
    }

    Q.push(1);
    viz[1] = 1;
    lastPos[1] = 0;
    while ( !Q.empty() ) {
        int nod = Q.front();
        Q.pop();
        for ( auto vecin : G[nod] ) {
            if ( !viz[vecin] ) {
                Q.push(vecin);
                viz[vecin] = 1;
                dist[vecin] = dist[nod] + 1;
                lastPos[vecin] = pos[nod];
            }
        } 
    }

    for ( int i = 1; i <= N; ++ i ) {
        unsortedNodes.push_back({dist[el[i]], lastPos[el[i]]});
        sortedNodes.push_back({dist[el[i]], lastPos[el[i]]});
    }
    sort(sortedNodes.begin(), sortedNodes.end());
    cout << ((sortedNodes == unsortedNodes) ? "Yes" : "No");
    return 0;
}