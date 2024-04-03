//https://codeforces.com/contest/1943/problem/B
//https://codeforces.com/contest/1943/submission/254236739

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
    int t;
    cin >> t;
    while(t--)
    {
        long long n, q, l, r, ans = 0, len;
        string s;
        cin >> n >> q >> s;

        auto v = manacher(s);
        for(auto &x : v) x--; //decrease the values of element in v to get true value of palindrom

        set <int> s1, s2;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1]) s1.insert(i);
            if (i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
        }

        while(q--)
        {
            cin >> l >> r;
            l--, r--;

            if (l == r)
            {
                cout << 0 << "\n";
                continue;
            }

            len = r - l + 1;

            auto it = s1.lower_bound(l);
            if (it == s1.end() || (*it) >= r)
            {
                ans = 0;
            }
            else
            {
                it = s2.lower_bound(l);
                if (it == s2.end() || (*it) >= r - 1)
                {
                    ans = ((len - 1)/ 2) * (((len - 1) / 2) + 1);
                }
                else
                {
                    ans =  (len * (len - 1)) / 2 - 1;
                }
            }

            if (v[l + r] < (r - l + 1)) ans += len;

            cout << ans << "\n";
        }

    }
}
