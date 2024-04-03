//https://codeforces.com/problemset/problem/1132/E
//https://codeforces.com/contest/1132/submission/254754824

#include <bits/stdc++.h>
using namespace std;

long long cnt[9], W, ans;
void knapsack(int x, long long s)
{
    if (x == 0)
    {
        ans = max(s, ans);
        return ;
    }

    long long v = min(cnt[x],  (W - s) / x);

    for (long long i = 3; i > -1 && v > -1 ; i--)
    {
        knapsack(x - 1, s + (v--) * x);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    cin >> W;

    for(int i = 1; i < 9; i++)
    {
        cin >> cnt[i];
    }

    knapsack(8, 0);
    cout << ans << "\n";
}
