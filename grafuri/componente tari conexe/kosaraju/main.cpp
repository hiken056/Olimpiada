#include <bits/stdc++.h>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int numberOfNodes, numberOfEdges;
vector<vector<int>> graph;
vector<vector<int>> transposedGraph;
vector<bool> visited;
stack<int> visitingStack;
vector<vector<int>> stronglyConnectedComponents;

void initGraphs() {
    graph = vector<vector<int>>(numberOfNodes + 1);
    transposedGraph = vector<vector<int>>(numberOfNodes + 1);
    visited = vector<bool>(numberOfNodes + 1, false);
}

void readData() {
    fin >> numberOfNodes >> numberOfEdges;
    initGraphs();
    int x, y;
    while (numberOfEdges--) {
        fin >> x >> y;
        graph[x].emplace_back(y);
        transposedGraph[y].emplace_back(x);
    }
}

void dfs(int node) {
    visited[node] = true;
    for (const int& neighbour: graph[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
    visitingStack.emplace(node);
}

void visitNodesInGraph() {
    for (int i = 1; i <= numberOfNodes; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void dfsTransposed(int node, vector<int>& stronglyConnectedComponent) {
    visited[node] = false;
    stronglyConnectedComponent.emplace_back(node);
    for (const int& neighbour: transposedGraph[node]) {
        if (visited[neighbour]) {
            dfsTransposed(neighbour, stronglyConnectedComponent);
        }
    }
}

void visitNodesInTransposedGraph() {
    int node;
    while (!visitingStack.empty()) {
        node = visitingStack.top();
        visitingStack.pop();

        if (visited[node]) {
            vector<int> stronglyConnectedComponent;
            dfsTransposed(node, stronglyConnectedComponent);
            stronglyConnectedComponents.emplace_back(stronglyConnectedComponent);
        }
    }
}

void solveConnectedComponents() {
    visitNodesInGraph();
    visitNodesInTransposedGraph();
}

void printStronglyConnectedComponents() {
    fout << stronglyConnectedComponents.size() << '\n';
    for (const auto& component: stronglyConnectedComponents) {
        for (const int& node: component) {
            fout << node << ' ';
        }
        fout << '\n';
    }
}

int main()
{
    readData();
    solveConnectedComponents();
    printStronglyConnectedComponents();

    fin.close();
    fout.close();
    return 0;
}
