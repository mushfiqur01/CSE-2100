//https://atcoder.jp/contests/abc278/tasks/abc278_f

#include <bits/stdc++.h>
using namespace std;
#define nl << "\n"

int n, len[20];
string s[20];
bool flag[20];
map <string, bool> mp;

bool dfs(int u, int now, string str) //Now is the current player
{
    mp[str] = true;
    bool win = false;
    for (int i = 1; i <= n; i++)
    {
        if (u != 0 && s[i][0] != s[u][len[u] - 1]) continue;
        if (flag[i]) continue;
        if (mp[str + " " + s[i][0] + s[i][len[i] - 1]]) continue;

        flag[i] = true;

        win |= !(dfs (i, 3 - now, str + " " + s[i][0] + s[i][len[i] - 1]));

        flag[i] = false;

        if (win)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i], len[i] = s[i].size ();
    }

    if (dfs (0, 1, ""))
    {
        cout << "First" nl;
        return 0;
    }
    cout << "Second" nl;
    return 0;
}
