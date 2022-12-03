/*
https://leetcode.com/problems/max-area-of-island/
https://mp.weixin.qq.com/s/zJxRBWL4ok0tu2xXvNAjKA

这道题的主要思路是深度优先搜索。每次走到一个是 1 的格子，就搜索整个岛屿，并计算当前岛屿的面积。最后返回岛屿面积的最大值。

网格可以看成是一个无向图的结构，每个格子和它上下左右的四个格子相邻。如果四个相邻的格子坐标合法，且是陆地，就可以继续搜索。

在深度优先搜索的时候要注意避免重复遍历。我们可以把已经遍历过的陆地改成 2，这样遇到 2 我们就知道已经遍历过这个格子了，不进行重复遍历。

Time : O(m * n)
Space : O(m * n), the max depth of dfs may be m * n
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        auto result{0};
        
        for (auto i = 0; i < grid.size(); ++ i) {
            for (auto j = 0; j < grid.at(0).size(); ++ j) {
                if (grid.at(i).at(j) == 1) {
                    auto area = dfs(grid, i, j);
                    result = std::max(result, area);                    
                }                
            }
        }
        
        return result;
    }
    
private:
    int dfs(std::vector<std::vector<int> >& grid, int x, int y)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid.at(0).size()) {
            return 0;
        }
        
        if (grid.at(x).at(y) != 1) {
            return 0;
        }
        
        grid.at(x).at(y) = -1;
        
        auto area{1};
        for (const auto& d : m_directions) {
            area += dfs(grid, x + d.first, y + d.second);
        }  
        
        return area;               
    }
    
    const std::vector<std::pair<int, int> > m_directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
