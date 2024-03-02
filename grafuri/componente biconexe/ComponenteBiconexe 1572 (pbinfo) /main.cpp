#include <bits/stdc++.h>

using namespace std;

ifstream fin("componentebiconexe.in");
ofstream fout("componentebiconexe.out");

int task;
int numberOfVertices, numberOfEdges;
int root = 1;
int sonsOfRoot;
vector <vector <int>> graph;
vector <bool> visited;
vector <int> level, minimumLevel;
stack <pair <int, int>> edgeStack;
vector <pair <int, int>> criticalEdges;
unordered_set <int> articulationPoints;
vector <unordered_set <int>> biconnectedComponents;

void initializeContainers() {
    graph = vector <vector <int>>(numberOfVertices + 1);
    visited = vector <bool>(numberOfVertices + 1, false);
    level = vector <int>(numberOfVertices + 1);
    minimumLevel = vector <int>(numberOfVertices + 1);
}

void readData() {
    fin >> task;
    fin >> numberOfVertices >> numberOfEdges;
    initializeContainers();

    int x, y;
    while (numberOfEdges--) {
        fin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
}

void extractBiconnectedComponent(int node, int neighbour) {
    unordered_set <int> biconnectedComponent;
    pair <int, int> edge;
    do {
        edge = edgeStack.top();
        edgeStack.pop();
        biconnectedComponent.insert(edge.first);
        biconnectedComponent.insert(edge.second);
    } while (edge.first != node && edge.second != neighbour);
    biconnectedComponents.emplace_back(biconnectedComponent);
}

void dfs(int node, int father) {
    visited[node] = true;
    level[node] = level[father] + 1;
    minimumLevel[node] = level[father] + 1;

    for (const int& neighbour: graph[node]) {
        if (neighbour == father) {
            continue;
        }

        if (visited[neighbour]) {
            minimumLevel[node] = min(minimumLevel[node], level[neighbour]);
        }
        else {
            if (node == root) {
                ++sonsOfRoot;
            }
            edgeStack.emplace(node, neighbour);
            dfs(neighbour, node);
            minimumLevel[node] = min(minimumLevel[node], minimumLevel[neighbour]);

            if (minimumLevel[neighbour] >= level[node]) {
                if (minimumLevel[neighbour] > level[node]) {
                    criticalEdges.emplace_back(node, neighbour);
                }
                if (node != root) {
                    articulationPoints.insert(node);
                }
                extractBiconnectedComponent(node, neighbour);
            }
        }
    }
}

void printBiconnectedComponents() {
    fout << biconnectedComponents.size() << '\n';
    for (const auto& biconnectedComponent: biconnectedComponents) {
        fout << biconnectedComponent.size() << ' ';
        for (const int& node: biconnectedComponent) {
            fout << node << ' ';
        }
        fout << '\n';
    }
}

void printArticulationPoints() {
    fout << articulationPoints.size() << '\n';
    for (const int& point: articulationPoints) {
        fout << point << ' ';
    }
}

void printCriticalEdges() {
    fout << criticalEdges.size() << '\n';
    for (const auto& edge: criticalEdges) {
        fout << edge.first << ' ' << edge.second << '\n';
    }
}

void printSolution() {
    if (task == 1) {
        printBiconnectedComponents();
    }
    else if (task == 2) {
        printArticulationPoints();
    }
    else {
        printCriticalEdges();
    }
}

int main()
{
    readData();
    dfs(root, 0);
    if (sonsOfRoot > 1) {
        articulationPoints.insert(root);
    }
    printSolution();
    return 0;
}
