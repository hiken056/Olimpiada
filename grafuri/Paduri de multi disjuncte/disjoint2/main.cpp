#include <bits/stdc++.h>

using namespace std;

ifstream fin ("disjoint.in");
ofstream fout ("disjoint.out");

const int MAXN = 1e5;
int N, M;
int root[MAXN + 5];
int height[MAXN + 5];

int getRoot( int node) {
    if ( root[node] == node ) return node;
    return (root[node] = getRoot(root[node]));
}

bool query (int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    return rootX == rootY;
}

void unite ( int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX == rootY ) return;
    if ( height[rootX] > height[rootY] ) {
        root[rootY] = rootX;
    }
    else {
        root[rootX] = rootY;
        if ( height[rootX] == height[rootY] ) {
            height[rootY] ++;
        }
    }
}

int main () {

    fin >> N >> M;
    int x, y, t;
    for ( int i = 1; i <= N; ++ i) {
        root[i] = i;
    }
    while ( M-- ) {
        fin >> t >> x >> y;
        if ( t == 1 ) {
            unite(x, y);
        }
        else {
            bool rez = query(x, y);
            if ( rez ) fout << "DA\n";
            else fout << "NU\n";
        }
    }
    return 0;
}