//https://codeforces.com/contest/1326/problem/D2 <- I forgot submit the problem with this(problem) link
//https://codeforces.com/contest/1326/submission/254339457

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
        int p = 0, len, lenA, lenB;
        string s, prefix, a;
        cin >> s;

        len = s.size();
        while (p < len-1-p && s[p] == s[len-1-p]) p++;

        prefix = s.substr(0, p);
        s = s.substr(p, len - 2*p);

        if(s.size()>0)
        {
            auto v = manacher(s);
            for(auto &x : v) x--;

            len = v.size();
            for(int i = 0; i < len / 2 + 1; i++)
            {
                if(v[i] - 1 == i)
                {
                    lenA = i;
                }
            }
            for(int i = len / 2; i < len; i++)
            {
                if(len - v[i] == i)
                {
                    lenB = i;
                    break;
                }
            }

            if(v[lenA] < v[lenB])
            {
                int len = s.size();
                a = s.substr(len - v[lenB], len);
            }
            else
            {
                a = s.substr(0, lenA + 1);
            }
        }
        cout << prefix << a;
        reverse(prefix.begin(), prefix.end());
        cout << prefix << "\n";
    }
}
