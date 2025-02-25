#include <iostream>

using namespace std;

int climbStairs(int n){
    if(n <= 1){
        return 1;
    }

    int steps[n+1];

    steps[0] = 1;
    steps[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        steps[i] = steps[i-1] + steps[i-2];
    }

    return steps[n];
    
}

int main() {
  int numStairs = 4;
  int ways = climbStairs(numStairs);
  cout << "Number of ways to climb " << numStairs << " stairs: " << ways << endl;
  return 0;
}