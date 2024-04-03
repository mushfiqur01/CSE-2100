//https://codeforces.com/problemset/problem/335/B
//https://codeforces.com/contest/335/submission/254364310

#include<bits/stdc++.h>
using namespace std;
#define nl << "\n"

string LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    vector<string> dp(n + 1, ""); // Using one-dimensional vector

    for (int i = 1; i <= m; ++i) {
        string prev = dp[0];
        for (int j = 1; j <= n; ++j) {
            string temp = dp[j];
            if (X[i - 1] == Y[j - 1]) {
                dp[j] = prev + X[i - 1];
            } else {
                dp[j] = (dp[j].size() > dp[j - 1].size()) ? dp[j] : dp[j - 1];
            }
            if(dp[j].size() == 100) return dp[j];
            prev = temp;
        }
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    string a, b, ans;

        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        ans = LCS(a, b);

        int size = ans.size();
        if(size == 100)
        {
            ans = ans.substr(0, 50);
            cout << ans;
            reverse(ans.begin(), ans.end());
            cout << ans nl;
            return 0;
        }

        cout << ans nl;
}
