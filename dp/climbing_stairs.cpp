// Interviewer : "Imagine you are standing at the base of an ancient mystical staircase, each step inscribed with symbols of Fibonacci’s wisdom. This staircase, however, follows a peculiar rule: at any given moment, you can ascend either one step or two steps at a time. The number of steps in front of you is N. Your task is to determine the number of distinct ways you can reach the top, given this constraint. Can you devise an efficient approach to solve this problem, possibly leveraging the principles of recursion and dynamic programming?"

#include <iostream>

using namespace std;

int climbStairs(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int steps[n + 1];

    steps[0] = 1;
    steps[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        steps[i] = steps[i - 1] + steps[i - 2];
    }

    return steps[n];
}

int main()
{
    int numStairs = 4;
    int ways = climbStairs(numStairs);
    cout << "Number of ways to climb " << numStairs << " stairs: " << ways << endl;
    return 0;
}
