/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> path(n),on_path(n);
        auto dfs = [&](this auto&& dfs,int i)->void{
            if(i == n){
                ans.emplace_back(path);
                return;
            }
            for(int j=0;j<n;j++){
                if(!on_path[j]){
                    path[i]=nums[j];
                    on_path[j]=1;
                    dfs(i+1);
                    on_path[j]=0;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

