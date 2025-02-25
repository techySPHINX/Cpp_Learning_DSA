#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCostToReachTarget(int n, vector<vector<int>>& graph, int start, int target) {
    vector<int> minCost(n, INT_MAX);
    
    minCost[target] = 0;

    for (int i = target; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != 0 && minCost[j] != INT_MAX) { 
                minCost[i] = min(minCost[i], graph[i][j] + minCost[j]);
            }
        }
    }

    return minCost[start];
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (0 for no edge):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, target;
    cout << "Enter the start vertex and target vertex: ";
    cin >> start >> target;

    int result = minCostToReachTarget(n, graph, start, target);
    if (result == INT_MAX) {
        cout << "There is no path from " << start << " to " << target << endl;
    } else {
        cout << "The minimum cost to reach target " << target << " from start " << start << " is: " << result << endl;
    }

    return 0;
}
