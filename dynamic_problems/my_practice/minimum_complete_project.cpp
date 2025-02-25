#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int minCostToCompleteProject(int n, vector<pair<int, pair<int, int>>>& edges) {
    vector<vector<Edge>> graph(n);
    vector<int> inDegree(n, 0);
    
    for (const auto& edge : edges) {
        int from = edge.first;
        int to = edge.second.first;
        int cost = edge.second.second;
        graph[from].push_back({to, cost});
        inDegree[to]++;
    }

    vector<int> minCost(n, INT_MAX);
    minCost[n - 1] = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (const auto& edge : graph[current]) {
            int next = edge.to;
            int cost = edge.cost;

            if (minCost[current] != INT_MAX) {
                minCost[next] = min(minCost[next], minCost[current] + cost);
            }
            
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    int totalMinCost = 0;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0 && minCost[i] != INT_MAX) {
            totalMinCost += minCost[i];
        }
    }

    return totalMinCost;
}

int main() {
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, pair<int, int>>> edges(m);
    cout << "Enter the edges (from, to, cost):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[i] = {from, {to, cost}};
    }

    int result = minCostToCompleteProject(n, edges);
    cout << "The minimum total cost to complete all tasks is: " << result << endl;

    return 0;
}
