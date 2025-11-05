/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        auto dfs = [&](this auto&&dfs,int i,int c)->int {
            if(i<0){
                if(c==0) return 0;
                return INT_MAX/2;
            }
            if(memo[i][c]!=-1) return memo[i][c];
            if(c<coins[i]){
                return memo[i][c]=dfs(i-1,c);
            }
            return memo[i][c]=min(dfs(i-1,c),dfs(i,c-coins[i])+1);
        };
        int ans=dfs(n-1,amount);
        return (ans<INT_MAX/2)?ans:-1;
    }
};
// @lc code=end

