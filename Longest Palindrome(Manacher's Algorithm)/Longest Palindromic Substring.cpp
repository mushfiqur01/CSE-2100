//https://leetcode.com/problems/longest-palindromic-substring/description/
//https://leetcode.com/problems/longest-palindromic-substring/submissions/1220336487/

class Solution {
public:
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
    string longestPalindrome(string s) {
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
        s = s.substr(start, v[p]);

        return s;
    }
};
