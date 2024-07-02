#include <iostream>
#include <vector>
#include "../../../../../MinGW/include/c++/11.2.0/bits/algorithmfwd.h"

using namespace std;

void rotate_matrix(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    if (n != matrix[0].size())
    {
        throw runtime_error("Input matrix must be square.");
    }

    // Transpose the matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row 
    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "matrix:\n";
    for (const vector<int> &row : matrix)
    {
        for (int element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    rotate_matrix(matrix);

    cout << "\nRotated matrix:\n";
    for (const vector<int> &row : matrix)
    {
        for (int element : row)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
