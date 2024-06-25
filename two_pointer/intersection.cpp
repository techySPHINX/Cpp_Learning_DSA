#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionOfArrays(vector<int> A, vector<int> B)
{

    vector<int> ans;

    int i = 0, j = 0;

        while (i < A.size() && j < B.size())
    {

        if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {

            ans.push_back(A[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int main()
{

    vector<int> A{1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> B{3, 3, 4, 4, 5, 8};

    vector<int> ans = intersectionOfArrays(A, B);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}