//https://www.spoj.com/problems/NUMOFPAL/
//https://www.spoj.com/status/NUMOFPAL,mushfiqur_1/

//There was some problem with server of SPOJ. I was submitting the same solution after 1st attempt
//at 15:48:39(UTC+2). Whenever submitting any solution solution it showed it was not submitted & problem
//with server...
//It showed the same error for the accepted two submission. But after sometime page showed my code is submitted
//The both ac code is same

//This is log for what happened (And, why there are two code? Is there any improvement in 2nd code? question answer)
//I may delete the log after this codes' evaluation by SSG sir
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
    string s;
    long long ans = 0;
    cin >> s;

    auto v = manacher(s);

    for(auto x : v)
    {
        ans += x/2;
    }

    cout << ans << "\n";
    return 0;
}
