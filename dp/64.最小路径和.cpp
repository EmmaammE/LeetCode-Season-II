/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        if(m == 0) return 0;
        n = grid[0].size();

        paths = vector<vector<int>>(m, vector<int>(n, 0));

        // m是第几行 n是第几列（x)
        return path(n-1,m-1, grid);
    }
private:
    int m, n;
    vector<vector<int>> paths;
    long path(int x, int y, vector<vector<int>> o) {
        if(x < 0 || y < 0) return INT_MAX;

        if(x == 0 && y == 0) return o[0][0];

        if(paths[y][x] > 0) return paths[y][x];

        int s = o[y][x] + min(path(x,y-1, o), path(x-1,y,o));

        return paths[y][x] = s;
    }
};
// @lc code=end

