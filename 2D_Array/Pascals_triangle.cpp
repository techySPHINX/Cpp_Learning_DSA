#include <iostream>
#include <vector>

using namespace std;

void printPascal(int n) {
  vector<vector<int>> pascal(n);

  for (int i = 0; i < n; i++) {
    pascal[i].resize(i + 1); // Allocate space for each row

    // Initialize first and last elements of each row
    pascal[i][0] = 1;
    pascal[i][i] = 1;

    // Calculate other elements using previous row values
    for (int j = 1; j < i; j++) {
      pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }

  // Print the triangle
  for (const vector<int>& row : pascal) {
    for (int element : row) {
      cout << element << " ";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cout << "Enter the number of rows: ";
  cin >> n;

  printPascal(n);

  return 0;
}
