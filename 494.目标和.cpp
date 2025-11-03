/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0, n = nums.size();
        for(int num:nums) total += num;
        if(target + total < 0|| (target + total) % 2 != 0) return 0;
        int sum_add = (target + total) / 2;
        auto dfs = [&](this auto&& dfs,int i, int c){
            if(i < 0){
                if(c == 0) return 1;
                return 0;
            }
            if(c < nums[i]) return dfs(i - 1, c);
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1,sum_add);
    }
};
// @lc code=end

