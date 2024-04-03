//https://cses.fi/problemset/task/1111
//https://cses.fi/problemset/result/8894183/

#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++)
    {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if(i + p[i] > r)
        {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s)
{
    string t;
    for(auto c: s)
    {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    string s, ans;
    cin >> s;

    auto v = manacher(s);
    for(auto &x : v) x--;

    int len = v.size(), Max = 0, p;
    for(int i = 0; i < len; i++)
    {
        if(Max < v[i])
        {
            p = i;
            Max = v[i];
        }
    }

    int start = p / 2 - (v[p] - 1) / 2;
    ans = s.substr(start, v[p]);

    cout << ans << "\n";
    return 0;
}
