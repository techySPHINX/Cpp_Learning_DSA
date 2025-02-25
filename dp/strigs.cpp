// Given a string str of lowercase alphabets, the task is to find all distinct palindromic sub-strings of the given string.

#include <bits/stdc++.h>
using namespace std;

int pallindromesubstring(string s)
{
    int dp[s.size()][s.size()]; // to store the position of pallindromic suubstrings
    int st, end, i, j, len;

    map<string, bool> m;

    for (int i = 0; i < s.size(); i++)
    {
        dp[i][i] = 1; //sub strings of length 1 are pallindromes
        m[string(s.begin() + 1, s.begin() + i + 1)] = 1;

    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
            m[string(s.begin() + 1, s.begin() + i + 2)] = 1;
        }
        else{
            dp[i][i+1] = 0;
        }
    }
    
}