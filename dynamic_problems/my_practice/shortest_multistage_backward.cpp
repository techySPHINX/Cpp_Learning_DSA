#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int findShortestPath(int n, vector<vector<int>>& matrix, int start, int target) {
    
    vector<int> cost(n, INT_MAX);
    cost[target] = 0; 

    
    for (int i = target; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0 && cost[j] != INT_MAX) { 
                if (cost[i] > cost[j] + matrix[i][j]) {
                    cost[i] = cost[j] + matrix[i][j];
                }
            }
        }
    }

   
    return cost[start];
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use 0 for no edge):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int start, target;
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "Enter the target vertex: ";
    cin >> target;

    int minCost = findShortestPath(n, matrix, start, target);
    
    if (minCost == INT_MAX) {
        cout << "There is no path from vertex " << start << " to vertex " << target << endl;
    } else {
        cout << "The minimum cost of the path from vertex " << start << " to vertex " << target << " is: " << minCost << endl;
    }

    return 0;
}
