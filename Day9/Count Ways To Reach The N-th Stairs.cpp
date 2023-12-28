#include <bits/stdc++.h> 
int getCount(int currStep, int nStairs, vector<int> &dp, const int &mod) {

    // Base case.
    if (currStep >= nStairs) {

        return (currStep == nStairs);
    }

    // Check we have already solution or not?.
    if (dp[currStep] != -1) {

        return dp[currStep];
    }

    // Climb one stair.
    int oneStepcount = getCount(currStep + 1, nStairs, dp, mod);

    // Climb two stairs.
    int twoStepCount = getCount(currStep + 2, nStairs, dp, mod);

    // Store for later use.
    dp[currStep] = (oneStepcount + twoStepCount) % mod;

    return dp[currStep];
}

int countDistinctWays(int nStairs) {
    
    // Initialize the variable 'mod'.
    const int mod = 1000000007;

    // Create an array 'dp' of length 'nStairs + 1' with initial value '-1'.
    vector<int> dp(nStairs + 1, -1);

    // Initialize the variable 'ways'.
    int ways = getCount(0, nStairs, dp, mod);

    return ways;
}
