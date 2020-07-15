/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        dfs(0, s, ip);

        return res;
    }

private:
    vector<string> res;
    void dfs(int index, string s, string ip) {
        int size = s.length();
        if(index == 4) {
            if(size == 0) {
                // 如果0.0.0.0
                res.push_back(ip);
            }
            return;
        }

        // 0 必须要单独一节，这一节最多有3个数
        for(int i=1; i <= min(3, s[0]=='0'?1:size); i++) {
            string ss = s.substr(0, i);
            if(stoi(ss) > 255) return;
            dfs(index+1, s.substr(i), ip+(index==0?"":".")+ss);
        }
    }
};
// @lc code=end

