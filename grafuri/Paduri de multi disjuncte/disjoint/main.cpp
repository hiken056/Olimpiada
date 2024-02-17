#include <bits/stdc++.h>

using namespace std;

ifstream fin ( "disjoint.in");
ofstream fout ("disjoint.out");

int n, queries;
vector<int>root, height;

void initializeRoots () { //initializam root urile cu valorile lor 
    for ( int i = 1; i <= n; ++ i) {
        root[i] = i;
    }
}

void readData () { //citim
    fin >> n >> queries;
    root = vector<int>(n+1);
    height = vector<int>(n+1); 
    initializeRoots();
}

int getRoot (int node) {   //tinem minte root-ul pentru fiecare node
    if ( root[node] == node) 
        return node;
    return (root[node] = getRoot(root[node]));
}

void unite ( int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if ( rootX != rootY ) {
        if ( height[rootX] <= height[rootY] ) {
            root[rootX] = rootY;
            if ( height[rootX] == height[rootY] )
                ++height[rootY];
        }
        else {
            root[rootY] = rootX;
        }
    }
}

bool query ( int x, int y) {
    return getRoot(x) == getRoot(y);
}

void solveQueries () {
    int task, x, y;
    while (queries -- ) {
        fin >> task >> x >> y;
        if (task == 1 ) {
            unite(x,y);
        }
        else {
            if ( query (x, y)) 
                fout << "DA\n"; 
            else 
                fout << "NU\n";
        }
    }
}

int main() {
    readData();
    solveQueries();

    fin.close();
    fout.close();
    return 0;   
}