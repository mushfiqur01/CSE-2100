//https://lightoj.com/problem/an-easy-lcs

#include<bits/stdc++.h>
using namespace std;

#define nl << "\n"

string LCS(string X, string Y)   //LCS = Longest Common Subsequence
{
    int m = X.size();
    int n = Y.size();

    vector<vector<string>> dp(m+1, vector<string>(n+1, ""));

    for (int i = 1; i <= m; ++i)   // Build the DP table
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + X[i - 1];
            }
            else
            {
                // Choose the lexicographically smaller LCS if lengths are the same because it is done in sample test
                if (dp[i - 1][j].size() == dp[i][j - 1].size())
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j].size() > dp[i][j - 1].size()) ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
    }

    return dp[m][n];
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    string a, b, ans;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b;

        ans = LCS(a, b);

        cout << "Case " << i << ": ";
        if(ans.size())
        {
            cout << ans nl;
        }
        else
        {
            cout << ":(" nl;
        }
    }
}
