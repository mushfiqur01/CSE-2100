//https://leetcode.com/problems/longest-palindrome/description/
//https://leetcode.com/problems/longest-palindrome/submissions/1220388884/

// Although it is not related to algorithm, I put it here because of its name.
// 1st I thought it would be related to the algorithm, so I created the cpp file here.
// After carefully reading I understood it is not related to the algorithm.

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);

        for(char c : s) count[c]++;

        int ans = 0;
        bool odd = false;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (count[i] % 2)
            {
                odd = true;
                ans += count[i] - 1;
            }
            else ans += count[i];
        }
        for (int i = 'a'; i <= 'z'; i++)
        {
            if (count[i] % 2)
            {
                odd = true;
                ans += count[i] - 1;
            }
            else ans += count[i];
        }

        return ans + odd;
    }
};
