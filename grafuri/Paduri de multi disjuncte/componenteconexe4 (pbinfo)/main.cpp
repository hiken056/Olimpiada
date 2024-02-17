#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int x, y;  
};

int n, m;

vector <Edge> edges;
vector <int> root, height;
vector <int> sol;

void readData () {
    cin >> n >> m;
    edges.resize(m);
    for ( auto&  edge: edges ) {
        cin >> edge.x >> edge.y;
    }
}


void initialize () {
    root = vector<int>(n+1);
    height = vector<int>(n+1);
    for ( int i = 1; i <= n; ++ i ) {
        root[i] = i;
    }
}

int getRoot(int node) {
    if (node == root[node])
        return node;
    return root[node] = getRoot(root[node]);
}

bool query ( int x, int y) {
    return getRoot(x) == getRoot(y);
}

void unite ( int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX != rootY ) {
        if ( height[rootX] <= height[rootY] ) 
            root[rootX] = rootY;
            if ( height[rootX] == height[rootY] ) 
                ++ height[rootY];
        else {
            root[rootY] = rootX;
        }
    }
}

void solve () {
    int componente = n;
    sol.push_back(componente);
    for ( int i = m-1; i >= 0; -- i) {
        componente -= !query(edges[i].x, edges[i].y);
        unite(edges[i].x, edges[i].y);
        sol.push_back(componente);
    }
}

int main () {
    readData();
    initialize();
    solve();

    for ( int i = m-1; i >= 0; -- i) {
        cout << sol[i] << '\n';
    }
    return 0;
}

//inghetata, jeluri, barni, crananele (chipsuri de la lidl), cheez-bals, toblerone, limnada, fruncte inghetate, batoane, popcorn caramel, garlic bread, strufafel, pretzel, afine, nachos, mango, mini muffins, oreo, carnaciori, cookies-subway, 