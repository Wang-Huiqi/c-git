/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
    bool isReSame(string &s, int left, int right) {
            while(left < right) {
                if(s[left++] != s[right--]) return false;
            }
            return true;
        }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.size();
        auto dfs = [&](this auto&& dfs, int start, int i)->void {
            if(i == n){
                ans.emplace_back(path);
                return;
            }
            if(i < n - 1) {
                dfs(start, i + 1);
            }
            if(isReSame(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end

