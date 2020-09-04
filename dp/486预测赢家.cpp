class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int left =0, right = nums.size()-1;
        return select(left, right,0, 0, 0, nums);
     
    }

    bool select(int left, int right, int turn, int sumA, int sumB, vector<int>& nums) {
        if(left > right) {
            if(sumA >= sumB) {
                return true;
            } else {
                return false;
            }
        }

        int next = (turn + 1) %2;

        if(turn == 0) {
            // 玩家A
            return select(left+1, right, next, sumA+nums[left], sumB, nums) 
            || select(left, right-1, next, sumA+nums[right], sumB, nums);
        } else {
            return select(left+1, right, next, sumA, sumB+nums[left], nums)
            && select(left, right-1, next, sumA, sumB+nums[right], nums);
        }
    }
};