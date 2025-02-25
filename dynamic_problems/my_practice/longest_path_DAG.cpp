#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;

void topological(int v, vector<bool>& visited, vector<int>& stack, const vector<vector<pair<int, int>>>& adj) {
    visited[v] = true;

    for (auto& neighbor : adj[v]) {
        if (!visited[neighbor.first]) {
            topological(neighbor.first, visited, stack, adj);
        }
    }

    stack.push_back(v);
}
int longestPathInDAG(int n, const vector<pair<pair<int, int>, int>>& edges) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;
        adj[u].push_back({v, weight});
    }

    
    vector<bool> visited(n, false);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topological(i, visited, stack, adj);
        }
    }

    vector<int> dist(n, INT_MIN);
    dist[stack.back()] = 0; 

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        if (dist[u] != INT_MIN) {
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] < dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    int longestPath = *max_element(dist.begin(), dist.end());
    return (longestPath == INT_MIN) ? 0 : longestPath;
}

int main() {
    int n; 
    std::cout << "Enter number of vertices: ";
    std::cin >> n;

    int m; 
    std::cout << "Enter number of edges: ";
    std::cin >> m;

    vector<pair<pair<int, int>, int>> edges(m); 
    std::cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        edges[i] = {{u, v}, weight};
    }

    int longestPathLength = longestPathInDAG(n, edges);
    std::cout << "The length of the longest path in the DAG is: " << longestPathLength << endl;

    return 0;
}
