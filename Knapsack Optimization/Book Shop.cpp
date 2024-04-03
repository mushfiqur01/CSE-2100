//https://cses.fi/problemset/task/1158
//https://cses.fi/problemset/result/8907914/

#include <bits/stdc++.h>
using namespace std;

int W, n;

int knapsack(vector<int>& weights, vector<int>& values)
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

    cin >> n >> W;

    vector<int> weights(n), values(n);

    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << knapsack(weights, values) << "\n";
}
