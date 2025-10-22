// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem78.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&] (this auto&& dfs, int i)->void {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            dfs(i + 1);
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

