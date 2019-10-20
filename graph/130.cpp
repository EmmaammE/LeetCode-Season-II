/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
private:
    int c,r;
public:
    void solve(vector<vector<char>> &board)
    {
        if(board.size()==0)
            return;
        c = board[0].size();
        r = board.size();

        for (int i = 0; i < c; i++)
        {
            // 第一行和最后一行所有元素
            dfs(0,i,board);
            dfs(r-1,i,board);
        }

        for (int i = 0; i < r; i++)
        {
            // 第一列和最后一列所有的元素
            dfs(i,0,board);
            dfs(i,c-1,board);
        }
        
        for (int i = 0; i < r; i++)
        {
           for (int j = 0; j < c; j++)
           {
               if(board[i][j] == 'G') {
                   board[i][j] = 'O';
               } else if(board[i][j] == 'O') {
                   board[i][j] = 'X';
               }
           }
        }
    }

    void dfs(int x, int y,vector<vector<char>> &b)
    {
        if(x<0||x>=r||y<0||y>=c||b[x][y]!='O') return;
        b[x][y] = 'G';
        dfs(x-1,y,b);
        dfs(x+1,y,b);
        dfs(x,y-1,b);
        dfs(x,y+1,b);
    }
};
// @lc code=end