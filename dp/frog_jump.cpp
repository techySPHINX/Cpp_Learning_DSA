#include <iostream>

using namespace std;

int minJumps(int n, int jumpDist){
    if(n <= jumpDist){
        return n;
    }

    int jumps[n+1];

    jumps[0] = 0;
    for (int i = 1; i <= jumpDist; i++)
    {
        jumps[i] = 1; // can reach in one jump to JumpDist
    }

    for (int i = jumpDist + 1; i <= n; i++)
    {
        jumps[i] = INT_MAX;
        for (int j = 1; j <= jumpDist && i -j >= 0; j++)
        {
            jumps[i] = min(jumps[i], jumps[i - j] + 1);
        }
        
    }

    if(jumps[n] == INT_MAX){
        return -1;
    }

    return jumps[n];
    
    
}