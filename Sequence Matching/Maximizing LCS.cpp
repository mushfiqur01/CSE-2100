//https://www.codechef.com/START71A/problems/MAXLCS
#include<bits/stdc++.h>

using namespace std; //The problem is it can't be submit

#define nl << "\n"
int LCS(string X, string Y, int n, int m) //LUcS = Longest Common Subsequence
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + LCS(X, Y, m - 1, n - 1);
    else
        return max(LCS(X, Y, m, n - 1),
            LCS(X, Y, m - 1, n));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t, n, ans;
    string a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());

        ans = LCS(a, b, n, n);
        cout << ans / 2 nl;
    }
}
