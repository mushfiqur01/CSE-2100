//https://atcoder.jp/contests/dp/tasks/dp_f?lang=en

#include<bits/stdc++.h>
using namespace std;

#define nl << "\n"

string LCS(string X, string Y)   //LCS = Longest Common Subsequence
{
    int m = X.size();
    int n = Y.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; ++i)   // Build the DP table
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0)   // Reconstruct the LCS
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs = X[i - 1] + lcs;
            i--, j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }

    return lcs;

}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    string a, b, ans;
    cin >> a >> b;

    ans = LCS(a, b);

    cout << ans nl;
}
