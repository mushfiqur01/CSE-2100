//https://www.spoj.com/problems/LKS/
//https://www.spoj.com/status/LKS,mushfiqur_1/

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
        cin >> values[i] >> weights[i];
    }

    cout << knapsack(weights, values) << "\n";
}
