// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem12.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
const pair<int,string> valueSymbol[]={
    {1000,"M"},
    {900,"CM"},
    {500,"D"},
    {400,"CD"},
    {100,"C"},
    {90,"XC"},
    {50,"L"},
    {40,"XL"},
    {10,"X"},
    {9,"IX"},
    {5,"V"},
    {4,"IV"},
    {1,"I"}
};
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for(const auto &[value,symbol]:valueSymbol){
            while(num>=value){
                num-=value;
                roman+=symbol;
            }
            if(num==0) break;
        }
        return roman;
    }
};
// @lc code=end

