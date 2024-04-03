//https://atcoder.jp/contests/dp/tasks/dp_d
//https://atcoder.jp/contests/dp/submissions/51975680

#include <bits/stdc++.h>
using namespace std;

int W, N;

long long knapsack(vector<int>& weights, vector<long long>& values)
{
    vector<long long> dp(W + 1, 0);

    for(int i = 0; i < N; i++)
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

    cin >> N >> W;

    vector<int> weights(N);
    vector<long long> values(N);

    for(int i = 0; i < N; i++)
    {
        cin >> weights[i] >> values[i];
    }

    cout << knapsack(weights, values) << "\n";
}
