/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int ans = right;

        while(left < right) {
            int mid = left + ((right-left) >> 1);
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
                ans = mid;
            }
        }

        return ans;
    }
};
// @lc code=end

