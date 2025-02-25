#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

class OptimalBST {
public:
    OptimalBST(const vector<int>& keys, const vector<int>& freq) 
        : keys(keys), freq(freq), n(keys.size()) {
        cost = vector<vector<int>>(n, vector<int>(n, 0));
        root = vector<vector<int>>(n, vector<int>(n, 0));
        calculateOBST();
    }

    int getMinCost() {
        return cost[0][n - 1];
    }

    void printTreeStructure(int i, int j) {
        if (i > j) return;
        int r = root[i][j];
        cout << "Key: " << keys[r] << " (Frequency: " << freq[r] << ")\n";
        cout << "Left subtree of " << keys[r] << ":\n";
        printTreeStructure(i, r - 1);
        cout << "Right subtree of " << keys[r] << ":\n";
        printTreeStructure(r + 1, j);
    }

private:
    vector<int> keys;
    vector<int> freq;
    int n;
    vector<vector<int>> cost;
    vector<vector<int>> root;

    void calculateOBST() {
        for (int i = 0; i < n; ++i) {
            cost[i][i] = freq[i];
            root[i][i] = i;
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                cost[i][j] = numeric_limits<int>::max();
                for (int r = i; r <= j; ++r) {
                    int c = (r > i ? cost[i][r - 1] : 0) + 
                            (r < j ? cost[r + 1][j] : 0) + 
                            sumFrequency(i, j);
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        root[i][j] = r;
                    }
                }
            }
        }
    }

    int sumFrequency(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; ++k) {
            sum += freq[k];
        }
        return sum;
    }
};

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    vector<int> keys(n);
    vector<int> freq(n);
    cout << "Enter the keys:\n";
    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
    }
    cout << "Enter the corresponding frequencies:\n";
    for (int i = 0; i < n; ++i) {
        cin >> freq[i];
    }
    OptimalBST obst(keys, freq);
    cout << "Minimum search cost: " << obst.getMinCost() << endl;
    cout << "Structure of the Optimal Binary Search Tree:\n";
    obst.printTreeStructure(0, n - 1);
    return 0;
}
