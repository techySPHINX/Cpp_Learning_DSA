#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_value(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + arr[i - 1]);
        }
    }

    return dp[n][k];
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << max_value(arr, k) << endl;
    return 0;
}