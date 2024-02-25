#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int numberOfNodes, numberOfEdges;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> onCurrentChain;
vector<int> initialIndex;
vector<int> lowlinkIndex;
vector<int> costs;
vector<vector<int>> stronglyConnectedComponents;
stack<int> visitingStack;
int globalIndex;

void initGraphs() {
    graph = vector<vector<int>>(numberOfNodes + 1);
    visited = vector<bool>(numberOfNodes + 1, false);
    onCurrentChain = vector<bool>(numberOfNodes + 1, false);
    initialIndex = vector<int>(numberOfNodes + 1);
    lowlinkIndex = vector<int>(numberOfNodes + 1);
    costs = vector<int>(numberOfNodes + 1);
}

void readData() {
    cin >> numberOfNodes;
    initGraphs();
    for (int i = 1; i <= numberOfNodes; ++i) {
        cin >> costs[i];
    }
    int x, y;

    cin >> numberOfEdges;
    while (numberOfEdges--) {
        cin >> x >> y;
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

void computeAnswer() {
    long long minimumSum = 0;
    long long ways = 1;
    long long minimumValue, occurences;
    for (const auto& component: stronglyConnectedComponents) {
        minimumValue = 2e9, occurences = 1;
        for (const int& node: component) {
            if (costs[node] < minimumValue) {
                minimumValue = costs[node];
                occurences = 1;
            }
            else if (costs[node] == minimumValue) {
                ++occurences;
            }
        }
        minimumSum += minimumValue;
        ways = ((ways % MOD) * (occurences % MOD)) % MOD;
    }
    cout << minimumSum << ' ' << ways;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    readData();
    computeStronglyConnectedComponents();
    computeAnswer();
    return 0;
}
