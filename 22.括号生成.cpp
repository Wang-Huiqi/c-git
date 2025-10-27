/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(2*n,0);
        auto dfs = [&](this auto&& dfs,int left,int right)->void {
            if (right==n){
                ans.emplace_back(path);
                return;
            }
            if(left<n){
                path[left+right]='(';
                dfs(left+1,right);
            }
            if(right<left){
                path[left+right]=')';
                dfs(left,right+1);
            }
        };
        dfs(0,0);
        return ans;
    }
};
// @lc code=end

