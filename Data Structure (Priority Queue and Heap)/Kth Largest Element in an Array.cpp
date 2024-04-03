//https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> PQ(nums.begin(), nums.end());
        k--;
        while(k--) PQ.pop();

        return PQ.top();
    }
};
