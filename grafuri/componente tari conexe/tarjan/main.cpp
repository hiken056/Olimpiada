#include <bits/stdc++.h>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int numberOfNodes, numberOfEdges;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> onCurrentChain;
vector<int> initialIndex;
vector<int> lowlinkIndex;
vector<vector<int>> stronglyConnectedComponents;
stack<int> visitingStack;
int globalIndex;

void initGraphs() {
    graph = vector<vector<int>>(numberOfNodes + 1);
    visited = vector<bool>(numberOfNodes + 1, false);
    onCurrentChain = vector<bool>(numberOfNodes + 1, false);
    initialIndex = vector<int>(numberOfNodes + 1);
    lowlinkIndex = vector<int>(numberOfNodes + 1);
}

void readData() {
    fin >> numberOfNodes >> numberOfEdges;
    initGraphs();
    int x, y;
    while (numberOfEdges--) {
        fin >> x >> y;
        graph[x].emplace_back(y);
    }
}

void tarjan(int node) {
    visited[node] = true;
    initialIndex[node] = lowlinkIndex[node] = ++globalIndex;
    visitingStack.emplace(node);
    onCurrentChain[node] = true;

    for (const int& neighbour: graph[node]) {
        if (!visited[neighbour]) {
            tarjan(neighbour);
            lowlinkIndex[node] = min(lowlinkIndex[node], lowlinkIndex[neighbour]);
        }
        else if (onCurrentChain[neighbour]) {
            lowlinkIndex[node] = min(lowlinkIndex[node], initialIndex[neighbour]);
        }
    }

    if (initialIndex[node] == lowlinkIndex[node]) {
        vector<int> stronglyConnectedComponent;
        int stackNode;
        do {
            stackNode = visitingStack.top();
            visitingStack.pop();

            onCurrentChain[stackNode] = false;
            stronglyConnectedComponent.emplace_back(stackNode);
        } while (stackNode != node);
        stronglyConnectedComponents.emplace_back(stronglyConnectedComponent);
    }
}

void computeStronglyConnectedComponents() {
    for (int node = 1; node <= numberOfNodes; ++node) {
        if (!visited[node]) {
            tarjan(node);
        }
    }
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
    computeStronglyConnectedComponents();
    printStronglyConnectedComponents();

    fin.close();
    fout.close();
    return 0;
}
