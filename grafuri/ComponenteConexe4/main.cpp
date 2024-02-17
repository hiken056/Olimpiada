#include <bits/stdc++.h>
 
using namespace std;

int n, m;
vector <Edge> edges;
vector <int> parent;
vector <int> height;

struct Edge {
    int x;
    int y;   
}

void read () {
    cin >> n >> m;
    edges.resize(n + 1);
    parent.resize(n+1);
    for (auto& edge: edges) {
        cin >> edge.x >> edge.y;
    }
}

int getRoot ( int node) {
    if ( node == parent[node] ) return node;
    return parent[node] = getRoot(parent[node]);
}

bool queries ( int x, int y) {
    return parent[x] == parent[y];
}

void unite ( int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX != rootY ) {
        if ( height[rootX] <= height[rootY] ) {
            parent[rootX] = rootY;
            if ( height[rootX] == height[rootY] )
                ++height[rootY];
        }
        else {
            parent[rootY] = rootX;
        }
    }
}

vector<int> sol;

void solve() {
    int componente = n;
    cout << componente << '\n';
    for ( int i = n-1; i >= 1; -- i) {
        componente -= !queries(edges[i]);
        unite ( edges[i].x, edges[i].y);
        sol.push_back(componente);
    }
}   
int main () {
    read();
    
    return 0;
}