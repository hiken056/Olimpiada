#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int N;
vector < int > G[MAXN];
queue <int> Q;
bool viz[MAXN];

void bfs ( int root ) {
    Q.emplace(root);
    viz[root] = 1;
    while ( !Q.empty() ) {
        int nod = Q.front();
        Q.pop();
        for ( auto vecin : G[nod] ) {
            if ( !viz[vecin] ) {
                Q.emplace(vecin);
                cout << vecin << " ";
            }
        }
    }
}

int main () {

    return 0;
}