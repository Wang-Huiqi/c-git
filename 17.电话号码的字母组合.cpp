/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    static constexpr string Mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        if (n == 0) return {};
        vector<string> ans;
        string path(n, 0);
        auto dfs = [&](this auto&& dfs, int i)->void{
            if (i == n){
                ans.emplace_back(path);
                return;
            }
            for (char c : Mapping[digits[i] - '0']) {
                path[i] = c;
                dfs(i+1);
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

