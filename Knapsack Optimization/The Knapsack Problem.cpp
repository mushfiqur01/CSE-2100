//https://www.spoj.com/problems/KNAPSACK/en/
//https://www.spoj.com/status/KNAPSACK,mushfiqur_1/

//This solution is 98% same as the solution "Large Knapsack".
//The difference between "The Knapsack Problem" and "Large Knapsack" is constants.

#include <bits/stdc++.h>
using namespace std;

int W, n;

long long knapsack(vector<int>& weights, vector<int>& values)
{
    vector<int> dp(W + 1, 0);

    for(int i = 0; i < n; i++)
    {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    return dp[W];
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    cin >> W >> n;

    vector<int> weights(n), values(n);

    for(int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack(weights, values) << "\n";
}
