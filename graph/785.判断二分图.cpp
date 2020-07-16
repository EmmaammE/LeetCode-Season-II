/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<int> nodes(size);

        function<bool(int,int)> toColor = [&](int node, int color) -> bool {
            // 给这个点着色
            if(nodes[node]) {
                return nodes[node] == color;
            }
            nodes[node] = color;

            for (int adj : graph[node]) {
                // 给邻接点着色
                if(!toColor(adj, -color)) {
                    return false;
                }
            }

            return true;
        };

        for(int i=0; i<size; i++) {
            if(!nodes[i] && !toColor(i, 1)) {
                return false;
            }
        }
        return true;
    };
};
// @lc code=end

