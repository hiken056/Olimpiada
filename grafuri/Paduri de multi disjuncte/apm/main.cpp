#include <bits/stdc++.h>

using namespace std;

ifstream fin ("apm.in");
ofstream fout ("apm.out");  

struct  Edge
{
    int x, y;
    int cost;

    Edge ( int x, int y, int cost) {
        this -> x = x;
        this -> y = y;
        this -> cost = cost; 
    }

    bool operator < (const Edge& other ) const {
        return cost < other.cost;
    }
};

int n, edges;
vector <int> root, height;
vector <Edge> allEdges;
vector <Edge> mst;
int totalCost;

void intializeRoots () {
    for ( int i = 1; i <= n; ++ i ) {
        root[i] = i;
    }
}

void readAllEdges() {
    int x, y, cost;
    while (edges -- ) {
        fin >> x >> y >> cost;
        allEdges.emplace_back(x, y, cost);
    }
    sort(allEdges.begin(), allEdges.end());
}

void readData() {
    fin >> n >> edges;
    root = vector<int>(n+1);
    height = vector<int>(n+1);
    intializeRoots();
    readAllEdges();
} 

int getRoot ( int node) {
    if ( root[node] == node) 
        return node;
    return (root[node] = getRoot(root[node]));
}

void unite (int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX != rootY ) {
        if ( height[rootX] <= height[rootY] ) {
            root[rootX] = rootY;
            if ( height[rootX] == height[rootY]) {
                ++height[rootY];
            }
        }
        else {
            root[rootY] = rootX;
        }
    }
}

bool query ( int x, int y) {
    return getRoot(x) == getRoot(y);
}

void determineMST () {
    int x, y, cost;
    int totalEdges = 0;
    for ( const auto& edge: allEdges ) {
        x = edge.x;
        y = edge.y;
        cost = edge.cost;

        if (!query(x,y) ) {
            unite(x, y);
            totalCost += cost;
            ++ totalEdges;
            mst.emplace_back(x, y, cost);
        }
        if ( totalEdges == n - 1) 
            break;
    }
}

void printMST () {
    fout << totalCost << '\n';
    fout << n - 1 << '\n';
    for ( const auto& edge: mst) {
        fout << edge.y << " " << edge.x << '\n';
    }
}


int main () {
    readData();
    determineMST();
    printMST();

    fin.close();
    fout.close();
    return 0;
}